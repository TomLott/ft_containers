#ifndef LIST_HPP
#define LIST_HPP

#include "utils.hpp"

template <class T, class Alloc>
class ft::list{

public:
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference	reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;

	typedef ptrdiff_t 	difference_type;
	typedef size_t 		size_type;

private:
	struct Node {
		value_type *content;
		Node * next;
		Node * prev;
	};

	typedef typename allocator_type::template rebind <Node>::other allocator_rebind_type;

	size_type 					_size;
	allocator_type 				_alloc;
	allocator_rebind_type 		_alloc_rebind;
	Node *						_last;

	void create_list(){
		_size = 0;
		this->_last = _alloc_rebind.allocate(1);
		this->_last->content = _alloc.allocate(1);
		this->_last->next = _last;
		this->_last->prev = _last;
	}

	Node * create_node(const value_type & val){
		Node *newNode = _alloc_rebind.allocate(1);
		newNode->content = _alloc.allocate(1);
		_alloc.construct(newNode->content, val);
		_size++;
		return (newNode);
	}

	void destroy_node(Node * node){
		_alloc.destroy(node->content);
		_alloc.deallocate(node->content, 1);
		_alloc_rebind.deallocate(node, 1);
		_size--;
	}

	void insert_node(Node *node, Node * next, Node * prev){
		link_node(node, next);
		link_node(prev, node);
	}

	void link_node(Node *first, Node *last){
		first->next = last;
		last->prev = first;
	}

	void link_node(Node *newNode, Node * start, Node * last){
		newNode->prev->next = start;
		start->prev = newNode->prev;
		newNode->prev = last;
		last->next = newNode;
	}

	void unlink_nodes(Node * start, Node * end){
		start->prev->next = end->next;
		end->next->prev = start->prev;
	}

	size_type list_size(){
		size_type len = 0;
		iterator it = begin();
		iterator ite = end();
		for (;it != ite; ++it){
			len++;
		}
		return (len);
	}

	size_type distance(iterator first, iterator last){
		size_type i = 0;
		while (first != last){
			first++;
			i++;
		}
		return (i);
	}

	Node * _split_list(Node * f, Node * l){

		if (f->next == _last || f->next->next == _last){
			Node * temp = l->next;
			link_node(l, _last);
			return (temp);
		}
		return (_split_list(f->next->next, l->next));
	}

	template<class Compare>
	Node * mergeL(Node * f, Node * l, Compare comp){
		if (f == _last)
			return (l);
		if (l == _last)
			return (f);
		if (!comp(*l->content, *f->content)){
			f->next = mergeL(f->next, l, comp);
			f->next->prev = f;
			link_node(_last, f);
			return (f);
		}
		else{
			l->next = mergeL(f, l->next, comp);
			l->next->prev = l;
			link_node(_last, l);
			return (l);
		}

	}

	template<class Compare>
	Node * _merge_sort(Node * node, Compare comp){
		if (_last == node || _last == node->next)
			return (node);
		Node * temp = _split_list(node, node);

		return (mergeL(_merge_sort(node, comp), _merge_sort(temp, comp), comp));
	}


	static bool nonComp(const value_type & f, const value_type & l){return (f < l);}

public:


	explicit list(const allocator_type & alloc = allocator_type()){
		_alloc = alloc;
		_size = 0;
		create_list();
	}

	explicit list (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()){
		_alloc = alloc;
		_size = n;
		create_list();
		for (size_t i = 0; i < n; i++)
			this->push_back(val);
	}


	template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
					typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _alloc(alloc){
		create_list();
		for (;first != last; first++)
			this->push_back(*first);
	}

	list (const list & x) {
		_alloc = x._alloc;
		_size = x._size;
		create_list();
		*this = x;
	}

	list & operator = (list const & src){
		if (!empty())
			clear();
		iterator it = src.begin();
		iterator ite = src.end();
		for (; it != ite; it++){
			push_back(*it);
		}
		return (*this);
	}


	~list(){
		clear();
		_alloc.deallocate(_last->content, 1);
		_alloc_rebind.deallocate(_last, 1);
	}

	void clear(){
		while (_size > 0)
			pop_back();
	}

	bool empty() const{	return (!(_size));}
	size_t size()const{ return (_size);}
	size_type max_size() const{ return std::numeric_limits<size_type >::max()/sizeof(Node);} /// make right here
	allocator_type get_allocator() const{ return _alloc;}

