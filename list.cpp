#include "list.hpp"
#include <list>
#include <iostream>

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


void defaultCnstTest(std::string &std, std::string &ft) {
	std::cout << "Default int constructor test" << " ";
	std::list<int> intStd;
	ft::list<int> intFt;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Default std::string constructor test" << " ";
	std::list<std::string> stringStd;
	ft::list<std::string> stringFt;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Default float constructor test" << " ";
	std::list<float> floatStd;
	ft::list<float> floatFt;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillCnstTest(std::string &std, std::string &ft, int number) {
	std::cout << "Fill int constructor test" << " ";
	int i = rand();
	std::list<int> intStd(number, i);
	ft::list<int> intFt(number, i);
	for (std::list<int>::iterator it = intStd.begin(); it != intStd.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = intFt.begin(); it != intFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Fill std::string constructor test" << " ";
	std::string j;
	j += rand();
	std::list<std::string> stringStd(number, j);
	ft::list<std::string> stringFt(number, j);
	for (std::list<std::string>::iterator it = stringStd.begin(); it != stringStd.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = stringFt.begin(); it != stringFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Fill float constructor test" << " ";
	float k = rand();
	std::list<float> floatStd(number, k);
	ft::list<float> floatFt(number, k);
	for (std::list<float>::iterator it = floatStd.begin(); it != floatStd.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = floatFt.begin(); it != floatFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTest(std::string &std, std::string &ft, int number) {
	std::cout << "Range int constructor test" << " ";
	std::list<int> testInt;
	for (int l = 0; l < number; l++) {
		int i = rand();
		testInt.push_back(i);
	}
	std::list<int> intStd(testInt.begin(), testInt.end());
	ft::list<int> intFt(testInt.begin(), testInt.end());
	for (std::list<int>::iterator it = intStd.begin(); it != intStd.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = intFt.begin(); it != intFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Range std::string constructor test" << " ";
	std::list<std::string> testString;
	for (int l = 0; l < number; l++) {
		std::string j;
		j += rand();
		testString.push_back(j);
	}
	std::list<std::string> stringStd(testString.begin(), testString.end());
	ft::list<std::string> stringFt(testString.begin(), testString.end());
	for (std::list<std::string>::iterator it = stringStd.begin(); it != stringStd.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = stringFt.begin(); it != stringFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Range float constructor test" << " ";

	std::list<float> testFloat;
	for (int l = 0; l < number; l++) {
		float k = rand();
		testFloat.push_back(k);
	}
	std::list<float> floatStd(testFloat.begin(), testFloat.end());
	ft::list<float> floatFt(testFloat.begin(), testFloat.end());
	for (std::list<float>::iterator it = floatStd.begin(); it != floatStd.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = floatFt.begin(); it != floatFt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Assign list

void assignTest(std::string &std, std::string &ft, int i) {
	std::cout << "Assign int test" << " ";
	int j = rand();
	std::list<int> stdFst(i, j);
	ft::list<int> ftFst(i, j);
	std::list<int> stdSec;
	ft::list<int> ftSec;
	stdSec = stdFst;
	ftSec = ftFst;
	for (std::list<int>::iterator it = stdSec.begin(); it != stdSec.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = ftSec.begin(); it != ftSec.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Assign std::string test" << " ";
	std::string m;
	m += rand();
	std::list<std::string> stdFstStr(i, m);
	ft::list<std::string> ftFstStr(i, m);
	std::list<std::string> stdSecStr;
	ft::list<std::string> ftSecStr;
	stdSecStr = stdFstStr;
	ftSecStr = ftFstStr;
	for (std::list<std::string>::iterator it = stdSecStr.begin(); it != stdSecStr.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = ftSecStr.begin(); it != ftSecStr.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std::cout << "Assign float test" << " ";
	float n = rand();
	std::list<float> stdFstFlt(i, n);
	ft::list<float> ftFstFlt(i, n);
	std::list<float> stdSecFlt;
	ft::list<float> ftSecFlt;
	stdSecFlt = stdFstFlt;
	ftSecFlt = ftFstFlt;
	for (std::list<float>::iterator it = stdSecFlt.begin(); it != stdSecFlt.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = ftSecFlt.begin(); it != ftSecFlt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestList(std::string &std, std::string &ft) {
	std::cout << "Range assign int test" << " ";
	std::list<int> test;
	std::list<int> def;
	ft::list<int> my;
	for (int i = 0; i < 100; i++)
		test.push_back(rand());
	def.assign(test.begin(), test.end());
	my.assign(test.begin(), test.end());
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestListFloat(std::string &std, std::string &ft) {
	std::cout << "Range assign float test" << " ";
	std::list<float> test;
	std::list<float> def;
	ft::list<float> my;
	for (int i = 0; i < 100; i++)
		test.push_back(rand());
	def.assign(test.begin(), test.end());
	my.assign(test.begin(), test.end());
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestListStr(std::string &std, std::string &ft) {
	std::cout << "Range assign std::string test" << " ";
	std::list<std::string> test;
	std::list<std::string> def;
	ft::list<std::string> my;
	std::string j;
	for (int i = 0; i < 100; i++) {
		j += rand();
		test.push_back(j);
		j.clear();
	}
	def.assign(test.begin(), test.end());
	my.assign(test.begin(), test.end());
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Iteratot list

void iteratorTest(std::string &std, std::string &ft, int number) {
	std::list<int> testStd;
	ft::list<int> testFt;
	std::cout << "All iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::list<int>::iterator it = testStd.begin();
	std::list<int>::iterator ite = testStd.end();
	ft::list<int>::iterator itm = testFt.begin();
	ft::list<int>::iterator item = testFt.end();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.begin();
	itm = testFt.begin();
	while (ite != it) {
		ite--;
		std += *ite;
	}
	while (item != itm) {
		item--;
		ft += *item;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reverse iteratot list

void reverseIteratorTest(std::string &std, std::string &ft, int number) {
	std::list<int> testStd;
	ft::list<int> testFt;
	std::cout << "All reverse_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::list<int>::reverse_iterator it = testStd.rbegin();
	std::list<int>::reverse_iterator ite = testStd.rend();
	ft::list<int>::reverse_iterator itm = testFt.rbegin();
	ft::list<int>::reverse_iterator item = testFt.rend();
	while (it != ite) {
		std += *it;
		it++;
	}
	while (itm != item) {
		ft += *itm;
		itm++;
	}
	it = testStd.rbegin();
	itm = testFt.rbegin();
	while (ite != it) {
		ite--;
		std += *ite;
	}
	while (item != itm) {
		item--;
		ft += *item;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const reverse iteratot list


//MARK: - Capacity list

void capacityTests(std::string &std, std::string &ft) {
	std::cout << "All capacity test" << " ";
	std::list<int> testStd;
	ft::list<int> testFt;
	std += testStd.empty();
	ft += testFt.empty();
	std += testStd.size();
	ft += testFt.size();
	listPushFrontElem(testStd, testFt, 100);
	std += testStd.empty();
	ft += testFt.empty();
	std += testStd.size();
	ft += testFt.size();
	std += testStd.max_size();
	ft += testFt.max_size();
	std::list<float> testStdStr;
	ft::list<float> testFtStr;
	std += testStdStr.max_size();
	ft += testFtStr.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Element access list

void accessTest(std::string &std, std::string &ft) {
	std::cout << "Elemen access test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	int i = 0;
	while (i < 10) {
		listPushFrontElem(def, my, 2);
		std += def.front();
		std += def.back();
		ft += my.front();
		ft += my.back();
		i++;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignModTest(std::string &std, std::string &ft, int number) {
	std::cout << "Assign test" << " ";
	float i = rand();
	std::list<float> fstStd(number, i);
	ft::list<float> fstFt(number, i);
	float j = rand();
	while (j == i)
		j = rand();
	fstStd.assign(number, j);
	fstFt.assign(number, j);
	for (std::list<float>::iterator it = fstStd.begin(); it != fstStd.end(); it++) {
		if (*it != j) {
			std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
			std.clear();
			ft.clear();
			return ;
		}
		std += *it;
	}
	for (ft::list<float>::iterator it = fstFt.begin(); it != fstFt.end(); it++) {
		if (*it != j) {
			std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
			std.clear();
			ft.clear();
			return ;
		}
		ft += *it;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Modifiers list

void pushBackTest(std::string &std, std::string &ft, int number) {
	std::cout << "Push back test" << " ";
	std::list<std::string> stdLst;
	ft::list<std::string> ftLst;
	listPushBackElem(stdLst, ftLst, number);
	for (std::list<std::string>::iterator it = stdLst.begin(); it != stdLst.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = ftLst.begin(); it != ftLst.end(); it++)
		ft += *it;
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushFrontTest(std::string &std, std::string &ft, int number) {
	std::cout << "Push front test" << " ";
	std::list<std::string> stdLst;
	ft::list<std::string> ftLst;
	listPushFrontElem(stdLst, ftLst, number);
	for (std::list<std::string>::iterator it = stdLst.begin(); it != stdLst.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = ftLst.begin(); it != ftLst.end(); it++)
		ft += *it;
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popBackTest(std::string &std, std::string &ft, int number) {
	std::cout << "Pop back test" << " ";
	std::list<float> stdLst;
	ft::list<float> ftLst;
	listPushBackElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	listPopBackElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popFrontTest(std::string &std, std::string &ft, int number) {
	std::cout << "Pop front test" << " ";
	std::list<float> stdLst;
	ft::list<float> ftLst;
	listPushBackElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	listPopFrontElem(stdLst, ftLst, number);
	std += stdLst.size();
	ft += ftLst.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void insertSinglPositionTest(std::string &std, std::string  &ft) {
	std::cout << "Insert singl position test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 5);
	def.insert(def.begin()++, 42);
	my.insert(my.begin()++, 42);
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void insertMultyPositionTest(std::string &std, std::string  &ft) {
	std::cout << "Insert multy position test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 5);
	def.insert(++def.begin(), 21, 42);
	my.insert(++my.begin(), 21, 42);
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void insertRangePosotionTest(std::string &std, std::string &ft) {
	std::cout << "Insert range position test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> test;
	for (int l = 0; l < 5; l++)
		test.push_back(l);
	listPushBackElem(def, my, 5);
	def.insert(++def.begin(), ++test.begin(), --(--test.end()));
	my.insert(++my.begin(), ++test.begin(), --(--test.end()));
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseSinglTest(std::string &std, std::string &ft) {
	std::cout << "Erase singl test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std += *(def.erase(++def.begin()));
	ft += *(my.erase(++my.begin()));
	std += *(def.erase(--(--def.end())));
	ft += *(my.erase(--(--my.end())));
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void eraseMultyTest(std::string &std, std::string &ft) {
	std::cout << "Erase multy test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std::list<std::string>::iterator it = def.begin();
	std::list<std::string>::iterator ite = def.end();
	ft::list<std::string>::iterator itm = my.begin();
	ft::list<std::string>::iterator item = my.end();
	for (int i = 0; i < 20; i++) {
		it++;
		itm++;
		ite--;
		item--;
	}
	std += *(static_cast<void>(it), ite);
	ft += *(static_cast<void>(itm), item);
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapTest() {
	std::cout << "Swap test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> swapDef;
	ft::list<std::string> swapMy;
	std::list<std::string> checkDef;
	ft::list<std::string> checkMy;
	listPushBackElem(def, my, 5);
	listPushBackElem(swapDef, swapMy, 10);
	checkDef = def;
	checkMy = my;
	def.swap(swapDef);
	my.swap(swapMy);
	if (swapDef != checkDef && swapMy != checkMy) {
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
		return ;
	}
	checkDef = def;
	checkMy = my;
	swapDef.swap(def);
	swapMy.swap(my);
	if (swapDef != checkDef && swapMy != checkMy)
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
}

void resizeTestStr(std::string &std, std::string &ft) {
	std::cout << "Resize std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(5);
	my.resize(5);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(7, "hello");
	my.resize(7, "hello");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(10);
	my.resize(10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestInt(std::string &std, std::string &ft) {
	std::cout << "Resize int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(5);
	my.resize(5);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(7, 100);
	my.resize(7, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(10);
	my.resize(10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Resize float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(5);
	my.resize(5);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(7, 100.2);
	my.resize(7, 100.2);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.resize(10);
	my.resize(10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearTest(std::string &std, std::string &ft) {
	std::cout << "Clear test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.clear();
	my.clear();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	listPushBackElem(def, my, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Operations list

void spliceTestEntireInt(std::string &std, std::string &ft) {
	std::cout << "Splice entire int test" << " ";
	std::list<int> defInt;
	ft::list<int> myInt;
	std::list<int> spliceInt;
	ft::list<int> mySpliceInt;
	listPushBackElem(defInt, myInt, 10);
	listPushBackElem(spliceInt, mySpliceInt, 4);
	std += defInt.size();
	ft += myInt.size();
	for (std::list<int>::iterator it = defInt.begin(); it != defInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = myInt.begin(); it != myInt.end(); it++)
		ft += *it;
	std += spliceInt.size();
	ft += mySpliceInt.size();
	for (std::list<int>::iterator it = spliceInt.begin(); it != spliceInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySpliceInt.begin(); it != mySpliceInt.end(); it++)
		ft += *it;
	defInt.splice(++defInt.begin(), spliceInt);
	myInt.splice(++myInt.begin(), mySpliceInt);
	std += defInt.size();
	ft += myInt.size();
	for (std::list<int>::iterator it = defInt.begin(); it != defInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = myInt.begin(); it != myInt.end(); it++)
		ft += *it;
	std += spliceInt.size();
	ft += mySpliceInt.size();
	for (std::list<int>::iterator it = spliceInt.begin(); it != spliceInt.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySpliceInt.begin(); it != mySpliceInt.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestEntireFloat(std::string &std, std::string &ft) {
	std::cout << "Splice entire float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> splice;
	ft::list<float> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 4);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice);
	my.splice(++my.begin(), mySplice);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestEntireStr(std::string &std, std::string &ft) {
	std::cout << "Splice entire std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> splice;
	ft::list<std::string> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 4);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice);
	my.splice(++my.begin(), mySplice);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestSinglInt(std::string &std, std::string &ft) {
	std::cout << "Splice single int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> splice;
	ft::list<int> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin());
	my.splice(++my.begin(), mySplice, ++mySplice.begin());
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestSinglFloat(std::string &std, std::string &ft) {
	std::cout << "Splice single float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> splice;
	ft::list<float> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin());
	my.splice(++my.begin(), mySplice, ++mySplice.begin());
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestSinglStr(std::string &std, std::string &ft) {
	std::cout << "Splice single std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> splice;
	ft::list<std::string> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin());
	my.splice(++my.begin(), mySplice, ++mySplice.begin());
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestRangeInt(std::string &std, std::string &ft) {
	std::cout << "Splice range int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> splice;
	ft::list<int> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin(), --(--splice.end()));
	my.splice(++my.begin(), mySplice, ++mySplice.begin(), --(--mySplice.end()));
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<int>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestRangeFloat(std::string &std, std::string &ft) {
	std::cout << "Splice range float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> splice;
	ft::list<float> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin(), --(--splice.end()));
	my.splice(++my.begin(), mySplice, ++mySplice.begin(), --(--mySplice.end()));
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<float>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void spliceTestRangeStr(std::string &std, std::string &ft) {
	std::cout << "Splice range std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> splice;
	ft::list<std::string> mySplice;
	listPushBackElem(def, my, 10);
	listPushBackElem(splice, mySplice, 3);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	def.splice(++def.begin(), splice, ++splice.begin(), --(--splice.end()));
	my.splice(++my.begin(), mySplice, ++mySplice.begin(), --(--mySplice.end()));
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += splice.size();
	ft += mySplice.size();
	for (std::list<std::string>::iterator it = splice.begin(); it != splice.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySplice.begin(); it != mySplice.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeTestInt(std::string &std, std::string &ft) {
	std::cout << "Remove int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(10);
	my.remove(10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(10);
	my.remove(10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Remove float test" << " ";
	std::list<float> def;
	ft::list<float> my;

	ft::list<int> l;

	ft::list<int>::iterator it = l.begin();

	*it;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 42);
	my.insert(++(++my.begin()), 42);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(42.21);
	my.remove(42.21);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove(21.42);
	my.remove(21.42);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeTestStr(std::string &std, std::string &ft) {
	std::cout << "Remove std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), "42");
	my.insert(++(++my.begin()), "42");
	def.insert(++(++def.begin()), "42");
	my.insert(++(++my.begin()), "42");
	def.insert(++(++def.begin()), "21");
	my.insert(++(++my.begin()), "21");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove("42");
	my.remove("42");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove("21");
	my.remove("21");
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void removeIfTest(std::string &std, std::string &ft) {
	std::cout << "Remove if test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 5);
	def.insert(++def.begin(), 9);
	my.insert(++my.begin(), 9);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove_if(singleDigit);
	my.remove_if(singleDigit);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.remove_if(isEven());
	my.remove_if(isEven());
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void uniqueTest(std::string &std, std::string &ft) {
	std::cout << "Unique test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	def.insert(++(++def.begin()), 21);
	my.insert(++(++my.begin()), 21);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.unique();
	my.unique();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.unique(sameRemainderOfDivision);
	my.unique(sameRemainderOfDivision);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void mergeTestInt(std::string &std, std::string &ft) {
	std::cout << "Merge int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> mergDef;
	ft::list<int> mergMy;
	listPushBackElem(def, my, 10);
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	def.merge(mergDef);
	my.merge(mergMy);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	mergDef.merge(def, myComparison);
	mergMy.merge(my, myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void mergeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Merge float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	std::list<float> mergDef;
	ft::list<float> mergMy;
	listPushBackElem(def, my, 10);
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	def.merge(mergDef);
	my.merge(mergMy);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	mergDef.merge(def, myComparison);
	mergMy.merge(my, myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void mergeTestStr(std::string &std, std::string &ft) {
	std::cout << "Merge std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> mergDef;
	ft::list<std::string> mergMy;
	listPushBackElem(def, my, 10);
	listPushBackElem(mergDef, mergMy, 10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	def.merge(mergDef);
	my.merge(mergMy);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = mergDef.begin(); it != mergDef.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mergMy.begin(); it != mergMy.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sortTestInt(std::string &std, std::string &ft) {
	std::cout << "Sort int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort();
	my.sort();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort(myComparison);
	my.sort(myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sortTestFloat(std::string &std, std::string &ft) {
	std::cout << "Sort float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort();
	my.sort();
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort(myComparison);
	my.sort(myComparison);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sortTestStd(std::string &std, std::string &ft) {
	std::cout << "Sort std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.sort();
	my.sort();
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reverseTestInt(std::string &std, std::string &ft) {
	std::cout << "Reverse int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.reverse();
	my.reverse();
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reverseTestFloat(std::string &std, std::string &ft) {
	std::cout << "Reverse float test" << " ";
	std::list<float> def;
	ft::list<float> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.reverse();
	my.reverse();
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reverseTestStr(std::string &std, std::string &ft) {
	std::cout << "Reverse std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	listPushBackElem(def, my, 100);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	def.reverse();
	my.reverse();
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member list

void equalTest(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 == def);
	std += (def == def1);
	std += (def == def);
	std += (def1 == def1);
	ft += (my1 == my);
	ft += (my == my1);
	ft += (my == my);
	ft += (my1 == my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 == defFloat);
	std += (defFloat == defFloat1);
	std += (defFloat == defFloat);
	std += (defFloat1 == defFloat1);
	ft += (myFloat1 == myFloat);
	ft += (myFloat == myFloat1);
	ft += (myFloat == myFloat);
	ft += (myFloat1 == myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void equalTestStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 == defStr);
	std += (defStr == defStr1);
	std += (defStr == defStr);
	std += (defStr1 == defStr1);
	ft += (myStr1 == myStr);
	ft += (myStr == myStr1);
	ft += (myStr == myStr);
	ft += (myStr1 == myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTest(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 != def);
	std += (def != def1);
	std += (def != def);
	std += (def1 != def1);
	ft += (my1 != my);
	ft += (my != my1);
	ft += (my != my);
	ft += (my1 != my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 != defFloat);
	std += (defFloat != defFloat1);
	std += (defFloat != defFloat);
	std += (defFloat1 != defFloat1);
	ft += (myFloat1 != myFloat);
	ft += (myFloat != myFloat1);
	ft += (myFloat != myFloat);
	ft += (myFloat1 != myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void nonEqualTestStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 != defStr);
	std += (defStr != defStr1);
	std += (defStr != defStr);
	std += (defStr1 != defStr1);
	ft += (myStr1 != myStr);
	ft += (myStr != myStr1);
	ft += (myStr != myStr);
	ft += (myStr1 != myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTest(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def1);
	ft += (my < my1);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 < defFloat);
	ft += (myFloat1 < myFloat);
	std += (defFloat < defFloat1);
	ft += (myFloat < myFloat1);
	std += (defFloat < defFloat);
	ft += (myFloat < myFloat);
	std += (defFloat1 < defFloat1);
	ft += (myFloat1 < myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessTestStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::list<std::string> def;
	ft::list<std::string> my;
	std::list<std::string> def1;
	ft::list<std::string> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def < def1);
	ft += (my < my1);
	std += (def1 < def);
	ft += (my1 < my);
	std += (def < def);
	ft += (my < my);
	std += (def1 < def1);
	ft += (my1 < my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTest(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def <= def);
	std += (def1 <= def1);
	ft += (my1 <= my);
	ft += (my <= my1);
	ft += (my <= my);
	ft += (my1 <= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void haha(){
	ft::list<int>::iterator it;
	++it;
}

void lessOrEqualTestFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat1 <= defFloat);
	std += (defFloat <= defFloat1);
	std += (defFloat <= defFloat);
	std += (defFloat1 <= defFloat1);
	ft += (myFloat1 <= myFloat);
	ft += (myFloat <= myFloat1);
	ft += (myFloat <= myFloat);
	ft += (myFloat1 <= myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void lessOrEqualTestStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr1 <= defStr);
	std += (defStr <= defStr1);
	std += (defStr <= defStr);
	std += (defStr1 <= defStr1);
	ft += (myStr1 <= myStr);
	ft += (myStr <= myStr1);
	ft += (myStr <= myStr);
	ft += (myStr1 <= myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTest(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def1 > def);
	std += (def > def1);
	std += (def > def);
	std += (def1 > def1);
	ft += (my1 > my);
	ft += (my > my1);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat > defFloat1);
	std += (defFloat1 > defFloat);
	std += (defFloat > defFloat);
	std += (defFloat1 > defFloat1);
	ft += (myFloat > myFloat1);
	ft += (myFloat1 > myFloat);
	ft += (myFloat > myFloat);
	ft += (myFloat1 > myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr > defStr1);
	std += (defStr1 > defStr);
	std += (defStr > defStr);
	std += (defStr1 > defStr1);
	ft += (myStr > myStr1);
	ft += (myStr1 > myStr);
	ft += (myStr > myStr);
	ft += (myStr1 > myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTest(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::list<int> def;
	ft::list<int> my;
	std::list<int> def1;
	ft::list<int> my1;
	listPushBackElem(def, my, 100);
	listPushBackElem(def1, my1, 50);
	std += (def >= def1);
	std += (def1 >= def);
	std += (def >= def);
	std += (def1 >= def1);
	ft += (my >= my1);
	ft += (my1 >= my);
	ft += (my >= my);
	ft += (my1 >= my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::list<float> defFloat;
	ft::list<float> myFloat;
	std::list<float> defFloat1;
	ft::list<float> myFloat1;
	listPushBackElem(defFloat, myFloat, 100);
	listPushBackElem(defFloat1, myFloat1, 50);
	std += (defFloat >= defFloat1);
	std += (defFloat1 >= defFloat);
	std += (defFloat >= defFloat);
	std += (defFloat1 >= defFloat1);
	ft += (myFloat >= myFloat1);
	ft += (myFloat1 >= myFloat);
	ft += (myFloat >= myFloat);
	ft += (myFloat1 >= myFloat1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::list<std::string> defStr;
	ft::list<std::string> myStr;
	std::list<std::string> defStr1;
	ft::list<std::string> myStr1;
	listPushBackElem(defStr, myStr, 100);
	listPushBackElem(defStr1, myStr1, 50);
	std += (defStr >= defStr1);
	std += (defStr1 >= defStr);
	std += (defStr >= defStr);
	std += (defStr1 >= defStr1);
	ft += (myStr >= myStr1);
	ft += (myStr1 >= myStr);
	ft += (myStr >= myStr);
	ft += (myStr1 >= myStr1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTest(std::string &std, std::string &ft) {
	std::cout << "Non member swap int test" << " ";
	std::list<int> def;
	std::list<int> toSwap;
	ft::list<int> my;
	ft::list<int> mySwap;
	listPushBackElem(def, my, 10);
	listPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::list<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestFloat(std::string &std, std::string &ft) {
	std::cout << "Non member swap float test" << " ";
	std::list<float> def;
	std::list<float> toSwap;
	ft::list<float> my;
	ft::list<float> mySwap;
	listPushBackElem(def, my, 10);
	listPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::list<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestStr(std::string &std, std::string &ft) {
	std::cout << "Non member swap std::string test" << " ";
	std::list<std::string> def;
	std::list<std::string> toSwap;
	ft::list<std::string> my;
	ft::list<std::string> mySwap;
	listPushBackElem(def, my, 10);
	listPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::list<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::list<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::list<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void  testList() {
	std::cout << "                            CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTest(std, ft);
	fillCnstTest(std, ft, 1000);
	rangeCnstTest(std, ft, 1000);
	std::cout << "                            ASSIGN" << std::endl;
	assignTest(std, ft, 1000);
	assignRangeTestList(std, ft);
	assignRangeTestListFloat(std, ft);
	assignRangeTestListStr(std, ft);
	std::cout << "                            ITERATORS" << std::endl;
	iteratorTest(std, ft, 1000);
	reverseIteratorTest(std, ft, 1000);
	std::cout << "                            CAPACITY" << std::endl;
	capacityTests(std, ft);
	std::cout << "                            ELEMENT ACCESS" << std::endl;
	accessTest(std, ft);
	std::cout << "                            MODIFIERS" << std::endl;
	assignModTest(std, ft, 1000);
	pushBackTest(std, ft, 1000);
	pushFrontTest(std, ft, 1000);
	popBackTest(std, ft, 1000);
	popFrontTest(std, ft, 1000);
	insertSinglPositionTest(std, ft);
	insertMultyPositionTest(std, ft);
	insertRangePosotionTest(std, ft);
	eraseSinglTest(std, ft);
	eraseMultyTest(std, ft);
	swapTest();
	resizeTestStr(std, ft);
	resizeTestInt(std, ft);
	resizeTestFloat(std, ft);
	clearTest(std, ft);
	std::cout << "                            OPERATIONS" << std::endl;
	spliceTestEntireInt(std, ft);
	spliceTestEntireFloat(std, ft);
	spliceTestEntireStr(std, ft);
	spliceTestSinglInt(std, ft);
	spliceTestSinglFloat(std, ft);
	spliceTestSinglStr(std, ft);
	spliceTestRangeInt(std, ft);
	spliceTestRangeFloat(std, ft);
	spliceTestRangeStr(std, ft);
	removeTestInt(std, ft);
	removeTestFloat(std, ft);
	removeTestStr(std, ft);
	removeIfTest(std, ft);
	uniqueTest(std, ft);

	mergeTestInt(std, ft);
	mergeTestFloat(std, ft);
	mergeTestStr(std, ft);
	sortTestInt(std, ft);
	sortTestFloat(std, ft);
	sortTestStd(std, ft);
	reverseTestInt(std, ft);
	reverseTestFloat(std, ft);
	reverseTestStr(std, ft);
	std::cout << "                            NON-MEMBER FUNCTION OVERLOADS" << std::endl;
	equalTest(std, ft);
	equalTestFloat(std, ft);
	equalTestStr(std, ft);
	nonEqualTest(std, ft);
	nonEqualTestFloat(std, ft);
	nonEqualTestStr(std, ft);
	lessTest(std, ft);
	lessTestFloat(std, ft);
	lessTestStr(std, ft);
	lessOrEqualTest(std, ft);
	lessOrEqualTestFloat(std, ft);
	lessOrEqualTestStr(std, ft);
	greaterTest(std, ft);
	greaterTestFloat(std, ft);
	greaterTestStr(std, ft);
	greaterOrEqualTest(std, ft);
	greaterOrEqualTestFloat(std, ft);
	greaterOrEqualTestStr(std, ft);
	swapNonMemberTest(std, ft);
	swapNonMemberTestFloat(std, ft);
	swapNonMemberTestStr(std, ft);
}



int main(){
	testList();
}


