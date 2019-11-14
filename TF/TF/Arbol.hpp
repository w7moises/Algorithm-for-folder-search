#ifndef __ARBOL_HPP__
#define __ARBOL_HPP__
#include <iostream>
#include "Nodo.hpp"
#include "Archivo.hpp"

using namespace std;

template<class T>
class ArbolAVL {
private:
	Node<T>*raiz;
	
	int cant;

	int max(int a, int b) {
		return a > b ? a : b;
	}

	int Altura(Node<T>*nodo) {
		if (nodo == nullptr)return -1;
		return nodo->altura;
	}
	Node<T>* Min(Node<T>*nodo) {
		if (nodo == nullptr)return nullptr;
		else if (nodo->left == nullptr)return nodo;
		else {
			return Min(nodo->left);
		}
	}

	void RotDer(Node<T>*& n) {
		Node<T>*temp = n->left;
		n->left = temp->right;
		n->altura = 1 + max(Altura(n->left), Altura(n->right));
		temp->right = n;
		n = temp;
		n->altura = 1 + max(Altura(n->left), Altura(n->right));
	}
	void RotIzq(Node<T>*& n) {
		Node<T>*temp = n->right;
		n->right = temp->left;
		n->altura = 1 + max(Altura(n->left), Altura(n->right));
		temp->left = n;
		n = temp;
		n->altura = 1 + max(Altura(n->left), Altura(n->right));
	}

	void Balance(Node<T>*&n) {
		int Dif = Altura(n->right) - Altura(n->left);
		if (Dif > 1) {
			if (Altura(n->right->left) > Altura(n->right->right))RotDer(n->right);
			RotIzq(n);
		}
		else if (Dif < -1) {
			if (Altura(n->left->right) > Altura(n->left->left))RotIzq(n->left);
			RotDer(n);
		}
		n->altura = 1 + max(Altura(n->left), Altura(n->right));
	}



	void _Insertar(Node<T>*&nodo, T  e) {
		if (nodo == nullptr) {
			nodo = new Node<T>(e);
			
		}
		else if (e >nodo->key)_Insertar(nodo->right, e);
		else if (e < nodo->key)_Insertar(nodo->left, e);
		Balance(nodo);
	}

	Node<T>* _Eliminar(Node<T>*&n, T  e) {
		Node<T>*aux;
		if (n == nullptr)return nullptr;
		else if (e > n->key)_Eliminar(n->right, e);
		else if (e < n->key)_Eliminar(n->left, e);
		else if (n->right && n->left) {
			aux = Min(n->right);
			n->key = aux->key;
			n->right = _Eliminar(n->right, aux->key);
		}
		else {
			aux = n;
			n = n->right ? n->right : n->left;
			delete aux;
		}
		if (n == nullptr)return n;
		Balance(n);
		return n;
	}

	void _InOrden(Node<T>*& nodo) {
		if (nodo == nullptr)return;
		_InOrden(nodo->left);
		cout<<nodo->key<<endl;
		_InOrden(nodo->right);
	}
	bool _Searchnode(Node<T>*n, T e) {
		if (n == nullptr)return false;
		else if (e == n->key) {
			return true;
		}
		else if (e > n->key)_Searchnode(n->right, e);
		else if (e < n->key)_Searchnode(n->left, e);
		
	}
	
	
public:
	ArbolAVL() {
		raiz = nullptr;
		
	}
	void Insertar(T e) {
		_Insertar(raiz, e);
	}
	void InOrden() {
		_InOrden(raiz);
	}

	void Eliminar(T e) {
		raiz = _Eliminar(raiz, e);
	}
	bool searchNode(T item) {
		return _Searchnode(raiz, item);
	}

};

#endif // !__ARBOL_HPP__