	iterator begin() { return iterator(this->_last->next);}
	const_iterator begin() const { return const_iterator(_last->next);}
	iterator end() {return iterator(_last);}
	const_iterator end() const {return const_iterator(_last);}

	reverse_iterator rbegin() { return reverse_iterator(this->_last->prev);}
	const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_last->prev);}

	reverse_iterator rend() { return reverse_iterator(this->_last);}
	const_reverse_iterator rend() const { return const_reverse_iterator (this->_last);}

	reference back(){ return *(_last->prev->content);}
	const_reference back() const{ return *(_last->prev->content);}
	reference front() { return *(_last->next->content);}
	const_reference front() const{ return *(_last->next->content);}

	iterator erase (iterator position){
		Node * node = position.getIt();
		iterator it(node->next);
		node->prev->next = position.getIt()->next;
		node->next->prev = position.getIt()->prev;
		destroy_node(node);
		return (it);
	}

	iterator erase(iterator first, iterator last){
		for (; first != last; ++first){
			erase(first);
		}
		return (iterator(last));
	}


	template <class InputIterator>

			void assign(InputIterator first, InputIterator last, typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
		clear();
		for (;first != last;first++){
			push_back(*first);
		}
	};
	void assign(size_t n, const value_type & val){
		clear();
		for (size_t i = 0; i < n; i++){
			push_back(val);
		}
	}

	void push_back(const value_type & val){
		insert_node(create_node(val), _last, _last->prev);
	}

	void push_front(const value_type & val){
		insert_node(create_node(val), _last->next, _last);
	}
	void pop_back(){
		Node *node = _last->prev;
		link_node(node->prev, node->next);
		destroy_node(node);
	}

	void pop_front(){
		Node * node = _last->next;
		link_node(node->prev, node->next);
		destroy_node(node);
	}

	iterator insert(iterator position, const value_type & val){
		Node * temp = position.getIt();
		Node * newNode = create_node(val);
		link_node(temp, newNode, newNode);
		//_size++;
		return (iterator(position));
	}

	void insert(iterator position, size_type n, const value_type & val){
		for (size_type i = 0; i < n; ++i){
			insert(position, val);
		}
	}

	template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
			   typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
		for (; first != last; first++){
			insert(position, *first);
		}
	}

	void merge(list & x){
		merge(x, nonComp);

	}

	template<class Compare>
			void merge(list & x, Compare comp){
		iterator it = begin();
		iterator ite = end();
		iterator xIt = x.begin();
		iterator xIte = x.end();
		while (it != ite && xIt != xIte){
			if (comp(*xIt, *it)){
				size_type len = 1;
				iterator temp2 = ++xIt;
				xIt--;
				for (; temp2 != xIte && comp(*temp2, *it);){
					++temp2; len++;
				}
				_size += len;
				x._size -= len;
				Node * f = xIt.getIt();
				Node * l = temp2.getIt()->prev;
				xIt = temp2;
				unlink_nodes(f, l);
				temp2 = ++it;
				it--;
				link_node(it.getIt(), f, l);
				it = temp2;
			}
			else
				++it;
		}
		splice(ite, x);

	}

	void splice (iterator position, list & x){
		if(this == &x)
			throw "list::splice(iterator, list) called with this == &list";
		if (!x.empty()){
			Node * first = x.end().getIt();
			first = first->next;
			Node * last = x.end().getIt();
			last = last->prev;
			unlink_nodes(first, last);
			link_node(position.getIt(), first, last);
			_size += x._size;
			x._size = 0;
		}

	}
	void splice (iterator position, list & x, iterator i){\
		if(this == &x)
			throw "list::splice(iterator, list) called with this == &list";
		if (!x.empty()) {
			if (position.getIt() != i.getIt() && position.getIt() != (i.getIt())->next) {
				Node *first = i.getIt();
				unlink_nodes(first, first);
				link_node(position.getIt(), first, first);
				_size++;
				x._size--;
			}
		}
	}

	void splice(iterator position, list & x, iterator first, iterator last){
		if (first != last){
			Node * f = first.getIt();
			--last;
			Node * l = last.getIt();
			if (this != &x){
				size_t len = distance(first, last) + 1;
				x._size -= len;
				_size += len;
			}
			unlink_nodes(f, l);
			link_node(position.getIt(), f, l);
		}
	}

	void remove(const value_type & val){
		iterator it = begin();
		iterator ite = end();
		for (;it != ite; it++){
			if (*it == val)
				erase(it);
		}
	}

	template<class Predicate>
			void remove_if(Predicate pred){
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; it++){
			if (pred(*it))
				erase(it);
		}
	}

	void resize(size_type n, value_type val = value_type()) {
		if (_size > n){
			while (_size > n)
				pop_back();
		}
		else if (_size < n)
			while (_size < n)
				push_back(val);
	}


	void reverse() {
		Node *temp;
		Node *first = _last;
		if (_size > 1) {
			while (true) {
				temp = first->next;
				first->next = first->prev;
				first->prev = temp;
				first = first->prev;
				if (first == _last)
					break;

			}
		}
	}


	void sort(){
		sort(nonComp);
	}

	template<class Compare>
			void sort(Compare comp){
		_merge_sort(_last->next, comp);
		Node * node = _last->next;
		while (node->next != _last){
			node = node->next;
		}
		_last->prev = node;
	}

	void swap(list & x){
		if (*this != x){
			allocator_type alloc;
			allocator_rebind_type rebind_alloc;
			Node * last;

			alloc = x._alloc;
			rebind_alloc = x._alloc_rebind;
			last = x._last;

			x._last = this->_last;
			x._alloc_rebind = this->_alloc_rebind;
			x._alloc = this->_alloc;

			this->_alloc_rebind = rebind_alloc;
			this->_alloc = alloc;
			this->_last = last;
		}
	}

	void unique(){
		iterator it1 = begin();
		iterator it2 = it1++;
		iterator ite = end();

		for (;it2 != ite;){
			if (*it1++ == *it2)
				it2 = erase(it2);
			else{
				it2++;
			}
		}
	}

	template<class BinaryPredicate>
			void unique(BinaryPredicate binary_pred){
		iterator it1 = begin();
		iterator it2;
		iterator ite = end();

		for (;it1 != ite;){
			it2 = (++it1)--;
			for (;it2 != ite && binary_pred(*it1, *it2);)
				++it2;
			if (++it1 != it2){
				it1 = erase(it1, it2);
			}
		}
	}



