
#include <iostream>
#include <cstring>
using namespace std;
#include "Autor.h"
#include "archivoAutor.h"

Autor::Autor()
{
	//ctor
}


		Autor::Autor(int id , bool estado ){
		_idAutor=id ;
		_estado=true;
		}


		void Autor::setId(int id ){
		_idAutor=id ;
		}

		void Autor::setEstado(bool estado){
		_estado=estado;
		}


		int Autor::getId(){
		return _idAutor;
		}


		bool Autor::getEstado(){
		return _estado ;
		}


		int Autor::generarId(){
		archivoAutor autor ;
		int contadorID=autor.getCantidadRegistros();
		return contadorID+1;
		}


		void Autor::cargarAutor(){
		std::string  nombre ;
		std::string  apellido ;
		int dni ;
		cout <<"Ingrese nombre: ";
		cin.ignore();
		getline(cin,nombre);
		cout <<"Ingrese apellido: ";
		getline(cin,apellido);
		cout <<"Ingrese dni: ";
		cin>>dni ;
		_estado=true ;
		setApellido(apellido);
		setNombre(nombre);
		setDni(dni);
		setId(generarId());

		}


		void Autor::mostrarAutor(){
		cout << "ID "<<_idAutor  << endl ;
		cout << "Nombre: "<<getNombre()<< endl ;
		cout << " Apellido: "<< getApellido() << endl ;
		cout << "Dni:  "<<getDni() << endl ;
		if (_estado == true){
			cout << "Activo." << endl ;
		}else {
			cout << "Inactivo. " << endl ;
		}
		}
