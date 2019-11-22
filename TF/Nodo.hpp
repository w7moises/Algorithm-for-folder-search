#ifndef __NODO_HPP__
#define __NODO_HPP__
template<class T>
class Node {
public:
	Node *right;
	Node *left;
	T  key;
	int altura;

public:
	Node(T key) {
		right = nullptr;
		left = nullptr;
		this->key = key;
		altura = 0;
	}


};
#endif // !__NODO_HPP__
