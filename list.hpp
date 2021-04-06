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
	//allocator_type_node 		_allocNodes;
	allocator_rebind_type 		_alloc_rebind;
	Node *						_last;

	void create_list(){
		this->_last = _alloc_rebind.allocate(1);
		this->_last->content = _alloc.allocate(1);
		this->_last->next = nullptr;
		this->_last->prev = nullptr;
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

	size_type list_size(){
		size_type len = 0;
		iterator it = begin();
		iterator ite = end();
		for (;it != ite; ++it){
			len++;
		}
		return (len);
	}


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

	~list() {
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
	size_type max_size() const{ return 0;} /// make right here
	iterator begin() { return iterator(_last->next);}
	const_iterator begin() const { return iterator(_last->next);}



	list & operator = (list const & src){
		if (!empty())
			clear();


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




public:
	class iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		iterator() : _it(0){};
	public:

		explicit iterator(Node * node) : _it(node){};
		virtual ~iterator(){};

		explicit iterator(iterator & node){
			if (this != & node){
				_it = node;
			}
		}
		iterator & operator = (iterator const & src){
			if (this != &src){
				_it = src;
			}
		}

		iterator & operator ++ (){	_it = _it->next;	return (*this);}
		iterator operator ++ (int){	iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		iterator & operator -- (){	_it = _it->prev;return (*this);	}
		iterator operator -- (int){	iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(iterator const & src){return (_it->content == src._it->content);}
		bool operator==(const_iterator const & src){return (_it->content == src._it->content);}
		bool operator!=(iterator const & src){return (_it->content != src._it->content);}
		bool operator!=(const_iterator const & src){return (_it->content != src._it->content);}
		reference operator*() const {return *(_it->content);}
		pointer operator->() const {return (_it->content);}

	};
	class const_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		const_iterator() : _it(0){};
	public:

		explicit const_iterator(Node * node) : _it(node){};
		virtual ~const_iterator(){};

		explicit const_iterator(const_iterator & node){
			if (this != & node){
				_it = node;
			}
		}
		const_iterator & operator = (const_iterator const & src){
			if (this != &src){
				_it = src;
			}
		}

		const_iterator & operator ++ (){	_it = _it->next;	return (*this);}
		const_iterator operator ++ (int){	iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		const_iterator & operator -- (){	_it = _it->prev;return (*this);	}
		const_iterator operator -- (int){	iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(iterator const & src){return (_it->content == src._it->content);}
		bool operator==(const_iterator const & src){return (_it->content == src._it->content);}
		bool operator!=(iterator const & src){return (_it->content != src._it->content);}
		bool operator!=(const_iterator const & src){return (_it->content != src._it->content);}
		const_reference operator*() const {return *(_it->content);}
		const_pointer operator->() const {return (_it->content);}

	};
	class reverse_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		reverse_iterator() : _it(0){};
	public:

		explicit reverse_iterator(Node * node) : _it(node){};
		virtual ~reverse_iterator(){};

		explicit reverse_iterator(reverse_iterator & node){
			if (this != & node){
				_it = node;
			}
		}
		reverse_iterator & operator = (reverse_iterator const & src){
			if (this != &src){
				_it = src;
			}
		}

		reverse_iterator & operator -- (){	_it = _it->next;	return (*this);}
		reverse_iterator operator -- (int){	iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		reverse_iterator & operator ++ (){	_it = _it->prev;return (*this);	}
		reverse_iterator operator ++ (int){	iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(reverse_iterator const & src){return (_it->content == src._it->content);}
		bool operator==(const_reverse_iterator const & src){return (_it->content == src._it->content);}
		bool operator!=(reverse_iterator const & src){return (_it->content != src._it->content);}
		bool operator!=(const_reverse_iterator const & src){return (_it->content != src._it->content);}
		reference operator*() const {return *(_it->content);}
		pointer operator->() const {return (_it->content);}

	};
	class const_reverse_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type>{
	private:
		Node * _it;
		const_reverse_iterator() : _it(0){};
	public:

		explicit const_reverse_iterator(Node * node) : _it(node){};
		virtual ~const_reverse_iterator(){};

		explicit const_reverse_iterator(const_reverse_iterator & node){
			if (this != & node){
				_it = node;
			}
		}
		const_reverse_iterator & operator = (const_reverse_iterator const & src){
			if (this != &src){
				_it = src;
			}
		}

		const_reverse_iterator & operator -- (){	_it = _it->next;	return (*this);}
		const_reverse_iterator operator -- (int){	iterator oldValue(_it);	_it = _it->next; return (oldValue);	}
		const_reverse_iterator & operator ++ (){	_it = _it->prev;return (*this);	}
		const_reverse_iterator operator ++ (int){	iterator oldValue(_it);	_it = _it->prev; return (oldValue);	}

		bool operator==(reverse_iterator const & src){return (_it->content == src._it->content);}
		bool operator==(const_reverse_iterator const & src){return (_it->content == src._it->content);}
		bool operator!=(reverse_iterator const & src){return (_it->content != src._it->content);}
		bool operator!=(const_reverse_iterator const & src){return (_it->content != src._it->content);}
		const_reference operator*() const {return *(_it->content);}
		pointer operator->() const {return (_it->content);}

	};

};

#endif
