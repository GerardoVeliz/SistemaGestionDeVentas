
#include <iostream>
#include <locale.h>
#include <cstring>
using namespace std;
#include "Persona.h"

	Persona::Persona(){
	strcpy(_nombre, "vacio");
	strcpy(_apellido,"vacio");
	_dni=0 ;
	}


	Persona::Persona(std::string nombre, std::string apellido , int dni ){
	strcpy(_nombre, nombre.c_str());
	strcpy(_apellido,apellido.c_str());
	_dni=dni ;
	}

	void Persona::setNombre( std::string nombre){
	strcpy(_nombre,nombre.c_str());
	}
	void Persona::setApellido(std::string apellido){
	strcpy(_apellido,apellido.c_str());
	}
	void Persona::setDni(int dni ){
	_dni=dni ;
	}
	std::string Persona:: getNombre(){
	std::string nombre;
	nombre=_nombre ;
	return nombre ;
	}
	std::string Persona::getApellido(){
	std::string apellido ;
	apellido=_apellido;
	return apellido ;

	}
	int  Persona::getDni(){
	return _dni;
	}
