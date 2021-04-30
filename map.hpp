#ifndef MAP_HPP
#define MAP_HPP
#include "utils.hpp"
#include <map>

template < class Key, class T, class Compare, class Alloc>
class ft::map{
public:
	typedef Key										key_type;
	typedef T										mapped_type;
	typedef std::pair<const key_type, mapped_type> 				value_type;
	typedef Compare									key_compare;
	typedef Alloc									allocator_type;
	typedef value_type &							reference;
	typedef const value_type & 						const_reference;
	typedef value_type *							pointer;
	typedef const value_type *						const_pointer;

	typedef size_t									size_type;
	typedef ptrdiff_t 								difference_type;

	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;

	class value_compare : public std::binary_function<value_type, value_type, bool> {
	public:
		key_compare comp;

		explicit value_compare(key_compare c) : comp(c) {};
	public:
		bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); };
	};

private:

	/*enum Color{
		RED,
		BLACK
	};*/

	struct Node {
		Node *parent;
		Node *left;
		Node *right;
		pointer content;
		bool color;
	};

	const static bool _black = false;
	const static bool _red = true;

	typedef typename allocator_type::template rebind<Node>::other alloc_rebind;
	alloc_rebind 	_node_alloc;

	size_type  		_size;
	allocator_type _alloc;
	key_compare 	_compare;

	Node * _root;
	Node * _endNode;
	Node * _beginNode;

	void _createMap(){
		_beginNode = _node_alloc.allocate(1);
		_beginNode->parent = nullptr;
		_beginNode->left = nullptr;
		_beginNode->right = nullptr;
		_beginNode->content = nullptr;
		_beginNode->color = _black;

		_endNode = _node_alloc.allocate(1);
		_endNode->parent = nullptr;
		_endNode->left = nullptr;
		_endNode->right = nullptr;
		_endNode->content = nullptr;
		_endNode->color = _black;
		_size = 0;
	}

	Node * _createNode(Node *parent, reference content, bool color){
		Node *node = _node_alloc.allocate(1);
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = color;
		node->content = _alloc.allocate(1);
		_alloc.construct(node->content, content);
		_size++;
		return (node);
	}

	void _deleteNode(Node *node){
		_alloc.destroy(node->content);
		_alloc.deallocate(node->content, 1);
		_node_alloc.deallocate(node, 1);
		_size--;
	}

	bool _isOnLeft(Node * node){
		return (node == node->parent->left);
	}


	/* We replace old node with new node */
	void _moveDown(Node *nParent, Node *oldParent){
		if (oldParent->parent != nullptr){
			if (_isOnLeft(oldParent)){
				oldParent->parent->left = nParent;
			}else {
				oldParent->parent->right = nParent;
			}
		}
		nParent->parent = oldParent->parent;
		oldParent->parent = nParent;
	}

	void _rotateLeft(Node *x){
		/* new parent will be right child of node */
		Node *nParent = x->right;

		/*update root if current node is root */
		if (x == _root)
			_root = nParent;
		_moveDown(nParent, x);
		/*connect x with new parent's left element with node */
		x->right = nParent->left;
		/*connect new parent's left element with node
			 if it is not null*/
		if (nParent->left != nullptr)
			nParent->left->parent = x;
		/* connect new parent with x*/
		nParent->left = x;
	}

	void _rotateRight(Node *x){
		Node *nParent = x->left;

		if (x == _root)
			_root = nParent;
		_moveDown(nParent, x);
		x->left = nParent->right;
		if (nParent->right != nullptr)
			nParent->right->parent = x;
		nParent->right = x;
	}

	void _colorSwap(Node *node1, Node *node2){
		bool temp = node1->color;
		node1->color = node2->color;
		node2->color = temp;
	}

	void _valueSwap(Node *node1, Node *node2){
		pointer temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
	}

	Node * _getUncle(Node *node){
		if (node->parent == nullptr || node->parent->parent == nullptr)
			return (nullptr);
		/*if uncle on right*/
		if (_isOnLeft(node->parent))
			return (node->parent->parent->right);
		else
			return (node->parent->parent->left);
	}

	Node * _getBrother(Node *node){
		if (node->parent == nullptr)
			return (nullptr);
		if (_isOnLeft(node->parent))
			return (node->parent->right);
		else
			return (node->parent->left);
	}

	bool _hasRedChild(Node *node){
		return ((node->left != nullptr && node->left->color == _red) ||
				(node->right != nullptr && node->right->color == _red));
	}

	void _fixRed_Red(Node *node){
		if (node == _root){
			node->color = _black;
			return ;
		}
		Node *parent = node->parent;
		Node *grandParent = node->parent->parent;
		Node *uncle = _getUncle(node);

		if (parent->color != _black){
			if (uncle != nullptr && uncle->color == _red){
				parent->color = _black;
				uncle->color = _black;
				grandParent->color = _red;
				_fixRed_Red(grandParent);
			}
			else {
				if (_isOnLeft(parent)) {
					if (_isOnLeft(node)){
						/*for left right*/
						_colorSwap(parent, grandParent);
					}
					else {
						_rotateLeft(parent);
						_colorSwap(node, grandParent);
					}
					_rotateRight(grandParent);
				}
				else{
					if (_isOnLeft(node)){
						/*for right left*/
						_rotateRigth(parent);
						_colorSwap(node, grandParent);
					}
					else{
						_colorSwap(parent, grandParent);
					}
					_rotateLeft(grandParent);
				}
			}
		}
	}

	Node * _parentWithoutLeftChild(Node * node){
		Node * temp = node;
		while (temp->left != nullptr){  temp = temp->left; }
		return (temp);
	}

	Node * _nodeReplace(Node *node){
		if (node->left != nullptr && node->right != nullptr)
			return (_parentWithoutLeftChild(node->right));
		if (node->left == nullptr && node->right == nullptr)
			return (nullptr);
		if (node->left != nullptr)
			return node->left;
		else
			return node->right;
	}

	void _fixDoubleBlack(Node * node){
		if (node == _root){
			return ;
		}
		Node *brotherNode = _getBrother(node);
		Node *parent = node->parent;
		if (brotherNode == nullptr){
			_fixDoubleBlack(parent);
		}
		else{
			if (brotherNode->color == _red) {
				parent->color = _red;
				brotherNode->color = _black;
				if (_isOnLeft(brotherNode)) {
					_rotateRight(parent);
				} else
					_rotateLeft(parent);
				_fixDoubleBlack(node);
			}
			else {
				if (_hasRedChild(brotherNode)) {
					if (brotherNode->left != nullptr && brotherNode->left->color == _red) {
						if (_isOnLeft(brotherNode)) {
							brotherNode->left->color = brotherNode->color;
							brotherNode->color = parent->color;
							_rotateRight(parent);
						} else {
							brotherNode->left->color = parent->color;
							_rotateRight(brotherNode);
							_rotateLeft(parent);
						}
					} else {
						if (_isOnLeft(brotherNode)) {
							brotherNode->right->color = parent->color;
							_rotateLeft(brotherNode);
							_rotateRight(parent);
						} else {
							brotherNode->right->color = brotherNode->color;
							brotherNode->color = parent->color;
							_rotateLeft(parent);
						}
					}
					parent->color = _black;
				}
				else{
					brotherNode->color = _red;
					if (parent->color == _black)
						_fixDoubleBlack(parent);
					else
						parent->color = _black;

				}
			}
		}
	}


	void _deleteNodeFromTree(Node * delNode){
		Node * tempNode = _nodeReplace(delNode);

		/* True when del and temp nodes are both black */

		bool del_temp_black = ((tempNode == nullptr || tempNode->color == _black) && delNode->color == _black);
		Node *parent = delNode->parent;

		if (tempNode == nullptr){
			/*if tempNode is nullptr, than delNode is leaf */
			if (delNode == _root)
				_root = nullptr;
			else{
				if (del_temp_black){
					/*v is leaf, need to fix double black at v*/
					_fixDoubleBlack(delNode);
				}
				else
					if (_getBrother(delNode) != NULL)
						_getBrother(delNode)->color = _red;
			}
			/*delete from tree*/
			if (_isOnLeft(delNode))
				parent->left = NULL;
			else
				parent->right = NULL;
			_deleteNode(delNode);
			return ;
		}
		if (delNode->left == NULL || delNode->right == NULL){
			if (delNode == _root){
				_alloc.destroy(delNode->content, 1);
				_alloc.construct(delNode->content, *(tempNode->content));
				delNode->left = nullptr;
				delNode->right = nullptr;
				_deleteNode(tempNode);
			}
			else{
				if (_isOnLeft(delNode))
					delNode->parent->left = tempNode;
				else
					delNode->parent->right = tempNode;
				tempNode->parent = delNode->parent;
				_deleteNode(delNode);
				if (del_temp_black)
					_fixDoubleBlack(tempNode);
				else
					tempNode->color = _black;
			}
			return ;
		}
		_valueSwap(delNode, tempNode);
		_deleteNodeFromTree(tempNode);
	}

	Node *_searchByKey(key_type key){
		Node *node = _root;
		while (node != nullptr){
			if (key < node->content->first){
				if (node->left == nullptr)
					break;
				else
					node = node->left;
			}
			else if (key == node->content->first){
				break;
			}
			else{
				if (node->right == nullptr)
					break;
				else
					node = node->right;
			}
		}
		return (node);
	}

	bool _insert(value_type val){
		Node *node = _createNode(nullptr, val, _red);

		if (_root == nullptr){
			node->color = _black;
			_root = node;
		}
		else{
			Node *temp = _searchByKey(val.first);
			if (temp->content->first == val.first){
				_deleteNode(node);
				return false;
			}

			node->parent = temp;
			if (val.second < temp->content)
				temp->left = node;
			else
				temp->right = node;
			_fixRed_Red(node);
		}
		return (true);
	}

	bool _deleteByKey(key_type val){
		if (_root == nullptr){
			return false;
		}
		Node *node = _searchByKey(val);
		if (node->content->first != val)
			return false;
		_deleteNodeFromTree(node);
		return true;
	}

	Node * _getMin(Node * node){
		if (node && node->left)
			return _getMin(node);
		return (node);
	}

	Node * _getMax(Node * node){
		if (node && node->right)
			return _getMax(node);
		return (node);
	}

	void _linkLeft(Node *parent, Node *node){
		if (parent == nullptr)
			return ;
		parent->left = node;
		if (node)
			node->parent = parent;
	}
	void _linkRight(Node * parent, Node *node){
		if (parent == nullptr)
			return ;
		parent->right = node;
		if (node)
			node->parent = parent;
	}

	Node * _nextNode(Node * node){
		if (node->right)
			return (_getMin(node->right));
		else if (node->parent && _isOnLeft(node))
			return (node->parent);
		else if (!_isOnLeft())
			node = node->parent;
		Node * temp = node;
		while (temp->parent->right == temp) {
			temp = temp->parent;
			if (temp == nullptr)
				return (node->right);
		}
		return (temp->parent);
	}

	Node * _prevNode(Node * node){
		if (node->left)
			return (_getMax(node->left));
		else if (node->parent && !_isOnLeft(node))
			return (node->parent);
		Node * temp = node;
		while (temp->parent->right == temp){
			temp = temp->parent;
			if (temp == nullptr)
				return (node->right);
		}
		return (temp->parent);
	}

