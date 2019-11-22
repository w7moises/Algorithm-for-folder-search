#ifndef __ARCHIVO_HPP__
#define __ARCHIVO_HPP__
#include <string>
#include <iostream>
#include <filesystem>
using namespace System;
using namespace std;
namespace fs = std::experimental::filesystem;
class Archivo {
public:
	string path;
	string nombre;
	string extension;
	int fsi;
	int filtro,filtro2;

public:
	Archivo( ) {
	
	}
	void crear(string path) {
		this->path = path;
		String^ str2 = gcnew String(path.c_str());
		nombre = getFileName(path);
		extension = getExtension(path);
		try
		{
			fsi = fs::file_size(path) / 1024;
		}
		catch (const std::exception&)
		{
			fsi = 0;
		}
	}
	string getFileName(const string& s) {
		char sep = '/';
#ifdef _WIN32
		sep = '\\';
#endif
		size_t i = s.rfind(sep, s.length());
		if (i != string::npos) {
			return(s.substr(i + 1, s.length() - i));
		}
		return("");
	}
	string getExtension(const string& s) {
		char sep = '.';
#ifdef _WIN32
		sep = '.';
#endif
		size_t i = s.rfind(sep, s.length());
		if (i != string::npos) {
			return(s.substr(i + 1, s.length() - i));
		}
		return("");
	}
	friend ostream& operator<< (ostream& os, Archivo  c) {
		if (c.extension == "") {
			os << c.nombre << endl;
			return os;
		}
		else {
			os << c.nombre << " | " << c.fsi << " kb" << endl;
			return os;
		}
	}
	void SetFiltro(int filtro) {
		this->filtro = filtro;
	}
	bool operator<(Archivo  rhs) {
		if (filtro == 1) {
			return fsi < rhs.fsi;
		}
		else if (filtro == 2) {
			return nombre < rhs.nombre;
		}
		else if (filtro == 3) {
			return extension < rhs.extension;
		}
	
	
	}
	bool operator>(Archivo  rhs) {
		if (filtro == 1) {
			return fsi >= rhs.fsi;
		}
		else if (filtro == 2) {
			return nombre > rhs.nombre;
		}
		else if (filtro == 3) {
			return extension >= rhs.extension;
		}
	
	}
	bool operator==(Archivo  rhs) {
		if (filtro == 1) {
			if (filtro2 == 0) {
				return fsi == rhs.fsi;
			}
			else if (filtro2 == 1) {
				return fsi > rhs.fsi;
			}
			else if (filtro2 == 2) {
				return fsi < rhs.fsi;
			}
		}
		else if (filtro == 2) {
			if (filtro2 == 1) {
				return nombre[0] == rhs.nombre[0];
			}
			else if (filtro2 == 2) {
				char nombreC = rhs.nombre[rhs.nombre.size() - 1];
				char comp = nombre[nombre.size() - 1];
				return comp == nombreC;
			}
			else if (filtro2 == 3) {
				int cont = 0;
				char comp = nombre[nombre.size() - 1];
				for (int i = 0; i < rhs.nombre.size(); i++)
				{
					if (comp == rhs.nombre[i]) { cont++; }
					
				}
				if (cont >= 1)return true; else return false;
				
			}
			else {
			return nombre == rhs.nombre;
			}
		}
		else if (filtro == 3) {
			return extension == rhs.extension;
		}
	
	
	}
	
	
};
#endif // !__ARCHIVO_HPP__
	