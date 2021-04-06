#include <vector>
#include <iostream>
#include "vector.hpp"
#include "list.hpp"
#include <list>

int main(){
	{
		std::cout << "my \n";
		ft::vector<int> a;
		for (int i = 0; i < 7; i++) {
			a.push_back(i + 10);
		}

		ft::vector<int>::iterator it = a.begin();
		ft::vector<int>::iterator ite = a.end();
		it += 3;
		ite -= 2;
		a.insert(it,2 , 25);
		std::cout << "size = " << a.size() << "cap = " << a.capacity() << std::endl;
		it = a.begin();
		ite = a.end();


		int i = 0;
		while (it != ite) {
			std::cout << *it << std::endl;
			it++;
		}
	}
	{
		std::cout << "std \n";
		std::vector<int> a1;
		for (int i = 0; i < 7; i++) {
			a1.push_back(i + 10);
		}

		std::vector<int>::iterator it1 = a1.begin();
		std::vector<int>::iterator ite1 = a1.end();

		it1 += 3;
		ite1 -=2;
		a1.insert(it1, 2,  25);
		std::cout << "size = " << a1.size() << "cap = " << a1.capacity() << std::endl;
		it1 = a1.begin();
		ite1 = a1.end();


		int i1 = 0;
		while (it1 != ite1) {
			std::cout << *it1 << std::endl;
			it1++;
		}
	}
}