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
	int filtro;

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
	bool operator<=(Archivo  rhs) {
		return fsi <= rhs.fsi;
	}
	bool operator>( Archivo  rhs)  {
		return fsi> rhs.fsi;
	}
	
	
};
#endif // !__ARCHIVO_HPP__
	