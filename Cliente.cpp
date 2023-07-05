
#include <iostream>
#include <locale.h>
using namespace std;
#include "Cliente.h"
#include "ArchivoCliente.h"

Cliente::Cliente()
{

	_id=-1;
	_estado=false ;
}
	Cliente::Cliente( int id , bool estado ){

	_id=id ;
	_estado=estado ;
	}

	void Cliente::setId(int id){
	_id=id ;
	}
	void Cliente::setEstado (bool estado){

	_estado=estado;
	}
	int  	Cliente::getId(){
	return _id;
	}
	bool Cliente::getEstado(){
	return _estado;
	}

	int Cliente::generarId(){
		archivoCliente clientes ;
		int cant=clientes.getCantidadRegistros();
		return cant+1;

	}

	void Cliente::cargarCliente(){
		std::string  nombre ;
		std::string  apellido ;
		int dni ;


	_id=generarId();
	cout <<"Ingrese nombre: ";
	cin.ignore();
	getline(cin,nombre);
	cout <<"Ingrese apellido: ";
	getline(cin,apellido);
	cout <<"Ingrese dni: ";
	cin>>dni ;
	_estado=true ;
	setDni(dni);
	setApellido(apellido);
	setNombre(nombre);

	}
	void Cliente::mostrarCliente(){
	cout << "ID: " << _id << endl;
	cout << "Nombre: " <<getNombre()<< endl;
	cout << "Apellido: " << getApellido()<<endl;
	cout << "Dni: " << getDni()<<endl;

	}
