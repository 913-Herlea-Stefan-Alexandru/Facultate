#include <QApplication>
//#include <QWidget>
//#include <QList>
#include <utility>
#include <QPainter>

#include "Service.h"
#include "UserRepository.h"
#include "IssueRepository.h"
#include "UserWindow.h"
#include "TableModel.h"

//class Item {
//public:
//    Item(QString name, int value) : name(std::move(name)), value(value) {}
//
//    QString name;
//    int value;
//};
//
//class Widget : public QWidget {
//public:
//    explicit Widget(QList<Item> elements, int limit) : elements(std::move(elements)), limit(limit) {}
//
//protected:
//    void paintEvent(QPaintEvent* event) override {
//        QPainter painter(this);
//        auto maxDiameter = std::min(this->width(), this->height());
//        painter.translate(this->width() / 2.0, this->height() / 2.0);
//        auto maxElement = *std::max_element(
//            this->elements.begin(),
//            this->elements.end(),
//            [](auto const& e1, auto const& e2) {
//                return e1.value < e2.value;
//            }
//        );
//        for (auto const& element : this->elements) {
//            auto diameter = element.value * maxDiameter / maxElement.value;
//            painter.setPen(element.value > this->limit ? Qt::blue : Qt::white);
//            painter.drawEllipse(-diameter / 2, -diameter / 2, diameter, diameter);
//            painter.drawText(-diameter / 2, 0, element.name);
//        }
//    }
//
//private:
//    QList<Item> elements;
//    int limit;
//};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    //Widget widget(QList<Item>() << Item("aaa", 1) << Item("bbb", 10) << Item("ccc", 3), 5);
    //widget.show();

    UserRepository u("Users.txt");
    IssueRepository i("Issues.txt");
    Service s(i);
    TableModel* tableModel = new TableModel(s);
    vector<UserWindow*> wins;

    for (int i = 0; i < u.size(); i++)
    {
        UserWindow* win = new UserWindow(u[i], s, tableModel);
        wins.push_back(win);
    }

    for (auto& win : wins)
    {
        win->show();
    }

    return a.exec();
}