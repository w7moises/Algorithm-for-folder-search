#ifndef __AVL_HPP__
#define __AVL_HPP__

#include <functional>
#include <algorithm>

template <typename T>
class AVLTree {
	struct Node {
		T     e;
		Node* l;
		Node* r;
		int   h;

		Node(T e) : e(e), l(nullptr), r(nullptr), h(0) {}

		static int height(Node* n) {
			return n == nullptr ? -1 : n->h;
		}
		void updateH() {
			h = std::max(Node::height(l), Node::height(r)) + 1;
		}
	};

	Node*           root;
	int             length;
	

	void destroy(Node* n) {
		if (n != nullptr) {
			destroy(n->l);
			destroy(n->r);
			delete n;
		}
	}
	void rotAB(Node*& n) {
		Node* aux = n->l;
		n->l = aux->r;
		n->updateH();
		aux->r = n;
		n = aux;
		n->updateH();
	}
	void rotBA(Node*& n) {
		Node* aux = n->r;
		n->r = aux->l;
		n->updateH();
		aux->l = n;
		n = aux;
		n->updateH();
	}
	void balance(Node*& n) {
		int delta = Node::height(n->l) - Node::height(n->r);
		if (delta < -1) {
			if (Node::height(n->r->l) > Node::height(n->r->r)) {
				rotAB(n->r);
			}
			rotBA(n);
		}
		else if (delta > 1) {
			if (Node::height(n->l->r) > Node::height(n->l->l)) {
				rotBA(n->l);
			}
			rotAB(n);
		}
	}
	void add(Node*& n, T e) {
		if (n == nullptr) {
			n = new Node(e);
		}
		else if (e < n->e) {
			add(n->l, e);
		}
		else if(e > n->e) {
			add(n->r, e);
		}
		balance(n);
		n->updateH();
	}
	void _Inorder(Node *&n) {
		if (n == nullptr)return;
		_Inorder(n->l);
		cout << n->e;
		_Inorder(n->r);
	}
	void _InorderAl(Node *&n) {
		if (n == nullptr)return;
		_InorderAl(n->r);
		cout << n->e;
		_InorderAl(n->l);
	}

	void _Search(Node *& n, T e) {
		if (n == nullptr)return;
		else if (e > n->e)_Search(n->r, e);
		else if (e < n->e)_Search(n->l, e);
		else if (e == n->e){
			cout << n->e;
		}
	}
	void _Filtrar(Node *&n, T e) {
		if (n == nullptr)return;
		_Filtrar(n->r,e);
		if (e == n->e) {
			cout << n->e;
		}
		_Filtrar(n->l,e);
	}
public:
	AVLTree()
		: root(nullptr), length(0) {}
	~AVLTree() { destroy(root); }

	int Height() {
		return Node::height(root);
	}
	int Size() {
		return length;
	}
	void Add(T e) {
		add(root, e);
		++length;
	}
	void Search(T e) {
		_Search(root, e);
	}
	void Inorder() {
		_Inorder(root);
	}
	void InorderAl() {
		_InorderAl(root);
	}
	void Filtrar(T e) {
		_Filtrar(root, e);
	}
};

#endif
