#ifndef __CONTROLADOR_HPP__
#define __CONTROLADOR_HPP__
#include "Archivo.hpp"
#include "avl.hpp"
class Controlador {

	AVLTree<Archivo>*tree;

public:
	Controlador() {
		tree = new AVLTree<Archivo>();
		}
	void BuscarArchivos() {
		system("cls");
		string path;
		cout << "Ingrese la ruta: ";
		cin >> path;
		
		Archivo arc2;
		string test;
		for (const auto & entry : fs::directory_iterator(path)) {
			test = entry.path().string();
			arc2.crear(test);
			tree->Add(arc2);	
		}
	}
	void ImprimirArchivos() {
		tree->Inorder();
	}
};

#endif // !__CONTROLADOR_HPP__