public:


	explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _compare(comp), _alloc(alloc), _root(nullptr){
		_createMap();
	}

	template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(), typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _compare(comp), _alloc(alloc), _root(nullptr){
		_createMap();
		insert(first, last);
	}

	map (const map & x) : _size(x._size), _alloc(x._alloc), _compare(x._compare), _root(nullptr){
		_createMap();
		*this = x;
	}

	map & operator = (const map & src){
		clear();
		insert(src.begin(), src.end());
		return (*this);
	}

	~map(){
		clear();
		_node_alloc.deallocate(_beginNode, 1);
		_node_alloc.deallocate(_endNode, 1);
	}

	void clear(){
		while (_size)
			erase(begin());
	}

	iterator begin(){
		Node *node;
		if (_size == 0)
			node = _endNode;
		else
			node = _beginNode->parent;
		iterator it(node);
		return (it);
	}

	const_iterator begin() const{
		Node *node;
		if (_size == 0)
			node = _endNode;
		else
			node = _beginNode->parent;
		const_iterator it(node);
		return (it);
	}

	reverse_iterator rbegin() {
		Node *node;
		if (_size == 0)
			node = _beginNode;
		else
			node = _endNode->parent;
		reverse_iterator it(node);
		return (it);
	}

	const_reverse_iterator rbegin() const {
		Node *node;
		if (_size == 0)
			node = _beginNode;
		else
			node = _endNode->parent;
		const_reverse_iterator it(node);
		return (it);
	}

	iterator end(){ return iterator(_endNode);}
	const_iterator end() const{ return const_iterator(_endNode);}

	reverse_iterator rend(){ return reverse_iterator(_beginNode);}
	const_reverse_iterator rend() const {return const_reverse_iterator(_beginNode);}

	bool empty() const{ return (_size == 0);}
	size_type size() const { return (_size);}
	size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(_root);}


	iterator find(const key_type & k){
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; ++it)
			if (it->first == k)
				return it;
		return (end());
	}

	size_type count(const key_type& k) const{
		iterator it = begin();
		iterator ite = end();
		for (;it != ite; ++it){
			if (it->first == k)
				return 1;
		}
		return 0;
	}

	const_iterator find (const key_type & k) const{
		const_iterator it = begin();
		const_iterator ite = end();
		for (; it != ite; ++it)
			if (it->first == k)
				return it;
		return (end());
	}


	std::pair<iterator, bool> insert(const value_type & val){
		if (_size != 0){
			if (_beginNode->parent != nullptr)
				_beginNode->parent->left = nullptr;
			if (_endNode->parent != nullptr)
				_beginNode->parent->right = nullptr;
		}
		bool isInserted = _insert(val);
		Node *max = _getMax(_root);
		Node *min = _getMin(_root);
		_linkLeft(min, _beginNode);
		_linkRight(max, _endNode);
		return (std::make_pair(find(val.first),isInserted));
	}

	mapped_type & operator [] (const key_type & k){
		return (this->insert(std::make_pair(k,mapped_type())).first->second);
	}

	iterator insert (iterator position, const value_type & val){
		(void)position;
		return (insert(val).first);
	}

	template<class InputIterator>
			void insert(InputIterator first, InputIterator last,
			   typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
		while(first != last){
			insert(*first);
			++first;
		}
	}

	void erase(iterator position){
		erase(position->first);
	}
	size_type erase(const key_type & k){
		if (_size != 0){
			if (_beginNode->parent){
				_beginNode->parent->left = nullptr;
			}
			if (_endNode->parent)
				_endNode->parent->right = nullptr;
		}
		bool result = _deleteByKey(k);
		Node * max = _getMax(_root);
		Node * min = _getMin(_root);
		_linkLeft(min, _beginNode);
		_linkRight(max,_endNode);
		return (result ? 1 : 0);
	}

	void erase(iterator first, iterator last){
		while(first != last){
			erase(first);
			first++;
		}
	}

	void swap(map & x){
		Node * temp = this->_root;
		this->_root = x._root;
		x._root = temp;

		temp = this->_beginNode;
		this->_beginNode = x._beginNode;
		x._beginNode = temp;

		temp = this->_endNode;
		this->_endNode = x._endNode;
		x._endNode = temp;

		size_t size = this->_size;
		this->_size = x._size;
		x._size = size;
	}
	key_compare key_comp() const{return _compare;}

	value_compare value_comp() const{ return value_compare(_compare);}

	/*1 2 3 4 4 4 5 5 5 5 5 6 7
	При поиске upper_bound для значения 5 это будет итератор (указатель, если концепция итератора для вас нова) на значение 6 - первое большее значение.

	Соответственно, lower_bound будет указывать на первое не меньшее значение - на первое 5.*/
	iterator lower_bound(const key_type & k){
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; ++it){
			if (!_compare(it->first, k))
				break;
		}
		return (it);
	}
	const_iterator lower_bound(const key_type & k) const{
		const_iterator it = begin();
		const_iterator ite = end();
		for (; it != ite; ++it){
			if (!_compare(it->first, k))
				break;
		}
		return (it);
	}

	iterator upper_bound(const key_type & k){
		iterator it = begin();
		iterator ite = end();

		for (; it != ite; ++it){
			if (_compare(it->first, k))
				break;
		}
		return (it);
	}

	const_iterator upper_bound(const key_type & k)const{
		const_iterator it = begin();
		const_iterator ite = end();

		for (; it != ite; ++it){
			if (_compare(it->first, k))
				break;
		}
		return (it);
	}

	std::pair<const_iterator, const_iterator> equal_range(const key_type & k) const{
		return std::make_pair(lower_bound(k), upper_bound(k));
	}
	std::pair<iterator,iterator> equal_range (const key_type& k){
		return std::make_pair(lower_bound(k), upper_bound(k));
	}



