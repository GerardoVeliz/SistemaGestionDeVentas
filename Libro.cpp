
#include <iostream>
#include <locale.h>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "archivoStockVenta.h"
#include "Autor.h"
#include "archivoAutor.h"

		Libro::Libro()
		{
			//ctor
		}

		void Libro::setIdLibro(int id ){
		_idLibro=id;
		}
		void Libro::setDescripcion (std::string descripcion){
		strcpy(_descripcion , descripcion.c_str());
		}
		void Libro::setImporte (float importe){
		_importe=importe;
		}
		void Libro::setStock (int stock){
		_stock=stock;
		}
		void Libro::setEstado (bool estado){
		_estadoLibro=estado ;
		}



		void Libro::setGenero(int genero){
		_genero=genero;
		}
		int Libro::getIdLibro(){
		return _idLibro;
		}
		 std::string Libro:: getDescipcion(){
		 std::string descripcion ;
		 descripcion=_descripcion;
		 return descripcion;
		 }
		 float  Libro::getImporte(){
		 return _importe;
		 }
		 int  Libro::getStock(){
		 return _stock;
		 }
		 bool Libro::getEstado(){
		 return _estadoLibro;
		 }

		int Libro::getGenero(){
		return _genero;
		}
		Autor Libro::getAutor(){
		return _autor;
		}

		void Libro::cargarLibro(){
			char  r;
		std::string descripcion;
		setIdLibro(generarId()+1);
		cin.ignore ();
		cout << "Ingrese Titulo del Libro: ";
		getline(cin,descripcion);
		cout << "Importe: ";
		cin>>_importe ;
		cout << "Cantidad ingresada de stock: ";
		cin>> _stock;
		cout << "Ingrese el numero de genero: "<< endl ;
		cout << "(1.CienciaFiccion, 2.Infantil, 3.Drama, 4.Fantastico, 5.Biografias 6.Romantico, 7.Otros)  : " << endl ;
		cin >>_genero;
		cout << "Es un autor ya registrado?  s(si)/n(no): "<< endl ;
		cin >> r;
		if (r== 's' || r== 'S'){
				int id ;
		cout << "ingrese el id ";
		cin>>id;
		archivoAutor autores;
		int cantAutores=autores.getCantidadRegistros();
		Autor aux ;
		for (int x=0 ; x<cantAutores;x++){
				aux=autores.getRegistro(x);
			if (aux.getId()== id  && aux.getEstado()==true){
				_autor.setDni(aux.getDni());
				_autor.setApellido(aux.getApellido());
				_autor.setNombre(aux.getNombre());
				_autor.setId(aux.getId());
				_autor.setEstado(true);
				cout << "Autor encontrado!" << endl ;
			}

		}
		}
		 else{
			archivoAutor autores;
			_autor.cargarAutor();
			if (autores.grabarRegistro(_autor)== 1){
				cout << endl <<"Autor Registrado correctamente! " << endl ;
			}else{
				cout << endl << "Error al registrar Autor."<< endl;
			}
		}
		 _estadoLibro=true ;
		 setDescripcion(descripcion);

		}

		void Libro::mostrarLibroVenta(){
		cout<<"Id Libro: #"<< _idLibro<<endl;
		cout<<"Titulo: "<<_descripcion<<endl;
		cout<<"Importe: $"<< _importe<<endl;
		cout<<"Stock : "<<_stock<<endl;
		cout << "Autor: "<<endl ;
		_autor.mostrarAutor();
		switch(_genero){
		case 1:
			cout << "Genero: Ciencia Ficcion"<< endl;
		break;
		case 2:
			cout << "Genero: Infantil"<< endl;
		break;
		case 3:
			cout << "Genero: Drama"<< endl;
		break;
		case 4:
			cout << "Genero: Fantastico"<< endl;
		break;
		case 5:
			cout << "Genero: Biografia"<< endl;
		break;
		case 6:
			cout << "Genero: Romantico "<< endl;
		break;
		case 7 :
			cout << "Genero: Otros "<< endl ;
			break;
	//CienciaFiccion, 2.Infantil, 3.Drama, 4.Fantastico, 5.Biografias 6.Romantico, 7.Otros)

		}

		}

		int Libro::generarId(){
		archivoStockVenta ventas ;
		int  contadorId=ventas.contarRegistros();
		return contadorId ;
		}


