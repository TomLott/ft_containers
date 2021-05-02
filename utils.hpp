#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <iostream>
#include <utility>

namespace ft
{
	template<class T, class Alloc = std::allocator <T> >
		class vector;
	template<class T, class Alloc = std::allocator <T> >
		class list;
	template<class T, class Container = ft::list<T>  >
		class queue;
	template<class T, class Container = ft::list<T>  >
		class stack;
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
			class map;


	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator1, class Iterator2>
	bool equal (Iterator1 it1, Iterator1 ite1, Iterator2 it2){
		for (; it1 != ite1; ++it1, ++it2){
			if (*it1 != *it2)
				return (false);
		}
		return (true);
	}

	template <class Iterator1, class Iterator2>
	bool compare_elements(Iterator1 it1, Iterator1 ite1, Iterator2 it2, Iterator2 ite2){
		for (; it1 != ite1; ++it1, ++it2) {
			if (*it2 == *ite2)
				return (false);
			if (*it1 < *it2) {
				return (true);
			}
			else
				return false;
		}
		return (true);
	}

	template <typename U>
	void swap(U & x, U & y){
		U z(x);
		x = y;
		y = z;
	}

	template <class T, class Alloc>
	bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator < (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator >  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	void swap(ft::list<T,Alloc> & x, ft::list<T, Alloc> & y);


	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);


	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);



}






#endif


