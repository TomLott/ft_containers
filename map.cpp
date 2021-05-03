#include "map.hpp"
#include <string>
#include "utils.hpp"
#include <vector>
#include <list>
#include <stack>

bool singleDigit(const int& value) {
	return (value < 10);
}
struct isEven {
	bool operator()(const int& value) {
		return (value % 2) == 0;
	}
};
bool sameRemainderOfDivision(int first, int second) {
	if (first % 10 == second % 10)
		return true;
	return false;
}
bool myComparison (int first, int second) {
	return (first > second);
}

//MARK: - Utilst list

template <typename T>
void listPushBackElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push_back(i);
		ft.push_back(i);
	}
}

template <typename T>
void listPushFrontElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push_front(i);
		ft.push_front(i);
	}
}

template <typename T>
void listPopFrontElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.pop_front();
		ft.pop_front();
	}
}

template <typename T>
void listPopBackElem(std::list<T> &std, ft::list<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.pop_back();
		ft.pop_back();
	}
}


template <typename T>
void VectorPushBackElem(std::vector<T> &std, ft::vector<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand() % 100;
		std.push_back(i);
		ft.push_back(i);
	}
}

template <typename T>
void VectorPopBackElem(std::vector<T> &std, ft::vector<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.pop_back();
		ft.pop_back();
	}
}

