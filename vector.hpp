#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"

template<class T, class Alloc>
	class ft::vector {

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;


	private:
		size_type _size;
		size_type _cap;
		pointer _arr;
		allocator_type _alloc;
		pointer createVector(const_reference val) {
			pointer newArr = _alloc.allocate(_cap);
			for (size_t i = 0; i < _size; i++) {
				_alloc.construct((newArr + i), val);
			}
			return (newArr);
		}

	public:

		explicit vector(const allocator_type &alloc = allocator_type()) : _size(
				0), _cap(0), _arr(nullptr), _alloc(alloc) {
		}

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type()) : _size(
				n), _alloc(alloc), _cap(n) {
			if (n < 0)
				throw std::length_error("vector");
			_arr = createVector(val);
		}



		template<class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _alloc(alloc),
																 _size(0),
																 _cap(0),
																 _arr(nullptr)
																 {
			ptrdiff_t len = last.operator->() - first.operator->();
			if (len < 0)
				throw std::length_error("vector");
			_size = static_cast<size_type> (len);
			_cap = _size;
			_arr = _alloc.allocate(_cap);
			for (size_type i = 0; i < _size; ++i){
				_alloc.construct(_arr + i, *first);
				first++;
			}
		}

		vector(const vector &x) {
			if (this != &x) {
				this->_cap = x._size;
				this->_size = x._size;
				this->_alloc = x._alloc;
				this->_arr = _alloc.allocate(_cap);
				for (int i = 0; i < _size; ++i) {
					_alloc.construct((_arr + i), *(x._arr + i));
				}
			}
		}
		void clear() {
			for (size_t i = 0; i < _size; i++) {
				_alloc.destroy(_arr + i);
			}
			_size = 0;
		}

		virtual ~vector() {
			if (_arr)
				clear();
				_alloc.deallocate(_arr, _cap);
		}



		vector & operator = (vector const & src){
			if (this != &src){
				clear();
				_alloc.deallocate(_arr, _cap);
				this->_cap = src._size;
				this->_size = src._size;
				this->_alloc = src._alloc;
				this->_arr = _alloc.allocate(_cap);
				for (size_t i = 0; i < src._size; i++){
					_alloc.construct(_arr + i, *(src._arr + i));
				}
			}
			return (*this);
		}

		void push_back(const value_type &val) {
			if (_cap == 0){
				_arr = _alloc.allocate(1);
				_cap = 1;
				_size = 1;
				_alloc.construct(_arr, val);
			}
			else
				insert(end(), val);
		}

		void pop_back(){ _alloc.destroy(_arr + (--_size));}


		/*Iterators*/

		class iterator : public ft::iterator<std::random_access_iterator_tag, value_type> {
		private:
			pointer _it;
		public:
			explicit iterator(pointer it = 0) : _it(it) {};

			~iterator() {};

			iterator(iterator const &src) {
				if (this != &src) {
					_it = src._it;
				}
			}

			/*operators*/
			iterator &operator=(const iterator &src) {
				if (this != &src) {
					_it = src._it;
				}
				return (*this);
			}

			iterator &operator++() {
				_it = _it + 1;
				return (*this);
			};

			iterator operator++(int) {
				iterator oldValue = *this;
				_it = _it + 1;
				return (oldValue);
			}

			iterator &operator--() {
				_it = _it - 1;
				return ((*this));
			}

			iterator operator--(int) {
				iterator oldValue = *this;
				_it = _it - 1;
				return (oldValue);
			}
			iterator base() const {return _it;}

			iterator operator+(difference_type i)  const{return (iterator(_it + i));}
			difference_type operator+(iterator &i) {return (_it + i._it);	}
			iterator operator-(difference_type i) const {return (iterator(_it - i));}
			difference_type operator-(iterator &i) {return (_it - i._it);	}
			iterator &operator+=(difference_type i) {_it = _it + i;	return (*this);}
			iterator &operator-=(difference_type i) {_it = _it - i;	return (*this);	}
			reference operator[](difference_type val) const { return (_it[val]); }
			reference operator*() const { return (*_it); }
			pointer operator->() const { return (_it); }
			bool operator==(iterator const & src){	return (_it == src._it);}
			bool operator!=(iterator const & src){	return (_it != src._it);}
			bool operator<(iterator const & src){	return (_it < src._it);	}
			bool operator>(iterator const & src){	return (_it > src._it);	}
			bool operator>=(iterator const & src){	return (_it >= src._it);}
			bool operator<=(iterator const & src){  return (_it <= src._it);}

			pointer getElement() const {return (_it);}

		};
		class const_iterator : public ft::iterator<std::random_access_iterator_tag, value_type>{
		private:
			pointer _it;
			const_iterator() : _it(nullptr){};
		public:
			explicit const_iterator(pointer it) : _it(it) {};
			~const_iterator(){};
			const_iterator & operator =( iterator const &src){
				if (this != &src){
					_it = src._it;
				}
				return (*this);
			}

			const_iterator & operator = (const_iterator const &src){
				if (this != &src){
					_it = src._it;
				}
				return (*this);
			}



			const_iterator(const_iterator const & src){
				*this = src;
			}
			const_iterator(iterator const & src){
				*this = src;
			}

			const_iterator operator++(int){
				const_iterator oldValue(_it);
				_it = _it + 1;
				return (oldValue);
			}
			const_iterator & operator++(){ _it = _it + 1; return (*this);}

			const_iterator operator--(int){
				const_iterator oldValue(_it);
				_it = _it - 1;
				return (oldValue);
			}

			const_iterator & operator--(){ _it = _it - 1; return (*this);}

			const_iterator operator+(difference_type n) const{ return const_iterator(_it + n);}
			const_iterator operator-(difference_type n) const{ return const_iterator(_it - n);}

			difference_type operator+(const_iterator &i) {return (_it + i._it);	}
			difference_type operator-(const_iterator &i) {return (_it - i._it);	}
			const_iterator & operator += (difference_type n){
				_it = _it + n;
				return (*this);
			}
			const_iterator & operator -= (difference_type n){
				_it = _it - n;
				return (*this);
			}

			const_reference operator[] (difference_type n) const {
				return (*(_it + n));
			}

			const_reference operator* () const{
				return (*_it);
			}

			const_pointer operator->() const{
				return (_it);
			}

			bool operator==(const_iterator const & src){return (_it == src._it);}
			bool operator!=(const_iterator const & src){return (_it != src._it);}
			bool operator<(const_iterator const & src){	return (_it < src._it);}
			bool operator>(const_iterator const & src){	return (_it > src._it);}
			bool operator>=(const_iterator const & src){return (_it >= src._it);}
			bool operator<=(const_iterator const & src){return (_it <= src._it);}

			bool operator==(iterator const & src){return (_it == src._it);}
			bool operator!=(iterator const & src){return (_it != src._it);}
			bool operator<(iterator const & src){	return (_it < src._it);}
			bool operator>(iterator const & src){	return (_it > src._it);}
			bool operator>=(iterator const & src){return (_it >= src._it);}
			bool operator<=(iterator const & src){return (_it <= src._it);}


			const_pointer getElement() const {return (_it);}

};
		class reverse_iterator : public ft::iterator<std::random_access_iterator_tag, value_type>{
		private:
			pointer _it;
			reverse_iterator() : _it(0){};
		public:
			explicit reverse_iterator(pointer it = 0) : _it(it) {};
			~reverse_iterator(){};
			reverse_iterator(reverse_iterator const & src){
				if (this != &src){
					_it = src._it;
				}
			}

			reverse_iterator & operator = (reverse_iterator const & src){
				if (this != &src){
					_it = src._it;
				}
				return (*this);
			}

			reverse_iterator operator++(int){
				reverse_iterator oldValue = *this;
				_it = _it - 1;
				return (oldValue);
			}

			reverse_iterator & operator++() const{
				_it = _it - 1;
				return (*this);
			}

			reverse_iterator operator--(int){
				reverse_iterator oldValue = *this;
				_it = _it + 1;
				return (oldValue);
			}

			reverse_iterator & operator--() const{
				_it = _it + 1;
				return (*this);
			}

			reverse_iterator operator+(difference_type n) const{ return const_iterator(_it - n);}
			reverse_iterator operator-(difference_type n) const{ return const_iterator(_it + n);}
			difference_type operator+(reverse_iterator &i) {return (_it - i._it);	}
			difference_type operator-(reverse_iterator &i) {return (_it + i._it);	}

			reverse_iterator operator += (difference_type n){ return (_it -= n);}
			reverse_iterator operator -= (difference_type n){ return (_it += n);}

			reference operator[] (difference_type n) const {return (*(_it + n));}

			reference operator* () const{return (*_it);}

			pointer operator->() const{return (_it);}

			bool operator==(reverse_iterator const & src){return (_it == src._it);}
			bool operator!=(reverse_iterator const & src){return (_it != src._it);	}
			bool operator<(reverse_iterator const & src){return (_it > src._it); }
			bool operator>(reverse_iterator const & src){return (_it < src._it);}
			bool operator>=(reverse_iterator const & src){	return (_it <= src._it);}
			bool operator<=(reverse_iterator const & src){	return (_it >= src._it);}

			const_pointer getElement() const {return (_it);}

		};
		class const_reverse_iterator : public ft::iterator<std::random_access_iterator_tag, value_type> {
		private:
			pointer _it;
			const_reverse_iterator() : _it(0) {};
		public:
			explicit const_reverse_iterator(pointer it) : _it(it){};
			~const_reverse_iterator(){}
			const_reverse_iterator(const_reverse_iterator & src){
				if (this != &src){
					_it = src.getElement();
				}
			}
			const_reverse_iterator(const reverse_iterator & src){
				if (this != &src){
					_it = src.getElement();
				}
			}

			const_reverse_iterator & operator = (const_reverse_iterator const & src){
				if (this != &src){
					_it = src.getElement();
				}
			}

			const_reverse_iterator & operator = (const reverse_iterator & src){
				if (this != &src){
					_it = src.getElement();
				}
			}

			const_reverse_iterator operator ++(int){
				const_reverse_iterator oldValue(_it);
				_it = _it - 1;
				return (oldValue);
			}

			const_reverse_iterator & operator ++(){
				_it = _it - 1;
				return (*this);
			}

			const_reverse_iterator & operator --(int){
				const_reverse_iterator oldValue(_it);
				_it = _it + 1;
				return (oldValue);
			}

			const_reverse_iterator & operator --(){
				_it = _it + 1;
				return (*this);
			}
			difference_type operator+(const_reverse_iterator &i) {return (_it - i._it);	}
			difference_type operator-(const_reverse_iterator &i) {return (_it + i._it);	}
			const_reverse_iterator & operator + (difference_type n) const{	return (const_reverse_iterator(_it - n));}
			const_reverse_iterator & operator - (difference_type n) const{	return (const_reverse_iterator(_it + n));}
			const_reverse_iterator & operator += (difference_type n) const{	_it = _it - n;	return (*this);	}
			const_reverse_iterator & operator -= (difference_type n) const{	_it = _it + n;	return (*this);	}
			const_reference operator [] (difference_type n) const{	return (*(_it + n));}
			const_reference operator *() const{	return (*_it);	}
			const_pointer operator-> () const{	return (_it);}

			bool operator == (const const_reverse_iterator & src) const{ return (_it == src._it);};
			bool operator != (const const_reverse_iterator & src) const{ return (_it != src._it);};
			bool operator <= (const const_reverse_iterator & src) const{ return (_it >= src._it);};
			bool operator >= (const const_reverse_iterator & src) const{ return (_it <= src._it);};
			bool operator > (const const_reverse_iterator & src) const{ return (_it < src._it);};
			bool operator < (const const_reverse_iterator & src) const{ return (_it > src._it);};


			bool operator == (const reverse_iterator & src) const{ return (_it == src.getElement());};
			bool operator != (const reverse_iterator & src) const{ return (_it != src.getElement());};
			bool operator <= (const reverse_iterator & src) const{ return (_it >= src.getElement());};
			bool operator <(const reverse_iterator & src) const{ return (_it > src.getElement());};
			bool operator >= (const reverse_iterator & src) const{ return (_it <= src.getElement());};
			bool operator > (const reverse_iterator & src) const{ return (_it < src.getElement());};





			pointer getElement() const {return (_it);}
	};

		iterator begin() { return iterator(_arr);}
		const_iterator begin() const { return const_iterator(_arr);}
		iterator end() { return iterator(_arr + _size);}
		const_iterator end () const { return  const_iterator(_arr + _size);}

		reverse_iterator rbegin() { return reverse_iterator(_arr + _size - 1);}
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_arr + _size - 1);}
		reverse_iterator rend() { return  reverse_iterator(_arr - 1);}
		const_reverse_iterator rend() const { return const_reverse_iterator(_arr - 1);}

		const_iterator cbegin() const {return const_iterator(_arr);}
		const_iterator cend() const{ return const_iterator(_arr + _size);}

		const_reverse_iterator crbegin() {return const_reverse_iterator(_arr + _size - 1);}
		const_reverse_iterator crend() const{ return const_reverse_iterator(_arr - 1);}

		///vectors functions

		size_type size() const{ return (_size);}
		size_type max_size() const {return (size_type(~0) / sizeof(value_type));}

		void resize(size_type n, value_type val = value_type()){
			if (n > max_size())
				throw std::length_error("'n' is more than max_size");
			if (n < _size){
				for (size_type i = _size - n; i < n; i++)
					_alloc.destroy(_arr + i);
			}
			else if (n > _size){
				reserve(n);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_arr + i, val);
			}
			_size = n;
		}

		size_type capacity() const{	return (_cap);}
		bool empty() const{ return (_size == 0);}
		void reserve (size_type n){
			if (_cap < n){
				pointer newArr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++){
					_alloc.construct(newArr + i, *(_arr + i));
				}
				for (size_type i = 0; i < _size; i++){
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _cap);
				_arr = newArr;
				_cap = n;
			}
		}

		reference operator [] (size_type n){ return (_arr[n]);}

		const_reference operator [] (size_type n) const{ return (_arr[n]);}

		reference at(size_type n){
			if (n >= _size || n < 0){
				throw std::out_of_range("vector");
			}
			return (_arr[n]);
		}
		const_reference at(size_type n) const{
			if (n >= _size || n < 0){
				throw std::out_of_range("vector");
			}
			return (_arr[n]);
		}

		reference front(){ return (*_arr);}
		const_reference front() const{ return (*_arr);}

		reference back(){ return (*(_arr + _size - 1));}
		const_reference back() const{ return (*(_arr + _size - 1));}

		template<class InputIterator>
				void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
			clear();
			ptrdiff_t  len = last.operator->() - first.operator->();
			if (len > _cap)
				reserve(len);
			for (ptrdiff_t i = 0; i < len; i++){
				_alloc.construct(_arr + i, *first);
				first++;
			}
			_size = static_cast<size_t>(len);
		}

		void assign(size_type n, const value_type & val){
			if (n < 0)
				throw std::length_error("vector");
			clear();
			insert(this->begin(), n, val);
		}

		iterator insert(iterator position, const value_type & val){
			if (_cap == 0){
				_cap = 1;
				_size = 1;
				_arr = _alloc.allocate(1);
				_alloc.construct(_arr, val);
				return iterator(_arr);
			}
			pointer newArr = 0;
			size_type newPos = position.operator->() - _arr;
			size_type newCap;
			if (_size + 1 > _cap)
				newCap = _cap * 2;
			else
				newCap = _cap;
			newArr = _alloc.allocate(newCap);
			size_type i = 0;
			for (; i < newPos; ++i){
				_alloc.construct(newArr + i, *(_arr + i));
			}
			_alloc.construct(newArr + newPos, val);
			i++;
			for (; i < _size + 1; ++i){
				_alloc.construct(newArr + i, *(_arr + i - 1));
			}
			for (size_type k = 0; k < _size; ++k)
				_alloc.destroy(_arr + k);
			_alloc.deallocate(_arr, _cap);
			_arr = newArr;
			_cap = newCap;
			_size++;
			return (iterator(_arr + newPos));
		}

		void insert(iterator position, size_type n, const value_type & val){
			if (_cap == 0){
				_cap = n;
				_size = n;
				_arr= _alloc.allocate(n);
				for (size_type i = 0; i < n; i++){
					_alloc.construct((_arr + i), val);
				}
				return ;
			}
			pointer newArr = 0;
			size_type newPos = position.operator->() - _arr;
			size_type newCap;
			if (_size + n > _cap)
				newCap = (_size + n) * 2;
			else
				newCap = _cap;
			newArr = _alloc.allocate(newCap);
			size_type i = 0;
			for (; i < newPos; i++){
				_alloc.construct(newArr + i, *(_arr + i));
			}
			size_type j = 0;
			for (; j < n; ++j, ++i){
				_alloc.construct(newArr + j + newPos, val);
			}
			for (; i < _size + n + 1; ++i){
				_alloc.construct(newArr + i, *(_arr + i - n));
			}
			j = 0;
			for (; j < _size; ++j){
				_alloc.destroy(_arr + j);
			}
			_alloc.deallocate(_arr, _cap);
			_arr = newArr;
			_cap = newCap;
			_size = _size + n;
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first,InputIterator last,
		typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
			ptrdiff_t len = last - first;
			if (_cap == 0){
				_size = len;
				_cap = len;
				_arr = _alloc.allocate(len);
				for (ptrdiff_t i = 0; i < len; i++){
					_alloc.construct(_arr + i, *first);
					first++;
				}
				return ;
			}
			size_type newPos = position.operator->() - _arr;
			size_type newCap;
			if (_size + len > _cap){
				newCap = (_size + len) * 2;
			}
			else
				newCap = _cap;
			pointer newArr = _alloc.allocate(newCap);
			size_type i = 0;
			for (; i < newPos; i++){
				_alloc.construct(newArr + i, *(_arr + i));
			}
			for (ptrdiff_t j = 0; j < len; ++j,++i){
				_alloc.construct(newArr + len + j, *first);
				first++;
			}
			for (; i < _size + len + 1; ++i){
				_alloc.construct(newArr + i, *(_arr + i - len));
			}
			for (size_t k = 0; k < _size; ++k){
				_alloc.destroy(_arr + k);
			}
			_alloc.deallocate(_arr, _cap);
			_arr = newArr;
			_cap = newCap;
			_size = _size + len;
		}

		iterator erase(iterator position){
			size_type newPos = position.getElement() - _arr;
			for (; newPos < _size; newPos++){
				_alloc.destroy(_arr + newPos);
				if (newPos + 1 < _size)
					_alloc.construct(_arr + newPos, *(_arr + newPos + 1));
			}
			_size--;
			_alloc.destroy(_arr + (_size - 1));
			return (iterator(position.getElement()));
		}

		iterator erase(iterator first, iterator last){
			for (; first != last;){
				erase(--last);
			}
			return (iterator(last));
		}

		void swap(vector& x) {
			size_type size = this->_size;
			this->_size = x._size;
			x._size = size;

			allocator_type alloc = this->_alloc;
			this->_alloc = x._alloc;
			x._alloc = alloc;

			size_type cap = this->_cap;
			this->_cap = x._cap;
			x._cap = cap;

			pointer arr = this->_arr;
			this->_arr = x._arr;
			x._arr = arr;
		}

		allocator_type get_allocator() const{
			return _alloc;
		}
	};
	namespace ft {
		template<class T, class Alloc>
		void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y) {
			x.swap(y);
		}

		template<class T, class Alloc>
		bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			return  ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		template <class T, class Alloc>
		bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
			if (lhs.size() == rhs.size())
				return (false);
			return (!(ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
		}

		template <class T, class Alloc>
		bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
			if (lhs == rhs)
				return (false);
			return (compare_elements(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return (lhs > rhs || lhs == rhs);
		}

		template <class T, class Alloc>
		bool operator >  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
			if (lhs == rhs)
				return (false);
			return !(compare_elements(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return (lhs < rhs || lhs == rhs) ;
		}


	}

#endif
