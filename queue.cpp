//MARK: - Utils queue
#include <queue>
#include <string>
#include "utils.hpp"
#include "queue.hpp"
#include <vector>
#include <list>

template <typename T>
void queuePushElem(std::queue<T> &std, ft::queue<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push(i);
		ft.push(i);
	}
}

template <typename T>
void fillStrQueue(std::queue<T> &def, ft::queue<T> &my, std::string &std, std::string &ft) {
	std += def.back();
	ft += my.back();
	std += def.front();
	ft += my.front();
	std += def.size();
	ft += my.size();
}

//MARK: - Default constructor queue

void defaultCnstTestQueue(std::string &std, std::string &ft) {
	std::cout << "Default int constructor test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Default float constructor test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Default std::string constructor test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty queue

void emptyTestQueue(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std += def.empty();
	ft += my.empty();
	queuePushElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std += def.empty();
	ft += my.empty();
	queuePushElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std += def.empty();
	ft += my.empty();
	queuePushElem(def, my, 10);
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size queue

void sizeTestQueue(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 50);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 50);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string  test" << " ";
	std::queue<std::string > def;
	ft::queue<std::string > my;
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	queuePushElem(def, my, 50);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Front queue

void frontTestQueue(std::string &std, std::string &ft) {
	std::cout << "Front int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Front float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void frontTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Front std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Back queue

void backTestQueue(std::string &std, std::string &ft) {
	std::cout << "Back int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Back float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void backTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Back std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Push queue

void pushTestQueue(std::string &std, std::string &ft) {
	std::cout << "Push int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Push float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Push std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 1);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 20);
	fillStrQueue(def, my, std, ft);
	queuePushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Pop queue

void popTestQueue(std::string &std, std::string &ft) {
	std::cout << "Pop int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Pop float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Pop std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	queuePushElem(def, my, 10);
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrQueue(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member Queue

void equalTestQueue(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void equalTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void equalTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void nonEqualTestQueue(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void nonEqualTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void nonEqualTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void lessTestQueue(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void lessTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void lessTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void lessOrEqualTestQueue(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void lessOrEqualTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def1 <= def);
	std += (def <= def1);
	std += (def<= def);
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

void lessOrEqualTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void greaterTestQueue(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void greaterTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def > def1);
	std += (def1 > def);
	std += (def > def);
	std += (def1 > def1);
	ft += (my > my1);
	ft += (my1 > my);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
	std += (def > def1);
	std += (def1 > def);
	std += (def > def);
	std += (def1 > def1);
	ft += (my > my1);
	ft += (my1 > my);
	ft += (my > my);
	ft += (my1 > my1);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void greaterOrEqualTestQueue(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::queue<int> def;
	ft::queue<int> my;
	std::queue<int> def1;
	ft::queue<int> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void greaterOrEqualTestQueueFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::queue<float> def;
	ft::queue<float> my;
	std::queue<float> def1;
	ft::queue<float> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

void greaterOrEqualTestQueueStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::queue<std::string> def;
	ft::queue<std::string> my;
	std::queue<std::string> def1;
	ft::queue<std::string> my1;
	queuePushElem(def, my, 100);
	queuePushElem(def1, my1, 50);
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

//MARK: - Queue

void testQueue() {
	std::cout << "                         CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestQueue(std, ft);
	defaultCnstTestQueueFloat(std, ft);
	defaultCnstTestQueueStr(std, ft);
	std::cout << "                         EMPTY" << std::endl;
	emptyTestQueue(std, ft);
	emptyTestQueueFloat(std, ft);
	emptyTestQueueStr(std, ft);
	std::cout << "                         SIZE" << std::endl;
	sizeTestQueue(std, ft);
	sizeTestQueueFloat(std, ft);
	sizeTestQueueStr(std, ft);
	std::cout << "                         FRONT" << std::endl;
	frontTestQueue(std, ft);
	frontTestQueueFloat(std, ft);
	frontTestQueueStr(std, ft);
	std::cout << "                         BACK" << std::endl;
	backTestQueue(std, ft);
	backTestQueueFloat(std, ft);
	backTestQueueStr(std, ft);
	std::cout << "                         PUSH" << std::endl;
	pushTestQueue(std, ft);
	pushTestQueueFloat(std, ft);
	pushTestQueueStr(std, ft);
	std::cout << "                         POP" << std::endl;
	popTestQueue(std, ft);
	popTestQueueFloat(std, ft);
	popTestQueueStr(std, ft);
	std::cout << "                         NON MEMBER FUNCTIONS OVERLOADS" << std::endl;
	equalTestQueue(std, ft);
	equalTestQueueFloat(std, ft);
	equalTestQueueStr(std, ft);
	nonEqualTestQueue(std, ft);
	nonEqualTestQueueFloat(std, ft);
	nonEqualTestQueueStr(std, ft);
	lessTestQueue(std, ft);
	lessTestQueueFloat(std, ft);
	lessTestQueueStr(std, ft);
	lessOrEqualTestQueue(std, ft);
	lessOrEqualTestQueueFloat(std, ft);
	lessOrEqualTestQueueStr(std, ft);
	greaterTestQueue(std, ft);
	greaterTestQueueFloat(std, ft);
	greaterTestQueueStr(std, ft);
	greaterOrEqualTestQueue(std, ft);
	greaterOrEqualTestQueueFloat(std, ft);
	greaterOrEqualTestQueueStr(std, ft);
};

int main(){
	testQueue();
	return (0);
}