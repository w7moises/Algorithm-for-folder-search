
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include "Archivo.hpp"

#include <vector>
#include <iostream>
#include <filesystem>
#include "Controlador.hpp"
using namespace std;

void Imprimir(Controlador * controller) {
	system("cls");
	int filtro;
	bool filtro2;
	cout << "Ingrese el filtro (1 alfabetico, 2 peso , 3 extension) ";
	cin >> filtro;
	cout << "Descendente o ascendete ( 0 o 1)";
	cin >> filtro2;
	if (filtro == 1) {
		if (filtro2 == true)controller->ImprimirNombreDes();
		else controller->ImprimirNombreAs();
	}
	else if (filtro == 2) {
		if (filtro2 == true)controller->ImprimirSizeDes();
		else controller->ImprimirSizeAs();
	}
	else if (filtro == 3) {
		if (filtro2 == true)controller->ImprirmirExtensionDes();
		else controller->ImprirmirExtensionAs();
	}
	cin.get(), cin.ignore();
}

void main() {
	Controlador * controller;
	controller = new Controlador();
	int opcion;
	do {
		system("cls");
		cout << "--Menu--" << endl;
		cout << "1)--Escanear archivos--" << endl;
		cout << "2)--Imprimir--" << endl;
		cout << "3)--Buscar--" << endl;
		cout << "4)--Filtrar--" << endl;
		cout << "0)--Salir--" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1: controller->BuscarArchivos(); break;
		case 2: Imprimir(controller); break;
		case 3: controller->Buscar(); break;
		case 4:controller->Filtrar(); break;
		}
	} while (opcion != 0);
	
	
	cin.get(), cin.ignore();
}