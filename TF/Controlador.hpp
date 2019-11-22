#ifndef __CONTROLADOR_HPP__
#define __CONTROLADOR_HPP__
#include "Archivo.hpp"
#include "avl.hpp"
class Controlador {

	AVLTree<Archivo>*treeName;
	AVLTree<Archivo>*treeSize;
	AVLTree<Archivo>*treeExtension;

public:
	Controlador() {
		treeName = new AVLTree<Archivo>();
		treeSize= new AVLTree<Archivo>();
		treeExtension = new AVLTree<Archivo>();
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
			arc2.SetFiltro(2);
			treeName->Add(arc2);
			arc2.SetFiltro(1);
			treeSize->Add(arc2);
			arc2.SetFiltro(3);
			treeExtension->Add(arc2);
		}
	}
	void ImprimirNombreAs() {
		system("cls");
		treeName->Inorder();
	}
	void ImprimirSizeAs() {
		system("cls");
		treeSize->Inorder();
	}
	void ImprirmirExtensionAs() {
		system("cls");
		treeExtension->Inorder();
	}
	void ImprimirNombreDes() {
		system("cls");
		treeName->InorderAl();
	}
	void ImprimirSizeDes() {
		system("cls");
		treeSize->InorderAl();
	}
	void ImprirmirExtensionDes() {
		system("cls");
		treeExtension->InorderAl();
	}
	void Buscar() {
		string path;
		cout << "Ingrese la ruta del archivo a buscar: ";
		cin >> path;
		Archivo Arc;
		Arc.crear(path);
		Arc.SetFiltro(2);
		treeName->Search(Arc);
		cin.get(), cin.ignore();
	}
	void Filtrar() {
		system("cls");
		int opcion, opcion2;
		int peso;
		string letra;

		cout << "Ingrese el tipo de filtro (1 alfabetico, 2 peso)";
		cin >> opcion;
		if (opcion == 1) {
			cout << " Ingrese el tipo de filtro alfabetico (1 empieza,2 finaliza, 3 contiene): ";
			cin >> opcion2;
			if (opcion2 == 1) {
				cout << "Ingrese el caracter: " << endl;
				cin >> letra;
				Archivo buscar;
				buscar.nombre = letra;
				buscar.filtro = 2;
				buscar.filtro2 = 1;
				treeName->Filtrar(buscar);
				cin.get(), cin.ignore();
			}
			else if (opcion2 == 2) {
				cout << "Ingrese el caracter: " << endl;
				cin >> letra;
				Archivo buscar;
				buscar.nombre = letra;
				buscar.filtro = 2;
				buscar.filtro2 = 2;
				treeName->Filtrar(buscar);
				cin.get(), cin.ignore();
			}
			else if (opcion2 == 3) {
				cout << "Ingrese el caracter: " << endl;
				cin >> letra;
				Archivo buscar;
				buscar.nombre = letra;
				buscar.filtro = 2;
				buscar.filtro2 = 3;
				treeName->Filtrar(buscar);
				cin.get(), cin.ignore();
			}
		}
		else if (opcion == 2) {
			cout << "Ingrese el filtro (1 mayor , 2 menor, 3 igual:";
			cin >> opcion2;
			if (opcion2 == 3) {
				cout << "Ingrese el peso: ";
				cin >> peso;
				Archivo buscar;
				buscar.fsi = peso;
				buscar.filtro = 1;
				buscar.filtro2 = 0;
				treeSize->Filtrar(buscar);

				cin.get(), cin.ignore();
				cin.get(), cin.ignore();
			}
			else if (opcion2 == 2) {
				cout << "Ingrese el peso : ";
				cin >> peso;
				Archivo buscar;
				buscar.fsi = peso;
				buscar.filtro = 1;
				buscar.filtro2 = 1;
				treeSize->Filtrar(buscar);

				cin.get(), cin.ignore();
				cin.get(), cin.ignore();
			}
			else if (opcion2 == 1) {
				cout << "Ingrese el peso : ";
				cin >> peso;
				Archivo buscar;
				buscar.fsi = peso;
				buscar.filtro = 1;
				buscar.filtro2 = 2;
				treeSize->Filtrar(buscar);

				cin.get(), cin.ignore();
				cin.get(), cin.ignore();
			}
		}
	
	}
};

#endif // !__CONTROLADOR_HPP__
