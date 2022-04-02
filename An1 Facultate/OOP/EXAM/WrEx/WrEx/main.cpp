#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <exception>

using namespace std;

class HTMLElement
{
protected:

	string text;

public:

	HTMLElement(string text) : text{ text }
	{

	}

	virtual string getHTMLString()
	{
		return this->text;
	}

};

class HTMLParagraph : public HTMLElement
{
public:

	HTMLParagraph(string text) : HTMLElement(text)
	{

	}

	string getHTMLString() override
	{
		return "<p>" + this->text + "</p>";
	}
};

class HTMLImage : public HTMLElement
{
public:

	HTMLImage(string text) : HTMLElement(text)
	{

	}

	string getHTMLString() override
	{
		return "<img>" + this->text + "</img>";
	}
};

template <class T>
class HTMLBuilder
{
private:

	vector<T> list;

public:

	HTMLBuilder& operator+=(T elem)
	{
		if (elem == nullptr)
			throw runtime_error("Cannot add a null element!");
		this->list.push_back(elem);
		return *this;
	}

	friend ostream& operator<<(ostream& out, HTMLBuilder& build)
	{
		out << "<html><body>";
		for (auto& elem : build.list)
		{
			if (elem != nullptr)
				out << elem->getHTMLString();
		}
		out << "</html></body>" << '\n';
		return out;
	}
};

void fct1() {
	HTMLElement* p1 = new HTMLParagraph{ "Examination" };
	assert(p1->getHTMLString() == "<p>Examination</p>");
	HTMLElement* p2 = nullptr;
	HTMLElement* i1 = new HTMLImage{ "a.jpg" };
	HTMLElement* i2 = new HTMLImage{ "b.jpg" };
	assert(i2->getHTMLString() == "<img>b.jpg</img>");
	HTMLBuilder<HTMLElement*> html{};
	try {
		html += p2;
		assert(false);
	}
	catch (runtime_error& e) {
		assert(strcmp(e.what(), "Cannot add a null element!") == 0);
	}
	//html = html + p1;
	//html = html + i1;
	//html = html + i1;
	((html += p1) += i1) += i2;
	cout << html; // prints: <html><body><p>Examination</p><img>a.jpg</img><img>b.jpg</img></html></body>
	delete p1; delete p2;
	delete i1; delete i2;
}

template <class Y>
Y fct(vector<Y> vec)
{
	/*
	* This functions computes the sum of the elements inside the vector / concatenates them
	* param vec: vector<Y> a vector of elements of type Y (Y being a class/type from the template)
	* returns: the sum / concatenation of the elements
	* throws: exception if the vector is empty
	*/
	if (vec.size() == 0)
		throw exception();
	Y sum = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		sum += vec[i];
	}
	return sum;
}

void testFct() {
	vector<int> v1{ 4, 2, 1, -4 };
	assert(fct<int>(v1) == 3);
	vector<int> v2;
	try {
		fct<int>(v2);
		assert(false);
	}
	catch (std::exception&) { assert(true); }

	vector<double> v3{ 2, 10.5, 5, -10 };
	assert(fct<double>(v3) == 7.5);

	vector<string> v4{ "y", "q", "a", "m" };
	assert(fct<string>(v4) == "yqam");
}

class Action
{
public:

	virtual void execute() = 0;
};

class CreateAction : public Action
{
public:

	void execute() override
	{
		cout << "Create file\n";
	}
};

class ExitAction : public Action
{
public:

	void execute() override
	{
		cout << "Exit application\n";
	}
};

class MenuItem
{
private:

	string text;
	Action* act;

public:

	MenuItem(string text, Action* act = nullptr) : text{ text }, act { act }
	{

	}

	virtual void print()
	{
		cout << this->text << '\n';
	}

	virtual void clicked()
	{
		cout << this->text << '\n';
		if (this->act != nullptr)
			this->act->execute();
	}

};

class Menu : public MenuItem
{
private:

	vector<MenuItem*> items;

public:

	Menu(string text, Action* act = nullptr) : MenuItem(text, act)
	{
		
	}

	void add(MenuItem* item)
	{
		this->items.push_back(item);
	}

	void print() override
	{
		MenuItem::print();
		for (auto& m : this->items)
		{
			m->print();
		}
	}

};

class MenuBar
{
private:

	vector<Menu*> menus;

public:

	void add(Menu* men)
	{
		this->menus.push_back(men);
	}

	void print()
	{
		for (auto& m : this->menus)
		{
			m->print();
		}
	}
};

int main()
{
	fct1();
	//testFct();

	//MenuBar menB;

	//Menu* file = new Menu("File");
	//Menu* about = new Menu("About");

	//Menu* nw = new Menu("New");
	//ExitAction* ex = new ExitAction();
	//Menu* exit = new Menu("Exit", ex);

	//CreateAction* createTxt = new CreateAction();
	//Menu* text = new Menu("Text", createTxt);
	//CreateAction* createCpp = new CreateAction();
	//Menu* cpp = new Menu("CPP", createCpp);

	//nw->add(text);
	//nw->add(cpp);

	//file->add(nw);
	//file->add(exit);

	//menB.add(file);
	//menB.add(about);

	//file->clicked();
	//nw->clicked();
	//cpp->clicked();

	return 0;
}