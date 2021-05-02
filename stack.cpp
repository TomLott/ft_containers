#include "stack.hpp"
#include "utils.hpp"
#include <list>
#include <string>
#include <stack>


template <typename T>
void stackPushElem(std::stack<T> &std, ft::stack<T> &ft, unsigned long number) {
	T i;
	for (unsigned long l = 0; l < number; l++) {
		i = rand();
		std.push(i);
		ft.push(i);
	}
}

template <typename T>
void fillStrStack(std::stack<T> &def, ft::stack<T> &my, std::string &std, std::string &ft) {
	std += def.top();
	ft += my.top();
	std += def.size();
	ft += my.size();
}

//MARK: - Default constructor stack

void defaultCnstTestStack(std::string &std, std::string &ft) {
	std::cout << "Default constructor int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Default constructor float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void defaultCnstTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Default constructor std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Empty stack

void emptyTestStack(std::string &std, std::string &ft) {
	std::cout << "Empty int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Empty float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void emptyTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Empty std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std += def.empty();
	ft += my.empty();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Size stack

void sizeTestStack(std::string &std, std::string &ft) {
	std::cout << "Size int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 20);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Size float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 20);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void sizeTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 10);
	std += def.size();
	ft += my.size();
	stackPushElem(def, my, 20);
	std += def.size();
	ft += my.size();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Top stack

void topTestStack(std::string &std, std::string &ft) {
	std::cout << "Top int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	stackPushElem(def, my, 10);
	std += def.top();
	ft += my.top();
	stackPushElem(def, my, 20);
	std += def.top();
	ft += my.top();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void topTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Top float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	stackPushElem(def, my, 10);
	std += def.top();
	ft += my.top();
	stackPushElem(def, my, 20);
	std += def.top();
	ft += my.top();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void topTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Size std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	stackPushElem(def, my, 10);
	std += def.top();
	ft += my.top();
	stackPushElem(def, my, 20);
	std += def.top();
	ft += my.top();
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Push stack

void pushTestStack(std::string &std, std::string &ft) {
	std::cout << "Push int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	stackPushElem(def, my, 1);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 20);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestQueueStack(std::string &std, std::string &ft) {
	std::cout << "Push float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	stackPushElem(def, my, 1);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 20);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void pushTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Push std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	stackPushElem(def, my, 1);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 20);
	fillStrStack(def, my, std, ft);
	stackPushElem(def, my, 17);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Pop stack

void popTestStack(std::string &std, std::string &ft) {
	std::cout << "Pop int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Pop float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

void popTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Pop std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	stackPushElem(def, my, 10);
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	def.pop();
	my.pop();
	fillStrStack(def, my, std, ft);
	if (std == ft)
		std::cout << "\033[1;32m[OK]\033[0;0m" << std::endl;
	else
		std::cout << "\033[1;31m[FAIL]\033[0;0m" << std::endl;
	std.clear();
	ft.clear();
}

//MARK: - Non member Queue

void equalTestStack(std::string &std, std::string &ft) {
	std::cout << "Equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void equalTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void equalTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void nonEqualTestStack(std::string &std, std::string &ft) {
	std::cout << "Non equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void nonEqualTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Non equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void nonEqualTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Non equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void lessTestStack(std::string &std, std::string &ft) {
	std::cout << "Less int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void lessTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Less float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void lessTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Less std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void lessOrEqualTestStack(std::string &std, std::string &ft) {
	std::cout << "Less or equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void lessOrEqualTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Less or equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void lessOrEqualTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Less or equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void greaterTestStack(std::string &std, std::string &ft) {
	std::cout << "Greater int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void greaterTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Greater float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void greaterTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Greater std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void greaterOrEqualTestStack(std::string &std, std::string &ft) {
	std::cout << "Greater or equal int test" << " ";
	std::stack<int> def;
	ft::stack<int> my;
	std::stack<int> def1;
	ft::stack<int> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void greaterOrEqualTestStackFloat(std::string &std, std::string &ft) {
	std::cout << "Greater or equal float test" << " ";
	std::stack<float> def;
	ft::stack<float> my;
	std::stack<float> def1;
	ft::stack<float> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

void greaterOrEqualTestStackStr(std::string &std, std::string &ft) {
	std::cout << "Greater or equal std::string test" << " ";
	std::stack<std::string> def;
	ft::stack<std::string> my;
	std::stack<std::string> def1;
	ft::stack<std::string> my1;
	stackPushElem(def, my, 100);
	stackPushElem(def1, my1, 50);
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

//MARK: - Stack

void testStack() {
	//MARK: - Constructor
	std::cout << "                         CONSTRUCTOR" << std::endl;
	std::string std;
	std::string ft;
	defaultCnstTestStack(std, ft);
	defaultCnstTestStackFloat(std, ft);
	defaultCnstTestStackStr(std, ft);
	std::cout << "                         EMPTY" << std::endl;
	emptyTestStack(std, ft);
	emptyTestStackFloat(std, ft);
	emptyTestStackStr(std, ft);
	std::cout << "                         SIZE" << std::endl;
	sizeTestStack(std, ft);
	sizeTestStackFloat(std, ft);
	sizeTestStackStr(std, ft);
	std::cout << "                         TOP" << std::endl;
	topTestStack(std, ft);
	topTestStackFloat(std, ft);
	topTestStackStr(std, ft);
	std::cout << "                         POP" << std::endl;
	popTestStack(std, ft);
	popTestStackFloat(std, ft);
	popTestStackStr(std, ft);
	std::cout << "                         NON MEMBER FUNCTIONS OVERLOADS" << std::endl;
	equalTestStack(std, ft);
	equalTestStackFloat(std, ft);
	equalTestStackStr(std, ft);
	nonEqualTestStack(std, ft);
	nonEqualTestStackFloat(std, ft);
	nonEqualTestStackStr(std, ft);
	lessTestStack(std, ft);
	lessTestStackFloat(std, ft);
	lessTestStackStr(std, ft);
	lessOrEqualTestStack(std, ft);
	lessOrEqualTestStackFloat(std, ft);
	lessOrEqualTestStackStr(std, ft);
	greaterTestStack(std, ft);
	greaterTestStackFloat(std, ft);
	greaterTestStackStr(std, ft);
	greaterOrEqualTestStack(std, ft);
	greaterOrEqualTestStackFloat(std, ft);
	greaterOrEqualTestStackStr(std, ft);
};

int main(){
	testStack();
	return 0;
}