public:
	class iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		//iterator() : _it(0){};
	public:

		explicit iterator(Node * node = nullptr) : _it(node){};
		virtual ~iterator(){};

		iterator(iterator const & node){
				_it = node._it;
		}
		iterator(const_iterator const & node){
				_it = node.getNode();
		}
		iterator & operator = (iterator const & src){
			_it = src._it;
			return (*this);
		}
		iterator & operator = (const_iterator const & src){
			_it = src._it;
			return (*this);
		}

		iterator & operator ++ (){	_it = _it->next;	return (*this);}
		iterator operator ++ (int){	iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		iterator & operator -- (){	_it = _it->prev;return (*this);	}
		iterator operator -- (int){	iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(iterator const & src){return (_it->content == src._it->content);}
		bool operator==(const_iterator const & src){return (_it->content == src.getIt()->content);}
		bool operator!=(iterator const & src){return (_it->content != src._it->content);}
		bool operator!=(const_iterator const & src){return (_it->content != src.getIt()->content);}
		reference operator*() const {return *(_it->content);}
		pointer operator->() const {return (_it->content);}

		Node * getIt() const { return (_it);}

	};
	class const_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		const_iterator() : _it(0){};
	public:

		explicit const_iterator(Node * node = nullptr) : _it(node){};
		virtual ~const_iterator(){};

		const_iterator(const_iterator const & node){
				_it = node._it;
		}
		const_iterator(iterator const & node){
				_it = node._it;
		}

		const_iterator & operator = (const_iterator const & src){
				_it = src._it;
			return (*this);
		}
		const_iterator & operator = (iterator const & src){
				_it = src._it;
			return (*this);
		}


		const_iterator & operator ++ (){	_it = _it->next;	return (*this);}
		const_iterator operator ++ (int){	const_iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		const_iterator & operator -- (){	_it = _it->prev;return (*this);	}
		const_iterator operator -- (int){	const_iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(iterator const & src){return (_it->content == src.getIt()->content);}
		bool operator==(const_iterator const & src){return (_it->content == src._it->content);}
		bool operator!=(iterator const & src){return (_it->content != src.getIt()->content);}
		bool operator!=(const_iterator const & src){return (_it->content != src._it->content);}
		const_reference operator*() const {return *(_it->content);}
		const_pointer operator->() const {return (_it->content);}
		Node * getNode() const { return (_it);}
	};
	class reverse_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		reverse_iterator() : _it(0){};
	public:

		explicit reverse_iterator(Node * node = nullptr) : _it(node){};
		virtual ~reverse_iterator(){};

		reverse_iterator(reverse_iterator const & node){
				_it = node._it;
		}

		reverse_iterator(const_reverse_iterator const & node){
				_it = node._it;
		}
		reverse_iterator & operator = (reverse_iterator const & src){
				_it = src._it;
			return (*this);
		}

		reverse_iterator & operator = (const_reverse_iterator const & src){
				_it = src._it;
			return (*this);
		}

		reverse_iterator & operator -- (){	_it = _it->next;	return (*this);}
		reverse_iterator operator -- (int){	reverse_iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		reverse_iterator & operator ++ (){	_it = _it->prev;return (*this);	}
		reverse_iterator operator ++ (int){	reverse_iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(reverse_iterator const & src){return (_it->content == src._it->content);}
		bool operator==(const_reverse_iterator const & src){return (_it->content == src.getIt()->content);}
		bool operator!=(reverse_iterator const & src){return (_it->content != src._it->content);}
		bool operator!=(const_reverse_iterator const & src){return (_it->content != src.getIt()->content);}
		reference operator*() const {return *(_it->content);}
		pointer operator->() const {return (_it->content);}
		Node * getIt() const { return (_it);}
	};
	class const_reverse_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		const_reverse_iterator() : _it(0){};
	public:

		explicit const_reverse_iterator(Node * node = nullptr) : _it(node){};
		virtual ~const_reverse_iterator(){};

		const_reverse_iterator(const_reverse_iterator const & node){
				_it = node._it;
		}
		const_reverse_iterator & operator = (const_reverse_iterator const & src){
				_it = src._it;
			return (*this);
		}

		const_reverse_iterator(reverse_iterator const & node){
				_it = node._it;
		}
		const_reverse_iterator & operator = (reverse_iterator const & src){
				_it = src._it;
			return (*this);
		}

		const_reverse_iterator & operator -- (){	_it = _it->next;	return (*this);}
		const_reverse_iterator operator -- (int){	const_reverse_iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		const_reverse_iterator & operator ++ (){	_it = _it->prev;return (*this);	}
		const_reverse_iterator operator ++ (int){	const_reverse_iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(reverse_iterator const & src){return (_it->content == src.getIt()->content);}
		bool operator==(const_reverse_iterator const & src){return (_it->content == src._it->content);}
		bool operator!=(reverse_iterator const & src){return (_it->content != src.getIt()->content);}
		bool operator!=(const_reverse_iterator const & src){return (_it->content != src._it->content);}
		const_reference operator*() const {return *(_it->content);}
		pointer operator->() const {return (_it->content);}
		Node * getIt() const { return (_it);}
	};



};

namespace ft{
	template <class T, class Alloc>
	bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		typename ft::list<T, Alloc>::iterator it1 = lhs.begin();
		typename ft::list<T, Alloc>::iterator ite1 = lhs.end();
		typename ft::list<T, Alloc>::iterator it2 = rhs.begin();
		typename ft::list<T, Alloc>::iterator ite2 = rhs.end();

		if (lhs.size() != rhs.size())
			return (false);
		for (; it1 != ite1; it1++, it2++){
			if (*it1 != *it2)
				return (false);
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator < (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename ft::list<T, Alloc>::iterator it1 = lhs.begin();
		typename ft::list<T, Alloc>::iterator ite1 = lhs.end();
		typename ft::list<T, Alloc>::iterator it2 = rhs.begin();
		typename ft::list<T, Alloc>::iterator ite2 = rhs.end();

		for (; it2 != ite2; ++it1, ++it2){
			if(it1 == ite1 || *it1 < *it2){
				return (true);
			}
			if (*it2 < *it1)
				return (false);
		}
		return (false);
	}
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator >  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return !(lhs < rhs);
	}
	template <class T, class Alloc>
	void swap(ft::list<T,Alloc> & x, ft::list<T, Alloc> & y) {
		x.swap(y);
	}
};

#endif
