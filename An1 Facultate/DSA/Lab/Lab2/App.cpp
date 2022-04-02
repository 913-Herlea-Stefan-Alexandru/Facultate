#include "ExtendedTest.h"
#include "ShortTest.h"

#include "FixedCapBiMap.h"


#include <iostream>
using namespace std;


int main() {
	testAll();
	testAllExtended();

	FixedCapBiMap m(5);

	m.add(4, 5);
	m.add(4, 6);
	m.add(6, 6);

	cout << m.size() << '\n';

	ValuePair res = m.removeKey(6);

	cout << m.size() << '\n';

	ValuePair r2 = m.removeKey(4);

	cout << m.size() << '\n';

	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


