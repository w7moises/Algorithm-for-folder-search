
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

void Menu(Controlador * controller) {
	
	
	controller->BuscarArchivos();
	controller->ImprimirArchivos();
	
}
void main() {
	Controlador * controller;
	controller = new Controlador();
	
	Menu(controller);
	

	
	cin.get(), cin.ignore();
}