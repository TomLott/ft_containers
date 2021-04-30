#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "utils.hpp"
#include "list.hpp"

template <class T, class Container>
class ft::queue{
public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t 		size_type;

private:
	container_type c;
public:
		explicit queue (const container_type & ctnr = container_type()){
			c = ctnr;
		}

		bool empty() const{
			return (this->c.empty());
		}

		value_type & back(){
			return (this->c.back());
		}

		const value_type & back() const{
			return (this->c.back());
		}

		value_type & front(){
			return (this->c.front());
		}

		const value_type & front() const {
			return (this->c.front());
		}

		void pop(){
			this->c.pop_front();
		}

		void push(const value_type & val){
			this->c.push_back(val);
		}

		size_type size() const{
			return (this->c.size());
		}

	container_type getC() const{ return c;}
};

namespace ft{
	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return (lhs.getC() == rhs.getC());
	}

	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return (lhs.getC() != rhs.getC());
	}

	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return (lhs.getC() < rhs.getC());
	}

	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return (lhs.getC() <= rhs.getC());
	}

	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return (lhs.getC() > rhs.getC());
	}

	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return (lhs.getC() >= rhs.getC());
	}
}


#endif