public:
	class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
			Node * _it;
	public:
			explicit iterator(Node * node = nullptr) : _it(node) {};
			~iterator(){};
			iterator(const iterator &it){
				*this = it;
			}
			iterator & operator = (const iterator & it){
				if (this != &it)
					this->_it = it._it;
				return (*this);
			}

			iterator operator ++(){
				if (_it->right) {	_it = _getMin(_it->right);	return (*this);		}
				else if (_it->parent && _it->parent->left == _it) {	_it = _it->parent;	return (*this);	}
				else if (_it->parent->right == _it) {_it = _it->parent;}
				Node *temp = _it;
				while (temp->parent->right == temp) {
					temp = temp->parent;
					if (temp == nullptr) {	_it = _it->right; return (*this);}
				}
				_it = temp->parent;
				return (*this);
			}
			iterator operator ++(int){
				iterator oldValue(_it);
				_it++;
				return (oldValue);
			}

			iterator operator --(){
				if (_it->left) {_it = _getMax(_it->left);	return (*this);	}
				else if (_it->parent && _it->parent->right == _it) {_it = _it->parent;	return (*this);	}
				Node *temp = _it;
				while (temp->parent->left == temp) {
					temp = temp->parent;
					if (temp == nullptr) {	_it = _it->left;	return (*this);	}
				}
				_it = _it->parent;
				return (*this);
			}

			iterator operator -- (int){
				iterator oldValue(_it);
				_it--;
				return (oldValue);
			}

		bool operator == (const iterator &it) const { return _it == it._it;}
		bool operator == (const const_iterator &it) const { return _it == it._getNode();}

		bool operator != (const iterator &it) const { return _it != it._it;}
		bool operator != (const const_iterator &it) const { return _it != it._getNode();}

		value_type & operator *() const { return *(_it->content);}
		value_type * operator ->() const { return (_it->content);}
		Node * _getNode() const { return _it;}

	};

	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		Node * _it;
	public:
		explicit const_iterator(Node * node = nullptr) : _it(node) {};
		~const_iterator(){};
		const_iterator(const const_iterator &it){
			*this = it;
		}
		const_iterator(const iterator &it){
			*this = it;
		}

		const_iterator & operator = (const const_iterator & it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}
		const_iterator & operator = (const iterator & it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}

		const_iterator operator ++(){
			if (_it->right) {
				if (_it->right) {	_it = _getMin(_it->right);	return (*this);		}
				else if (_it->parent && _it->parent->left == _it) {	_it = _it->parent;	return (*this);	}
				else if (_it->parent->right == _it) {_it = _it->parent;}
				Node *temp = _it;
				while (temp->parent->right == temp) {
					temp = temp->parent;
					if (temp == nullptr) {	_it = _it->right; return (*this);}
				}
				_it = temp->parent;
				return (*this);
			}
		}
		const_iterator operator ++(int){
			const_iterator oldValue(_it);
			_it++;
			return (oldValue);
		}

		const_iterator operator --(){
			if (_it->left) {_it = _getMax(_it->left);	return (*this);	}
			else if (_it->parent && _it->parent->right == _it) {_it = _it->parent;	return (*this);	}
			Node *temp = _it;
			while (temp->parent->left == temp) {
				temp = temp->parent;
				if (temp == nullptr) {	_it = _it->left;	return (*this);	}
			}
			_it = _it->parent;
			return (*this);
		}

		const_iterator operator -- (int){
			const_iterator oldValue(_it);
			_it--;
			return (oldValue);
		}

		bool operator == (const iterator &it) const { return _it == it._getNode();}
		bool operator == (const const_iterator &it) const { return _it == it._it;}

		bool operator != (const iterator &it) const { return _it != it._getNode();}
		bool operator != (const const_iterator &it) const { return _it != it._it;}

		const value_type & operator *() const { return *(_it->content);}
		const value_type * operator ->() const { return (_it->content);}
		Node * _getNode() const { return _it;}

	};

	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		Node * _it;
	public:
		explicit reverse_iterator(Node * node = nullptr) : _it(node) {};
		~reverse_iterator(){};
		reverse_iterator(const reverse_iterator &it){
			*this = it;
		}
		reverse_iterator & operator = (const reverse_iterator & it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}

		reverse_iterator operator --(){
			if (_it->left) {_it = _getMax(_it->left);	return (*this);	}
			else if (_it->parent && _it->parent->right == _it) {_it = _it->parent;	return (*this);	}
			Node *temp = _it;
			while (temp->parent->left == temp) {
				temp = temp->parent;
				if (temp == nullptr) {	_it = _it->left;	return (*this);	}
			}
			_it = _it->parent;
			return (*this);
		}
		reverse_iterator operator --(int){
			iterator oldValue(_it);
			_it--;
			return (oldValue);
		}

		reverse_iterator operator ++(){
			_it = _prevNode(_it);
			return (*this);
		}

		reverse_iterator operator ++ (int){
			reverse_iterator oldValue(_it);
			_it++;
			return (oldValue);
		}

		bool operator == (const reverse_iterator &it) const { return _it == it._it;}
		bool operator == (const const_reverse_iterator &it) const { return _it == it._getNode();}

		bool operator != (const reverse_iterator &it) const { return _it != it._it;}
		bool operator != (const const_reverse_iterator &it) const { return _it != it._getNode();}

		value_type & operator *() const { return *(_it->content);}
		value_type * operator ->() const { return (_it->content);}
		Node * _getNode() const { return _it;}

	};

	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		Node * _it;
	public:
		explicit const_reverse_iterator(Node * node = nullptr) : _it(node) {};
		~const_reverse_iterator(){};
		const_reverse_iterator(const const_reverse_iterator &it){
			*this = it;
		}
		const_reverse_iterator(const reverse_iterator &it){
			*this = it;
		}

		const_reverse_iterator & operator = (const const_reverse_iterator & it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}
		const_reverse_iterator & operator = (const reverse_iterator & it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}

		const_reverse_iterator operator --(){
			_it = _nextNode(_it);
			return (*this);
		}
		const_reverse_iterator operator --(int){
			const_reverse_iterator oldValue(_it);
			_it--;
			return (oldValue);
		}

		const_reverse_iterator operator ++(){
			_it = _prevNode(_it);
			return (*this);
		}

		const_reverse_iterator operator ++ (int){
			const_reverse_iterator oldValue(_it);
			_it++;
			return (oldValue);
		}

		bool operator == (const reverse_iterator &it) const { return _it == it._getNode();}
		bool operator == (const const_reverse_iterator &it) const { return _it == it._it;}

		bool operator != (const reverse_iterator &it) const { return _it != it._getNode();}
		bool operator != (const const_reverse_iterator &it) const { return _it != it._it;}

		const value_type & operator *() const { return *(_it->content);}
		const value_type * operator ->() const { return (_it->content);}
		Node * _getNode() const { return _it;}

	};

};

namespace ft{
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
};

#endif
