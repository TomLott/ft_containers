
#include <iostream>
#include <vector>
#include "vector.hpp"

//MARK: - Utilst vector

template <typename T>
void VectorPushBackElem(std::vector<T> &std, ft::vector<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
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
	std += def.capacity();
	ft += my.capacity();
}


//MARK: - Defoult constructor vector

void defaultCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Default constructor int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Default constructor float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Default constructor std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Fill constructor vector

void fillCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Fill constructor int test" << " ";
	std::vector<int> def(4, 100);
	ft::vector<int> my(4, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Fill constructor float test" << " ";
	std::vector<float> def(4, 100.42);
	ft::vector<float> my(4, 100.42);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Fill constructor std::string test" << " ";
	std::string set;
	set += "100";
	std::vector<std::string> def(4, set);
	ft::vector<std::string> my(4, set);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Range constructor vector

void rangeCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Range constructor int test" << " ";
	std::vector<int> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::vector<int> def(++test.begin(), --(--test.end()));
	ft::vector<int> my(++test.begin(), --(--test.end()));
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Range constructor float test" << " ";
	std::vector<float> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i + 0.42);
	std::vector<float> def(++test.begin(), --(--test.end()));
	ft::vector<float> my(++test.begin(), --(--test.end()));
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Range constructor std::string test" << " ";
	std::vector<std::string> test;
	std::string chr;
	for (int i = 0; i < 10; i++) {
		chr += i;
		test.push_back(chr);
		chr.clear();
	}
	std::vector<std::string> def(++test.begin(), test.end());
	ft::vector<std::string> my(++test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Copy constructor vector

void copyCnstTestVector(std::string &std, std::string &ft) {
	std::cout << "Copy constructor int test" << " ";
	std::vector<int> test;
	ft::vector<int> test1;
	for (int i = 0; i < 10; i++) {
		test.push_back(i);
		test1.push_back(i);
	}
	std::vector<int> def(test);
	ft::vector<int> my(test1);
	VectorFillStr(def, my, std, ft);

//	std::cout << "" << std::endl;
//	std::cout << "sz orig = " << def.size() << "	sz mine = " << my.size() << std::endl;
//	std::cout << "cp orig = " << def.capacity() << "	cp mine = " << my.capacity() << std::endl;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Copy constructor float test" << " ";
	std::vector<float> test;
	ft::vector<float> test1;
	for (int i = 0; i < 10; i++) {
		test.push_back(i + 0.42);
		test1.push_back(i + 0.42);
	}
	std::vector<float> def(test);
	ft::vector<float> my(test1);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void copyCnstTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Copy constructor std::string test" << " ";
	std::vector<std::string> test;
	ft::vector<std::string> test1;
	std::string chr;
	for (int i = 0; i < 10; i++) {
		chr += rand();
		test.push_back(chr);
		test1.push_back(chr);
		chr.clear();
	}
	std::vector<std::string> def(test);
	ft::vector<std::string> my(test1);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Assignation vector

void assignTestVector(std::string &std, std::string &ft) {
	std::cout << "Assign int test" << " ";
	std::vector<int> def;
	std::vector<int> toAssign;
	ft::vector<int> my;
	ft::vector<int> myAssign;
	for (int i = 0; i < 10; i++) {
		toAssign.push_back(i);
		myAssign.push_back(i);
	}
	def = toAssign;
	my = myAssign;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
//	std::cout << "std = " << std << std::endl;
//	std::cout << "my = " << ft << std::endl;
//	std::cout << "my sz - " << my.size() << "oth sz - " << def.size() << std::endl;
//	std::cout << "other cap - " << my.capacity() << "oth cap - " << def.capacity() << std::endl;
	std.clear();
	ft.clear();
}

void assignTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Assign float test" << " ";
	std::vector<float> def;
	std::vector<float> toAssign;
	ft::vector<float> my;
	ft::vector<float> myAssign;
	for (int i = 0; i < 10; i++) {
		toAssign.push_back(i + 0.42);
		myAssign.push_back(i + 0.42);
	}
	def = toAssign;
	my = myAssign;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Assign std::string test" << " ";
	std::vector<std::string> def;
	std::vector<std::string> toAssign;
	ft::vector<std::string> my;
	ft::vector<std::string> myAssign;
	std::string chr;
	for (int i = 0; i < 10; i++) {
		chr += rand();
		toAssign.push_back(chr);
		myAssign.push_back(chr);
		chr.clear();
	}
	def = toAssign;
	my = myAssign;
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Iterator vector

void iteratorTestVector(std::string &std, std::string &ft, int number) {
	std::vector<int> testStd;
	ft::vector<int> testFt;
	std::cout << "All iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::vector<int>::iterator it = testStd.begin();
	std::vector<int>::iterator ite = testStd.end();
	ft::vector<int>::iterator itm = testFt.begin();
	ft::vector<int>::iterator item = testFt.end();
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
	ite--;
	item--;
	while (ite != it) {
		std += *ite;
		ite--;
	}
	while (item != itm) {
		ft += *item;
		item--;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const iterator vector


//MARK: - Reverse iterator vector

void reverseIteratorTestVector(std::string &std, std::string &ft, int number) {
	std::vector<int> testStd;
	ft::vector<int> testFt;
	std::cout << "All reverse_iterator test" << " ";
	for (int l = 0; l < number; l++) {
		testStd.push_back(l);
		testFt.push_back(l);
	}
	std::vector<int>::reverse_iterator it = testStd.rbegin();
	std::vector<int>::reverse_iterator ite = testStd.rend();
	std::vector<int>::const_reverse_iterator itce = testStd.rend();

	ft::vector<int>::reverse_iterator itm = testFt.rbegin();
	ft::vector<int>::reverse_iterator item = testFt.rend();
	it++;
	itm++;
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
	ite--;
	item--;
	while (ite != it) {
		std += *ite;
		ite--;
	}
	while (item != itm) {
		ft += *item;
		item--;
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Const reverse iterator vector

//void constReverseIteratorTestVector(std::string &std, std::string &ft, int number) {
//	std::vector<int> testStd;
//	ft::vector<int> testFt;
//	std::cout << "All const_reverse_iterator test" << " ";
//	for (int l = 0; l < number; l++) {
//		testStd.push_back(l);
//		testFt.push_back(l);
//	}
//	std::vector<int>::const_reverse_iterator it = testStd.crbegin();
//	std::vector<int>::const_reverse_iterator ite = testStd.crend();
//	ft::vector<int>::const_reverse_iterator itm = testFt.crbegin();
//	ft::vector<int>::const_reverse_iterator item = testFt.crend();
//	it++;
//	itm++;
//	while (it != ite) {
//		std += *it;
//		it++;
//	}
//	while (itm != item) {
//		ft += *itm;
//		itm++;
//	}
//	it = testStd.crbegin();
//	itm = testFt.crbegin();
//	ite--;
//	item--;
//	while (ite != it) {
//		std += *ite;
//		ite--;
//	}
//	while (item != itm) {
//		ft += *item;
//		item--;
//	}
//	if (std == ft)
//		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
//	else
//		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
//	std.clear();
//	ft.clear();
//}

//MARK: - Size vector

void sizeTest(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Max size vector

void maxSizeTest(std::string &std, std::string &ft) {
	std::cout << "Max size int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1000);
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void maxSizeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Max size float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1000);
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void maxSizeTestStr(std::string &std, std::string &ft) {
	std::cout << "Max size std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1000);
	std += def.max_size();
	ft += my.max_size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Resize vector

void resizeTestIntVector(std::string &std, std::string &ft) {
	std::cout << "Resize int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.resize(80);
	my.resize(80);
	VectorFillStr(def, my, std, ft);
	def.resize(90);
	my.resize(90);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestFloatVector(std::string &std, std::string &ft) {
	std::cout << "Resize float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.resize(80);
	my.resize(80);
	VectorFillStr(def, my, std, ft);
	def.resize(90);
	my.resize(90);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void resizeTestStrVector(std::string &std, std::string &ft) {
	std::cout << "Resize std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.resize(80);
	my.resize(80);
	VectorFillStr(def, my, std, ft);
	def.resize(90);
	my.resize(90);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Capacity vector

void capacityTestVector(std::string &std, std::string &ft) {
	std::cout << "Capacity int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 1);
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void capacityTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Capacity float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 1);
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void capacityTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Capacity std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 1);
	VectorFillStr(def, my, std, ft);
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty vector

void emptyVectorTest(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std += def.empty();
	ft += my.empty();
	VectorPushBackElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	std += def.empty();
	ft += my.empty();
	VectorPushBackElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std += def.empty();
	ft += my.empty();
	VectorPushBackElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Reserve vector

void reserveVectorTest(std::string &std, std::string &ft) {
	std::cout << "Reserve int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(500);
	my.reserve(500);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(1);
	my.reserve(1);
	std += def.capacity();
	ft += my.capacity();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reserveVectorFloatTest(std::string &std, std::string &ft) {
	std::cout << "Reserve float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(500);
	my.reserve(500);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(1);
	my.reserve(1);
	std += def.capacity();
	ft += my.capacity();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void reserveVectorStrTest(std::string &std, std::string &ft) {
	std::cout << "Reserve std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(500);
	my.reserve(500);
	std += def.capacity();
	ft += my.capacity();
	def.reserve(1);
	my.reserve(1);
	std += def.capacity();
	ft += my.capacity();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Operator [] vector

void squareBracketsTest(std::string &std, std::string &ft) {
	std::cout << "Operator [] int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	std += def[50];
	ft += my[50];
	std += def[20];
	ft += my[20];
	std += def[10];
	ft += my[10];
	std += def[90];
	ft += my[90];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestFloat(std::string &std, std::string &ft) {
	std::cout << "Operator [] float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	std += def[50];
	ft += my[50];
	std += def[20];
	ft += my[20];
	std += def[10];
	ft += my[10];
	std += def[90];
	ft += my[90];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void squareBracketsTestStr(std::string &std, std::string &ft) {
	std::cout << "Operator [] std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	std += def[50];
	ft += my[50];
	std += def[20];
	ft += my[20];
	std += def[10];
	ft += my[10];
	std += def[90];
	ft += my[90];
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - At vector

void atTest(std::string &std, std::string &ft) {
	std::cout << "At int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	std += def.at(50);
	ft += my.at(50);
	std += def.at(20);
	ft += my.at(20);
	std += def.at(10);
	ft += my.at(10);
	std += def.at(90);
	ft += my.at(90);
	def.at(20) = 1;
	my.at(20) = 1;
	std += def.at(20);
	ft += my.at(20);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void atTestFloat(std::string &std, std::string &ft) {
	std::cout << "At float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	std += def.at(50);
	ft += my.at(50);
	std += def.at(20);
	ft += my.at(20);
	std += def.at(10);
	ft += my.at(10);
	std += def.at(90);
	ft += my.at(90);
	def.at(20) = 1;
	my.at(20) = 1;
	std += def.at(20);
	ft += my.at(20);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void atTestStr(std::string &std, std::string &ft) {
	std::cout << "At std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	std += def.at(50);
	ft += my.at(50);
	std += def.at(20);
	ft += my.at(20);
	std += def.at(10);
	ft += my.at(10);
	std += def.at(90);
	ft += my.at(90);
	def.at(20) = "1";
	my.at(20) = "1";
	std += def.at(20);
	ft += my.at(20);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Front vector

void frontTest(std::string &std, std::string &ft) {
	std::cout << "Front int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 10);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestFloat(std::string &std, std::string &ft) {
	std::cout << "Front float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 10);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestStr(std::string &std, std::string &ft) {
	std::cout << "Front std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 10);
	std += def.front();
	ft += my.front();
	VectorPushBackElem(def, my, 1);
	std += def.front();
	ft += my.front();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Back vector

void backTest(std::string &std, std::string &ft) {
	std::cout << "Back int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 10);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestFloat(std::string &std, std::string &ft) {
	std::cout << "Back float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 10);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestStr(std::string &std, std::string &ft) {
	std::cout << "Back std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 10);
	std += def.back();
	ft += my.back();
	def.clear();
	my.clear();
	VectorPushBackElem(def, my, 1);
	std += def.back();
	ft += my.back();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Range assign vector

void assignRangeTest(std::string &std, std::string &ft) {
	std::cout << "Assign range int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> toAssign;
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 8; i++)
		toAssign.push_back(rand());
	def.assign(++(++toAssign.begin()), --toAssign.end());
	my.assign(++(++toAssign.begin()), --toAssign.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestFloat(std::string &std, std::string &ft) {
	std::cout << "Assign range float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	std::vector<float> toAssign;
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 10; i++)
		toAssign.push_back(rand());
	def.assign(++(++toAssign.begin()), --toAssign.end());
	my.assign(++(++toAssign.begin()), --toAssign.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignRangeTestStr(std::string &std, std::string &ft) {
	std::cout << "Assign range std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::vector<std::string> toAssign;
	std::string test;
	VectorPushBackElem(def, my, 10);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 10; i++) {
		test += rand();
		toAssign.push_back(test);
		test.clear();
	}
	def.assign(++(++toAssign.begin()), --toAssign.end());
	my.assign(++(++toAssign.begin()), --toAssign.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Fill assign vector

void assignFillTest(std::string &std, std::string &ft) {
	std::cout << "Assign fill int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	def.assign(10, 42);
	my.assign(10, 42);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignFillTestFloat(std::string &std, std::string &ft) {
	std::cout << "Assign fill float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	def.assign(10, 42.21);
	my.assign(10, 42.21);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void assignFillTestStr(std::string &std, std::string &ft) {
	std::cout << "Assign fill std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	def.assign(10, "42");
	my.assign(10, "42");
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Push back vector

void pushBackVectorTest(std::string &std, std::string &ft) {
	std::cout << "Push back int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushBackVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Push back float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushBackVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Push back std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Pop back vector

void popBackVectorTest(std::string &std, std::string &ft) {
	std::cout << "Pop back int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 20; i++) {
		def.pop_back();
		my.pop_back();
		VectorFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popBackVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Pop back float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 20; i++) {
		def.pop_back();
		my.pop_back();
		VectorFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popBackVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Pop back std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 1000);
	VectorFillStr(def, my, std, ft);
	for (int i = 0; i < 20; i++) {
		def.pop_back();
		my.pop_back();
		VectorFillStr(def, my, std, ft);
	}
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Insert vector

void singleInsertVectorTest(std::string &std, std::string &ft) {
	std::cout << "Single insert int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 10);
	std::vector<int>::iterator it = ++def.begin();
	ft::vector<int>::iterator mit = ++my.begin();
	it = def.insert(it, 42);
	mit = my.insert(mit, 42);
	VectorFillStr(def, my, std, ft);
	if (std == ft && *it == *mit)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Single insert float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 10);
	std::vector<float>::iterator it = ++def.begin();
	ft::vector<float>::iterator mit = ++my.begin();
	it = def.insert(it, 42.21);
	mit = my.insert(mit, 42.21);
	VectorFillStr(def, my, std, ft);
	if (std == ft && *it == *mit)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleInsertVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Single insert std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 10);
	std::vector<std::string>::iterator it = ++def.begin();
	ft::vector<std::string>::iterator mit = ++my.begin();
	std::string test;
	test += "42";
	it = def.insert(it, test);
	mit = my.insert(mit, test);
	VectorFillStr(def, my, std, ft);
	if (std == ft && *it == *mit)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillInsertVectorTest(std::string &std, std::string &ft) {
	std::cout << "Fill insert int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 10);
	def.insert(def.begin() + 5, 5, 21);
	my.insert(my.begin() + 5, 5, 21);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillInsertVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Fill insert float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 10);
	def.insert(def.begin() + 5, 5, 21.42);
	my.insert(my.begin() + 5, 5, 21.42);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void fillInsertVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Fill insert std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 10);
	def.insert(def.begin() + 5, 5, "21");
	my.insert(my.begin() + 5, 5, "21");
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertVectorTest(std::string &std, std::string &ft) {
	std::cout << "Range insert int test" << " ";
	std::vector<int> test;
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	for (int i = 0; i < 10; i++)
		test.push_back(rand());
	def.insert(def.begin() + 10, test.begin(), test.end());
	my.insert(my.begin() + 10, test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range insert float test" << " ";
	std::vector<float> test;
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	for (int i = 0; i < 10; i++)
		test.push_back(rand());
	def.insert(def.begin() + 10, test.begin(), test.end());
	my.insert(my.begin() + 10, test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeInsertVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Range insert std::string test" << " ";
	std::vector<std::string> test;
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::string str;
	VectorPushBackElem(def, my, 100);
	for (int i = 0; i < 10; i++) {
		str += rand();
		test.push_back(str);
		str.clear();
	}
	def.insert(def.begin() + 10, test.begin(), test.end());
	my.insert(my.begin() + 10, test.begin(), test.end());
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Erase vector

void singleEraseVectorTest(std::string &std, std::string &ft) {
	std::cout << "Single erase int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40);
	my.erase(my.begin() + 40);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleEraseVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Single erase float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40);
	my.erase(my.begin() + 40);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void singleEraseVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Single erase std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40);
	my.erase(my.begin() + 40);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeEraseVectorTest(std::string &std, std::string &ft) {
	std::cout << "Range erase int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40, def.begin() + 60);
	my.erase(my.begin() + 40, my.begin() + 60);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeEraseVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Range erase float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40, def.begin() + 60);
	my.erase(my.begin() + 40, my.begin() + 60);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void rangeEraseVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Range erase std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	def.erase(def.begin() + 40, def.begin() + 60);
	my.erase(my.begin() + 40, my.begin() + 60);
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Swap vector

void swapVectorTest(std::string &std, std::string &ft) {
	std::cout << "Swap int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> toSwap;
	ft::vector<int> mySwap;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(toSwap, mySwap, 50);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Swap float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	std::vector<float> toSwap;
	ft::vector<float> mySwap;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(toSwap, mySwap, 50);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Swap std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::vector<std::string> toSwap;
	ft::vector<std::string> mySwap;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(toSwap, mySwap, 50);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	def.swap(toSwap);
	my.swap(mySwap);
	VectorFillStr(def, my, std, ft);
	VectorFillStr(toSwap, mySwap, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Clear vector

void clearVectorTest(std::string &std, std::string &ft) {
	std::cout << "Clear int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearVectorTestFloat(std::string &std, std::string &ft) {
	std::cout << "Clear float test" << " ";
	std::vector<float> def;
	ft::vector<float> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void clearVectorTestStr(std::string &std, std::string &ft) {
	std::cout << "Clear std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	VectorPushBackElem(def, my, 100);
	VectorFillStr(def, my, std, ft);
	def.clear();
	my.clear();
	VectorFillStr(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member vector

void equalTestVector(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void equalTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
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

void equalTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
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

void nonEqualTestVector(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void nonEqualTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
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

void nonEqualTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
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

void lessTestVector(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void lessTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
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

void lessTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::vector<std::string> def;
	ft::vector<std::string> my;
	std::vector<std::string> def1;
	ft::vector<std::string> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void lessOrEqualTestVector(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void lessOrEqualTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
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

void lessOrEqualTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
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

void greaterTestVector(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void greaterTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
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

void greaterTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
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

void greaterOrEqualTestVector(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::vector<int> def;
	ft::vector<int> my;
	std::vector<int> def1;
	ft::vector<int> my1;
	VectorPushBackElem(def, my, 100);
	VectorPushBackElem(def1, my1, 50);
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

void greaterOrEqualTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::vector<float> defFloat;
	ft::vector<float> myFloat;
	std::vector<float> defFloat1;
	ft::vector<float> myFloat1;
	VectorPushBackElem(defFloat, myFloat, 100);
	VectorPushBackElem(defFloat1, myFloat1, 50);
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

void greaterOrEqualTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::vector<std::string> defStr;
	ft::vector<std::string> myStr;
	std::vector<std::string> defStr1;
	ft::vector<std::string> myStr1;
	VectorPushBackElem(defStr, myStr, 100);
	VectorPushBackElem(defStr1, myStr1, 50);
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

void swapNonMemberTestVector(std::string &std, std::string &ft) {
	std::cout << "Non member swap int test" << " ";
	std::vector<int> def;
	std::vector<int> toSwap;
	ft::vector<int> my;
	ft::vector<int> mySwap;
	VectorPushBackElem(def, my, 10);
	VectorPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::vector<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::vector<int>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<int>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<int>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestVectorFloat(std::string &std, std::string &ft) {
	std::cout << "Non member swap float test" << " ";
	std::vector<float> def;
	std::vector<float> toSwap;
	ft::vector<float> my;
	ft::vector<float> mySwap;
	VectorPushBackElem(def, my, 10);
	VectorPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::vector<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::vector<float>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<float>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<float>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void swapNonMemberTestVectorStr(std::string &std, std::string &ft) {
	std::cout << "Non member swap std::string test" << " ";
	std::vector<std::string> def;
	std::vector<std::string> toSwap;
	ft::vector<std::string> my;
	ft::vector<std::string> mySwap;
	VectorPushBackElem(def, my, 10);
	VectorPushBackElem(toSwap, mySwap, 10);
	std += def.size();
	ft += my.size();
	for (std::vector<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	std::swap(def, toSwap);
	ft::swap(my, mySwap);
	std += def.size();
	ft += my.size();
	for (std::vector<std::string>::iterator it = def.begin(); it != def.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = my.begin(); it != my.end(); it++)
		ft += *it;
	std += toSwap.size();
	ft += mySwap.size();
	for (std::vector<std::string>::iterator it = toSwap.begin(); it != toSwap.end(); it++)
		std += *it;
	for (ft::vector<std::string>::iterator it = mySwap.begin(); it != mySwap.end(); it++)
		ft += *it;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Vector

void testVector() {
	std::cout << "                            CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestVector(std, ft);
	defaultCnstTestVectorFloat(std, ft);
	defaultCnstTestVectorStr(std, ft);
	fillCnstTestVector(std, ft);
	fillCnstTestVectorFloat(std, ft);
	fillCnstTestVectorStr(std, ft);

	rangeCnstTestVector(std, ft);
	rangeCnstTestVectorFloat(std, ft);
	rangeCnstTestVectorStr(std, ft);

	copyCnstTestVector(std, ft);
//	std::cout << "\tcopyCnstTestVector(std, ft);" << std::endl;
	copyCnstTestVectorFloat(std, ft);
//	std::cout << "\tcopyCnstTestVectorFloat(std, ft);" << std::endl;
	copyCnstTestVectorStr(std, ft);
//	std::cout << "\tcopyCnstTestVectorStr(std, ft);" << std::endl;
	std::cout << "                            ASSIGNATION" << std::endl;
	assignTestVector(std, ft);
	assignTestVectorFloat(std, ft);
	assignTestVectorStr(std, ft);
	std::cout << "                            ITERATORS" << std::endl;
	iteratorTestVector(std, ft, 1000);
	reverseIteratorTestVector(std, ft, 10);
	std::cout << "                            CAPACITY" << std::endl;
	sizeTest(std, ft);
	sizeTestFloat(std, ft);
	sizeTestStr(std, ft);
	maxSizeTest(std, ft);
	maxSizeTestFloat(std, ft);
	maxSizeTestStr(std, ft);
	resizeTestIntVector(std, ft);
	resizeTestFloatVector(std, ft);
	resizeTestStrVector(std, ft);
	capacityTestVector(std, ft);
	capacityTestVectorFloat(std, ft);
	capacityTestVectorStr(std, ft);
	emptyVectorTest(std, ft);
	emptyVectorTestFloat(std, ft);
	emptyVectorTestStr(std, ft);
	reserveVectorTest(std, ft);
	reserveVectorFloatTest(std, ft);
	reserveVectorStrTest(std, ft);
	std::cout << "                            ELEMENT ACCESS" << std::endl;
	squareBracketsTest(std, ft);
	squareBracketsTestFloat(std, ft);
	squareBracketsTestStr(std, ft);
	atTest(std, ft);
	atTestFloat(std, ft);
	atTestStr(std, ft);
	frontTest(std, ft);
	frontTestFloat(std, ft);
	frontTestStr(std, ft);
	backTest(std, ft);
	backTestFloat(std, ft);
	backTestStr(std, ft);
	std::cout << "                            MODIFIERS" << std::endl;
	assignRangeTest(std, ft);
	assignRangeTestFloat(std, ft);
	assignRangeTestStr(std, ft);
	assignFillTest(std, ft);
	assignFillTestFloat(std, ft);
	assignFillTestStr(std, ft);
	pushBackVectorTest(std, ft);
	pushBackVectorTestFloat(std, ft);
	pushBackVectorTestStr(std, ft);
	popBackVectorTest(std, ft);
	popBackVectorTestFloat(std, ft);
	popBackVectorTestStr(std, ft);
	singleInsertVectorTest(std, ft);
	singleInsertVectorTestFloat(std, ft);
	singleInsertVectorTestStr(std, ft);
	fillInsertVectorTest(std, ft);
	fillInsertVectorTestFloat(std, ft);
	fillInsertVectorTestStr(std, ft);
	rangeInsertVectorTest(std, ft);
	rangeInsertVectorTestFloat(std, ft);
	rangeInsertVectorTestStr(std, ft);
	singleEraseVectorTest(std, ft);
	singleEraseVectorTestFloat(std, ft);
	singleEraseVectorTestStr(std, ft);
	rangeEraseVectorTest(std, ft);
	rangeEraseVectorTestFloat(std, ft);
	rangeEraseVectorTestStr(std, ft);
	swapVectorTest(std, ft);
	swapVectorTestFloat(std, ft);
	swapVectorTestStr(std, ft);
	clearVectorTest(std, ft);
	clearVectorTestFloat(std, ft);
	clearVectorTestStr(std, ft);
	std::cout << "                            NON MEMBER FUNCTIONS OVERLOADS" << std::endl;
	equalTestVector(std, ft);
	equalTestVectorFloat(std, ft);
	equalTestVectorStr(std, ft);
	nonEqualTestVector(std, ft);
	nonEqualTestVectorFloat(std, ft);
	nonEqualTestVectorStr(std, ft);
	lessTestVector(std, ft);
	lessTestVectorFloat(std, ft);
	lessTestVectorStr(std, ft);
	lessOrEqualTestVector(std, ft);
	lessOrEqualTestVectorFloat(std, ft);
	lessOrEqualTestVectorStr(std, ft);
	greaterTestVector(std, ft);
	greaterTestVectorFloat(std, ft);
	greaterTestVectorStr(std, ft);
	greaterOrEqualTestVector(std, ft);
	greaterOrEqualTestVectorFloat(std, ft);
	greaterOrEqualTestVectorStr(std, ft);
	swapNonMemberTestVector(std, ft);
	swapNonMemberTestVectorFloat(std, ft);
	swapNonMemberTestVectorStr(std, ft);
}

int main()
{
//	std::cout << "                                                LIST" << std::endl;
//	testList();
	std::cout << "                                                VECTOR" << std::endl;
	testVector();
	std::cout << "                                                MAP" << std::endl;
//	testMap();
//	std::cout << "                                                QUEUE" << std::endl;
//	testQueue();
//	std::cout << "                                                STACK" << std::endl;
//	testStack();
//	while (1)
//		;
	return (0);
}
