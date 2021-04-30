#ifndef STACK_HPP
#define STACK_HPP

#include "utils.hpp"
#include "list.hpp"

template <class T, class Container>
class ft::stack{
public:
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t 		size_type;

private:
	container_type c;
public:

	explicit  stack (const container_type& ctnr = container_type()){
		c = ctnr;
	}

	bool empty() const{
		return (this->c.empty());
	}

	void pop(){
		this->c.pop_back();
	}

	void push(const value_type & val){
		this->c.push_back(val);
	}

	size_type size() const{
		return (this->c.size());
	}

	value_type & top(){
		return (this->c.back());
	}

	const value_type & top() const{
		return (this->c.back());
	}

	container_type getC() const{
		return c;
	}
};
	template <class T, class Container>
	bool ft::operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.getC() == rhs.getC());
	}

	template <class T, class Container>
	bool ft::operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.getC() != rhs.getC());
	}

	template <class T, class Container>
	bool ft::operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.getC() < rhs.getC());
	}

	template <class T, class Container>
	bool ft::operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.getC() <= rhs.getC());
	}

	template <class T, class Container>
	bool ft::operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.getC() > rhs.getC());
	}

	template <class T, class Container>
	bool ft::operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs.getC() >= rhs.getC());
	}



#endif