template <typename T>
void VectorFillStr(std::vector<T> &def, ft::vector<T> &my, std::string &std, std::string &ft) {
	for (typename std::vector<T>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (typename ft::vector<T>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
}

//MARK: - Utilst map

template <typename Key, typename T>
void mapInsertElem(std::map<Key,T> &std, ft::map<Key,T> &ft, unsigned long number) {
	Key i;
	T j;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		j = rand();
		std::pair<Key, T> res(i, j);
		std.insert(res);
		ft.insert(res);
	}
}

template <typename Key, typename T>
void mapFillStr(std::map<Key,T> &def, ft::map<Key,T> &my, std::string &std, std::string &ft) {
	for (typename std::map<Key,T>::iterator it = def.begin(); it != def.end(); it++) {
		std += it->first;
		std += it->second;
	}
	for (typename ft::map<Key,T>::iterator it = my.begin(); it != my.end(); it++) {
		ft += it->first;
		ft += it->second;
	}
	std += def.size();
	ft += my.size();
}

//MARK: - Default constructor map

void defaultCnstTestMap(std::string &std, std::string &ft) {
	std::cout << "Default constructor int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}
void defaultCnstTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Default constructor float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Default constructor std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Range constructor map

void rangeCnstTestMap(std::string &std, std::string &ft) {
	std::cout << "Range constructor int test" << " ";
	std::map<int, int> test;
	for (int i = 0; i < 100; i++) {
		std::pair<int, int> res(rand(), rand());
		test.insert(res);
	}
	std::map<int, int> def(++test.begin(), --test.end());
	ft::map<int, int> my(++test.begin(), --test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Range constructor float test" << " ";
	std::map<float, float> test;
	for (int i = 0; i < 100; i++) {
		std::pair<float, float> res(rand(), rand());
		test.insert(res);
	}
	std::map<float, float> def(++test.begin(), --test.end());
	ft::map<float, float> my(++test.begin(), --test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Range constructor std::string test" << " ";
	std::map<std::string, std::string> test;
	std::string key;
	std::string value;
	for (int i = 0; i < 100; i++) {
		key += rand();
		value += rand();
		std::pair<std::string, std::string> res(key, value);
		test.insert(res);
	}
	std::map<std::string, std::string> def(++test.begin(), --test.end());
	ft::map<std::string, std::string> my(++test.begin(), --test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Copy constructor map

void copyCnstTestMap(std::string &std, std::string &ft) {
	std::cout << "Copy constructor int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Copy constructor float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Copy constructor std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Assignation map

void assignTestMap(std::string &std, std::string &ft) {
	std::cout << "Assignation int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std::map<int, int> test;
	ft::map<int, int> myTest;
	mapInsertElem(test, myTest, 100);
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	def = test;
	my = myTest;
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Assignation float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std::map<float, float> test;
	ft::map<float, float> myTest;
	mapInsertElem(test, myTest, 100);
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	def = test;
	my = myTest;
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Assignation std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std::map<std::string, std::string> test;
	ft::map<std::string, std::string> myTest;
	mapInsertElem(test, myTest, 100);
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	def = test;
	my = myTest;
	mapFillStr(def, my, std, ft);
	mapFillStr(test, myTest, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Iterator map

void iteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::iterator it = testStd.begin();
	std::map<int,int>::iterator ite = testStd.end();
	ft::map<int,int>::iterator itm = testFt.begin();
	ft::map<int,int>::iterator item = testFt.end();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.begin();
	itm = testFt.begin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const iteratot map

void constIteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All const_iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::const_iterator it = testStd.cbegin();
	std::map<int,int>::const_iterator ite = testStd.cend();
	ft::map<int,int>::const_iterator itm = testFt.begin();
	ft::map<int,int>::const_iterator item = testFt.end();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.cbegin();
	itm = testFt.begin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reverse iteratot map

void reverseIteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All reverse_iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::reverse_iterator it = testStd.rbegin();
	std::map<int,int>::reverse_iterator ite = testStd.rend();
	ft::map<int,int>::reverse_iterator itm = testFt.rbegin();
	ft::map<int,int>::reverse_iterator item = testFt.rend();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.rbegin();
	itm = testFt.rbegin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const reverse iteratot map

void constReverseIteratorTestMap(std::string &std, std::string &ft, int number) {
	std::map<int,int> testStd;
	ft::map<int,int> testFt;
	std::cout << "All const_reverse_iterator test" << " ";
	for (int i = 0; i < number; i++) {
		std::pair<int, int> res(rand(), rand());
		testStd.insert(res);
		testFt.insert(res);
	}
	std::map<int,int>::const_reverse_iterator it = testStd.crbegin();
	std::map<int,int>::const_reverse_iterator ite = testStd.crend();
	ft::map<int,int>::const_reverse_iterator itm = testFt.rbegin();
	ft::map<int,int>::const_reverse_iterator item = testFt.rend();
	while (it != ite) {
		std += it->first;
		std += it->second;
		it++;
	}
	while (itm != item) {
		ft += itm->first;
		ft += itm->second;
		itm++;
	}
	it = testStd.rbegin();
	itm = testFt.rbegin();
	while (ite != it) {
		ite--;
		std += ite->first;
		std += ite->second;
	}
	while (item != itm) {
		item--;
		ft += item->first;
		ft += item->second;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty map

void emptyMapTest(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std += def.empty();
	ft += my.empty();
	mapInsertElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std += def.empty();
	ft += my.empty();
	mapInsertElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std += def.empty();
	ft += my.empty();
	mapInsertElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size map

void sizeMapTest(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std += def.size();
	ft += my.size();
	mapInsertElem(def, my, 10);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std += def.size();
	ft += my.size();
	mapInsertElem(def, my, 10);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std += def.size();
	ft += my.size();
	mapInsertElem(def, my, 10);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Max size map

void maxSizeTestMap(std::string &std, std::string &ft) {
	std::cout << "Max size int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void maxSizeTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Max size float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Operator [] map

void squareBracketsTestMap(std::string &std, std::string &ft) {
	std::cout << "Opetator[] int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(21, 42);
	def.insert(test);
	my.insert(test);
	std += def[21];
	ft += my[21];
	std += def[42];
	ft += my[42];
	std += def[42];
	ft += my[42];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Opetator[] float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(21, 42);
	def.insert(test);
	my.insert(test);
	std += def[21];
	ft += my[21];
	std += def[42];
	ft += my[42];
	std += def[42];
	ft += my[42];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Opetator[] std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("21", "42");
	def.insert(test);
	my.insert(test);
	std += def["21"];
	ft += my["21"];
	std += def["42"];
	ft += my["42"];
	std += def["42"];
	ft += my["42"];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Insert map

void singleInsertMap(std::string &std, std::string &ft) {
	std::cout << "Single insert int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapFillStr(def, my, std, ft);
	std::pair<int, int> test(42, 21);
	def.insert(test);
	my.insert(test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertMapFloat(std::string &std, std::string &ft) {
	std::cout << "Single insert float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapFillStr(def, my, std, ft);
	std::pair<float, float> test(42.21, 21.42);
	def.insert(test);
	my.insert(test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertMapStr(std::string &std, std::string &ft) {
	std::cout << "Single insert std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapFillStr(def, my, std, ft);
	std::pair<std::string, std::string> test("42", "21");
	def.insert(test);
	my.insert(test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void withHitInsertMap(std::string &std, std::string &ft) {
	std::cout << "With hit insert int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapFillStr(def, my, std, ft);
	std::pair<int, int> test(42, 21);
	def.insert(def.begin(),test);
	my.insert(my.begin(), test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void withHitInsertMapFloat(std::string &std, std::string &ft) {
	std::cout << "With hit insert float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapFillStr(def, my, std, ft);
	std::pair<float, float> test(42.21, 21.42);
	def.insert(def.begin(),test);
	my.insert(my.begin(), test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void withHitInsertMapStr(std::string &std, std::string &ft) {
	std::cout << "With hit insert std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapFillStr(def, my, std, ft);
	std::pair<std::string, std::string> test("42", "21");
	def.insert(def.begin(),test);
	my.insert(my.begin(), test);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertMapTest(std::string &std, std::string &ft) {
	std::cout << "Range insert int test" << " ";
	std::map<int, int> test;
	for (int i = 0; i < 100; i++) {
		std::pair<int, int> l(rand(), rand());
		test.insert(l);
	}
	std::map<int, int> def;
	ft::map<int, int> my;
	def.insert(test.begin(), test.end());
	my.insert(test.begin(), test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range insert float test" << " ";
	std::map<float, float> test;
	for (int i = 0; i < 100; i++) {
		std::pair<float, float> l(rand(), rand());
		test.insert(l);
	}
	std::map<float, float> def;
	ft::map<float, float> my;
	def.insert(test.begin(), test.end());
	my.insert(test.begin(), test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Range insert std::string test" << " ";
	std::map<std::string, std::string> test;
	for (int i = 0; i < 100; i++) {
		std::string l1;
		std::string l2;
		l1 += rand();
		l2 += rand();
		std::pair<std::string, std::string> l(l1, l2);
		test.insert(l);
	}
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	def.insert(test.begin(), test.end());
	my.insert(test.begin(), test.end());
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Erase map

void eraseSingleMapTest(std::string &std, std::string &ft) {
	std::cout << "Single erase int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	std::map<int, int>::iterator it = def.begin();
	ft::map<int, int>::iterator mit = my.begin();
	for (int i = 0; i < 10; i++) {
		it++;
		mit++;
	}
	for (int i = 0; i < 40; i++) {
		std::map<int, int>::iterator tmp = it;
		ft::map<int, int>::iterator mtmp = mit;
		it++;
		mit++;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	it = def.end();
	mit = my.end();
	it--;
	mit--;
	for (int i = 0; i < 20; i++) {
		std::map<int, int>::iterator tmp = it;
		ft::map<int, int>::iterator mtmp = mit;
		it--;
		mit--;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseSingleMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Single erase float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	std::map<float, float>::iterator it = def.begin();
	ft::map<float, float>::iterator mit = my.begin();
	for (int i = 0; i < 10; i++) {
		it++;
		mit++;
	}
	for (int i = 0; i < 40; i++) {
		std::map<float, float>::iterator tmp = it;
		ft::map<float, float>::iterator mtmp = mit;
		it++;
		mit++;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	it = def.end();
	mit = my.end();
	it--;
	mit--;
	for (int i = 0; i < 20; i++) {
		std::map<float, float>::iterator tmp = it;
		ft::map<float, float>::iterator mtmp = mit;
		it--;
		mit--;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseSingleMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Single erase std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	std::map<std::string, std::string>::iterator it = def.begin();
	ft::map<std::string, std::string>::iterator mit = my.begin();
	for (int i = 0; i < 10; i++) {
		it++;
		mit++;
	}
	for (int i = 0; i < 40; i++) {
		std::map<std::string, std::string>::iterator tmp = it;
		ft::map<std::string, std::string>::iterator mtmp = mit;
		it++;
		mit++;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	it = def.end();
	mit = my.end();
	it--;
	mit--;
	for (int i = 0; i < 20; i++) {
		std::map<std::string, std::string>::iterator tmp = it;
		ft::map<std::string, std::string>::iterator mtmp = mit;
		it--;
		mit--;
		def.erase(tmp);
		my.erase(mtmp);
		mapFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseKeyMapTest(std::string &std, std::string &ft) {
	std::cout << "Key erase int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	def.erase(42);
	my.erase(42);
	def.erase(1);
	my.erase(1);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseKeyMapTestFloat(std::string &std, std::string &ft) {
	std::cout << "Key erase float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	def.erase(42.21);
	my.erase(42.21);
	def.erase(1.7);
	my.erase(1.7);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseKeyMapTestStr(std::string &std, std::string &ft) {
	std::cout << "Key erase std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	def.erase("42");
	my.erase("42");
	def.erase("1");
	my.erase("1");
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseRangeTest(std::string &std, std::string &ft) {
	std::cout << "Range erase int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::map<int, int>::iterator it = def.begin();
	std::map<int, int>::iterator ite = def.end();
	ft::map<int, int>::iterator itm = my.begin();
	ft::map<int, int>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		++it;
		++itm;
		--ite;
		--item;
	}
	def.erase(it, ite);
	my.erase(itm, item);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseRangeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range erase float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::map<float, float>::iterator it = def.begin();
	std::map<float, float>::iterator ite = def.end();
	ft::map<float, float>::iterator itm = my.begin();
	ft::map<float, float>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		++it;
		++itm;
		--ite;
		--item;
	}
	def.erase(it, ite);
	my.erase(itm, item);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseRangeTestStr(std::string &std, std::string &ft) {
	std::cout << "Range erase std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::map<std::string, std::string>::iterator it = def.begin();
	std::map<std::string, std::string>::iterator ite = def.end();
	ft::map<std::string, std::string>::iterator itm = my.begin();
	ft::map<std::string, std::string>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		++it;
		++itm;
		--ite;
		--item;
	}
	def.erase(it, ite);
	my.erase(itm, item);
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
//	std.clear();
//	ft.clear();
}

//MARK: - Swap map

void swapTestMap(std::string &std, std::string &ft) {
	std::cout << "Swap int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std::map<int, int> toSwap;
	ft::map<int, int> mySwap;
	mapInsertElem(def, my, 100);
	mapInsertElem(toSwap, mySwap, 50);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Swap float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std::map<float, float> toSwap;
	ft::map<float, float> mySwap;
	mapInsertElem(def, my, 100);
	mapInsertElem(toSwap, mySwap, 50);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Swap std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std::map<std::string, std::string> toSwap;
	ft::map<std::string, std::string> mySwap;
	mapInsertElem(def, my, 100);
	mapInsertElem(toSwap, mySwap, 50);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	mapFillStr(def, my, std, ft);
	mapFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Clear map

void clearTestMap(std::string &std, std::string &ft) {
	std::cout << "Clear int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearTestMapFloat(std::string &std, std::string &ft) {
	std::cout << "Clear float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearTestMapStr(std::string &std, std::string &ft) {
	std::cout << "Clear std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	mapFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	mapFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Key compare map

void keyCompareTest(std::string &std, std::string &ft) {
	std::cout << "Key comp int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	std::map<int,int>::key_compare comp = def.key_comp();
	ft::map<int,int>::key_compare myComp = my.key_comp();
	int i = 10000;
	mapInsertElem(def, my, 100);
	for (std::map<int, int>::iterator it = def.begin(); it != def.end(); ++it) {
		std += comp(i, it->first);
		ft += myComp(i, it->first);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void keyCompareTestFloat(std::string &std, std::string &ft) {
	std::cout << "Key comp float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	std::map<float,float>::key_compare comp = def.key_comp();
	ft::map<float,float>::key_compare myComp = my.key_comp();
	float i = 10000.42;
	mapInsertElem(def, my, 100);
	for (std::map<float, float>::iterator it = def.begin(); it != def.end(); ++it) {
		std += comp(i, it->first);
		ft += myComp(i, it->first);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void keyCompareTestStr(std::string &std, std::string &ft) {
	std::cout << "Key comp std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	std::map<std::string,std::string>::key_compare comp = def.key_comp();
	ft::map<std::string,std::string>::key_compare myComp = my.key_comp();
	std::string i = "10000";
	mapInsertElem(def, my, 100);
	for (std::map<std::string, std::string>::iterator it = def.begin(); it != def.end(); ++it) {
		std += comp(i, it->first);
		ft += myComp(i, it->first);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Value compare map

void valueCompareTest(std::string &std, std::string &ft) {
	std::cout << "Value comp int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> res(100,100);
	for (std::map<int, int>::iterator it = def.begin(); it != def.end(); ++it) {
		std += def.value_comp()(res, *it);
		ft += my.value_comp()(res, *it);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void valueCompareTestFloat(std::string &std, std::string &ft) {
	std::cout << "Value comp float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> res(100.42,100.42);
	for (std::map<float, float>::iterator it = def.begin(); it != def.end(); ++it) {
		std += def.value_comp()(res, *it);
		ft += my.value_comp()(res, *it);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void valueCompareTestStr(std::string &std, std::string &ft) {
	std::cout << "Value comp std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> res("100","100");
	for (std::map<std::string, std::string>::iterator it = def.begin(); it != def.end(); ++it) {
		std += def.value_comp()(res, *it);
		ft += my.value_comp()(res, *it);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Find map

void findTest(std::string &std, std::string &ft) {
	std::cout << "Find int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	std::map<int, int>::iterator it;
	ft::map<int, int>::iterator ite;
	it = def.find(42);
	ite = my.find(42);
	std += it->first;
	std += it->second;
	ft += ite->first;
	ft += ite->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void findTestFloat(std::string &std, std::string &ft) {
	std::cout << "Find float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	std::map<float, float>::iterator it;
	ft::map<float, float>::iterator ite;
	it = def.find(42.21);
	ite = my.find(42.21);
	std += it->first;
	std += it->second;
	ft += ite->first;
	ft += ite->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void findTestStr(std::string &std, std::string &ft) {
	std::cout << "Find std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	std::map<std::string, std::string>::iterator it;
	ft::map<std::string, std::string>::iterator ite;
	it = def.find("42");
	ite = my.find("42");
	std += it->first;
	std += it->second;
	ft += ite->first;
	ft += ite->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Count map

void countTest(std::string &std, std::string &ft) {
	std::cout << "Count int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	std::pair<int, int> test1(21, 21);
	def.insert(test);
	my.insert(test);
	def.insert(test);
	my.insert(test);
	std += def.count(42);
	ft += my.count(42);
	std += def.count(21);
	ft += my.count(21);
	std += def.count(72);
	ft += my.count(72);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void countTestFloat(std::string &std, std::string &ft) {
	std::cout << "Count float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	std::pair<float, float> test1(21.42, 21.42);
	def.insert(test);
	my.insert(test);
	def.insert(test);
	my.insert(test);
	std += def.count(42.21);
	ft += my.count(42.21);
	std += def.count(21.42);
	ft += my.count(21.42);
	std += def.count(72.1);
	ft += my.count(72.1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void countTestStr(std::string &std, std::string &ft) {
	std::cout << "Count std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	std::pair<std::string, std::string> test1("21", "21");
	def.insert(test);
	my.insert(test);
	def.insert(test);
	my.insert(test);
	std += def.count("42");
	ft += my.count("42");
	std += def.count("21");
	ft += my.count("21");
	std += def.count("72");
	ft += my.count("72");
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Lover bound map

void lowerBoundTest(std::string &std, std::string &ft) {
	std::cout << "Lower bound int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	std::map<int, int>::iterator it;
	ft::map<int, int>::iterator itm;
	it = def.lower_bound(42);
	itm = my.lower_bound(42);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(43);
	itm = my.lower_bound(43);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(-9999999);
	itm = my.lower_bound(-9999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(999999999);
	itm = my.lower_bound(999999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lowerBoundTestFloat(std::string &std, std::string &ft) {
	std::cout << "Lower bound float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	std::map<float, float>::iterator it;
	ft::map<float, float>::iterator itm;
	it = def.lower_bound(42.21);
	itm = my.lower_bound(42.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(43.21);
	itm = my.lower_bound(43.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(-9999999.0);
	itm = my.lower_bound(-9999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound(999999999.0);
	itm = my.lower_bound(999999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lowerBoundTestStr(std::string &std, std::string &ft) {
	std::cout << "Lower bound std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	std::map<std::string, std::string>::iterator it;
	ft::map<std::string, std::string>::iterator itm;
	it = def.lower_bound("42");
	itm = my.lower_bound("42");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound("43");
	itm = my.lower_bound("43");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound("a");
	itm = my.lower_bound("a");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.lower_bound("zzzzzzzzzzzzzzz");
	itm = my.lower_bound("zzzzzzzzzzzzzzz");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Upper bound map

void upperBoundTest(std::string &std, std::string &ft) {
	std::cout << "Upper bound int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<int, int> test(42, 42);
	def.insert(test);
	my.insert(test);
	std::map<int, int>::iterator it;
	ft::map<int, int>::iterator itm;
	it = def.upper_bound(42);
	itm = my.upper_bound(42);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(43);
	itm = my.upper_bound(43);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(-9999999);
	itm = my.upper_bound(-9999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(999999999);
	itm = my.upper_bound(999999999);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void upperBoundTestFloat(std::string &std, std::string &ft) {
	std::cout << "Upper bound float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<float, float> test(42.21, 42.21);
	def.insert(test);
	my.insert(test);
	std::map<float, float>::iterator it;
	ft::map<float, float>::iterator itm;
	it = def.upper_bound(42.21);
	itm = my.upper_bound(42.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(43.21);
	itm = my.upper_bound(43.21);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(-9999999.0);
	itm = my.upper_bound(-9999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound(999999999.0);
	itm = my.upper_bound(999999999.0);
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void upperBoundTestStr(std::string &std, std::string &ft) {
	std::cout << "Upper bound std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::string, std::string> test("42", "42");
	def.insert(test);
	my.insert(test);
	std::map<std::string, std::string>::iterator it;
	ft::map<std::string, std::string>::iterator itm;
	it = def.upper_bound("42");
	itm = my.upper_bound("42");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound("43");
	itm = my.upper_bound("43");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound("a");
	itm = my.upper_bound("a");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	it = def.upper_bound("zzzzzzzzzzzzzzz");
	itm = my.upper_bound("zzzzzzzzzzzzzzz");
	std += it->first;
	ft += itm->first;
	std += it->second;
	ft += itm->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Equal range map

void equalRangeTest(std::string &std, std::string &ft) {
	std::cout << "Equal range int test" << " ";
	std::map<int, int> def;
	ft::map<int, int> my;
	mapInsertElem(def, my, 100);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> test;
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> myTest;
	test = def.equal_range(100);
	myTest = my.equal_range(100);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	std::pair<int, int> toTest(42, 42);
	def.insert(toTest);
	my.insert(toTest);
	test = def.equal_range(42);
	myTest = my.equal_range(42);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalRangeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Equal range float test" << " ";
	std::map<float, float> def;
	ft::map<float, float> my;
	mapInsertElem(def, my, 100);
	std::pair<std::map<float, float>::iterator, std::map<float, float>::iterator> test;
	std::pair<ft::map<float, float>::iterator, ft::map<float, float>::iterator> myTest;
	test = def.equal_range(100);
	myTest = my.equal_range(100);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	std::pair<float, float> toTest(42.21, 42.21);
	def.insert(toTest);
	my.insert(toTest);
	test = def.equal_range(42.21);
	myTest = my.equal_range(42.21);
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalRangeTestStr(std::string &std, std::string &ft) {
	std::cout << "Equal range std::string test" << " ";
	std::map<std::string, std::string> def;
	ft::map<std::string, std::string> my;
	mapInsertElem(def, my, 100);
	std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> test;
	std::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> myTest;
	test = def.equal_range("100");
	myTest = my.equal_range("100");
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	std::pair<std::string, std::string> toTest("42", "42");
	def.insert(toTest);
	my.insert(toTest);
	test = def.equal_range("42");
	myTest = my.equal_range("42");
	std += test.first->first;
	std += test.first->second;
	std += test.second->first;
	std += test.second->second;
	ft += myTest.first->first;
	ft += myTest.first->second;
	ft += myTest.second->first;
	ft += myTest.second->second;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Map

void testMap() {
	std::cout << "                            CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestMap(std, ft);
	defaultCnstTestMapFloat(std, ft);
	defaultCnstTestMapStr(std, ft);
	rangeCnstTestMap(std, ft);
	rangeCnstTestMapFloat(std, ft);
	rangeCnstTestMapStr(std, ft);
	copyCnstTestMap(std, ft);
	copyCnstTestMapFloat(std, ft);
	copyCnstTestMapStr(std, ft);
	std::cout << "                            ASSIGNATION" << std::endl;
	assignTestMap(std, ft);
	assignTestMapFloat(std, ft);
	assignTestMapStr(std, ft);
	std::cout << "                            ITERATORS" << std::endl;
	iteratorTestMap(std, ft, 1000);
	constIteratorTestMap(std, ft, 1000);
	reverseIteratorTestMap(std, ft, 1000);
	constReverseIteratorTestMap(std, ft, 1000);
	std::cout << "                            CAPACITY" << std::endl;
	emptyMapTest(std, ft);
	emptyMapTestFloat(std, ft);
	emptyMapTestStr(std, ft);
	sizeMapTest(std, ft);
	sizeMapTestFloat(std, ft);
	sizeMapTestStr(std, ft);
	maxSizeTestMap(std, ft);
	maxSizeTestMapFloat(std, ft);
	std::cout << "                            ELEMENT ACCESS" << std::endl;
	squareBracketsTestMap(std, ft);
	squareBracketsTestMapFloat(std, ft);
	squareBracketsTestMapStr(std, ft);
	std::cout << "                            MODIFIERS" << std::endl;
	singleInsertMap(std, ft);
	singleInsertMapFloat(std, ft);
	singleInsertMapStr(std, ft);
	withHitInsertMap(std, ft);
	withHitInsertMapFloat(std, ft);
	withHitInsertMapStr(std, ft);
	rangeInsertMapTest(std, ft);
	rangeInsertMapTestFloat(std, ft);
	rangeInsertMapTestStr(std, ft);
	eraseSingleMapTest(std, ft);
	eraseSingleMapTestFloat(std, ft);
	eraseSingleMapTestStr(std, ft);
	eraseKeyMapTest(std, ft);
	eraseKeyMapTestFloat(std, ft);
	eraseKeyMapTestStr(std, ft);
	swapTestMap(std, ft);
	swapTestMapFloat(std, ft);
	swapTestMapStr(std, ft);
	clearTestMap(std, ft);
	clearTestMapFloat(std, ft);
	clearTestMapStr(std, ft);
	std::cout << "                            OBSERVERS" << std::endl;
	keyCompareTest(std, ft);
	keyCompareTestFloat(std, ft);
	keyCompareTestStr(std, ft);
	valueCompareTest(std, ft);
	valueCompareTestFloat(std, ft);
	valueCompareTestStr(std, ft);
	std::cout << "                            OPERATIONS" << std::endl;
	findTest(std, ft);
	findTestFloat(std, ft);
	findTestStr(std, ft);
	countTest(std, ft);
	countTestFloat(std, ft);
	countTestStr(std, ft);
	lowerBoundTest(std, ft);
	lowerBoundTestFloat(std, ft);
	lowerBoundTestStr(std, ft);
	upperBoundTest(std, ft);
	upperBoundTestFloat(std, ft);
	upperBoundTestStr(std, ft);
	equalRangeTest(std, ft);
	equalRangeTestFloat(std, ft);
	equalRangeTestStr(std, ft);
}

int main(){
	testMap();
	return 0;
}