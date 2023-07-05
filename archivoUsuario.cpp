
#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdio>
using namespace std;
#include "archivoUsuario.h"
#include "funciones.h"

		archivoUsuario::archivoUsuario(){
			strcpy(_nombre, "usuarios.dat");
		}


		archivoUsuario::archivoUsuario (string ruta){
			strcpy(_nombre,ruta.c_str());
		}
		int archivoUsuario::getCantidadRegistros(){
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;
		}
		fseek(p,0,2);

		int valor = ftell(p);
		fclose(p);
		return valor / sizeof(Usuario);
		}


		int  archivoUsuario::grabarRegistro(Usuario obj){
		FILE *p;
		p=fopen(_nombre,"ab");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;

		}
		int valor=fwrite(&obj, sizeof(Usuario),1,p);
		fclose(p);
		return valor;

		}


		void archivoUsuario::listarArchivoUsuario(){
		int cantUsuarios=this->getCantidadRegistros();
		Usuario aux ;
		if (cantUsuarios==-1){
			cout << "No hay registros cargados aun!"<< endl ;
		}

		for (int x=0; x<cantUsuarios;x++){
			aux=this->getRegistro(x);
				if (aux.getEstado()==true){
					aux.mostrarUsuario();
					cout << endl ;
				}


		}
		}

		void archivoUsuario::listarUsuarioPorId(int id){
		int cantUsuarios=this->getCantidadRegistros();
		Usuario aux ;
		bool encontro=false;
		if (cantUsuarios==-1){
			cout << "No hay registros cargados aun!"<< endl ;
		}

		for (int x=0; x<cantUsuarios;x++){
			aux=this->getRegistro(x);
				if (aux.getID()==id && aux.getEstado()==true && encontro==false){
					encontro=true;
					aux.mostrarUsuario();
					cout << endl ;
				}


		}
		if (encontro==false){
			cout << "No se encontro usuario con ese numero de ID"<< endl ;
		}

		}



		Usuario archivoUsuario::getRegistro(int pos){
		Usuario aux ;
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			aux.setDni(-1); ///validar
			return aux ;
		}

		fseek(p,sizeof(Usuario)*pos,0);
		fread(&aux,sizeof(Usuario),1,p);
		fclose(p);
		return aux ;
		}

		Usuario archivoUsuario:: getRegistro( std::string nombre){
		Usuario aux ;
		int cantUsuarios=this->getCantidadRegistros();
		for (int x=0 ; x<cantUsuarios;x++){
			aux=this->getRegistro(x);
			if (nombre == aux.getUsuario() && aux.getEstado()== true ){
				return aux;
			}

			aux.setDni(-1);///validar en main o funcion
			return aux;
		}

		}

		/*int archivoUsuario::validarUsuarioAdministrador(Usuario aux){
		 Usuario aux1;
		int cantUsuarios = this->getCantidadRegistros();

		for (int x = 0; x < cantUsuarios; x++) {
		aux1 = this->getRegistro(x);
		if (aux.getUsuario() == aux1.getUsuario() && aux1.getEstado() == true && aux.getAdministrador()==true && aux1.getAdministrador()==true) {
		if (aux.getContrasena() == aux1.getContrasena()) {
                return 1; // Encontró y las credenciales son correctas
            } else {
                return -1; // Contraseña incorrecta
            }
        }
    }

    return -1; // No se encontró el usuario

		}*/


	int archivoUsuario::validarUsuarioAdministrador(Usuario aux) {
	Usuario aux1;
	int cantUsuarios = this->getCantidadRegistros();

	for (int x = 0; x < cantUsuarios; x++) {
	aux1 = this->getRegistro(x);
	if (aux.getUsuario() == aux1.getUsuario() && aux.getContrasena() == aux1.getContrasena() && aux1.getAdministrador()==true) {
		return 1; // Usuario encontrado y es administrador
	}
	}

	return -1; // No se encontró el usuario o no es administrador
	}

		int archivoUsuario::validarUsuario(Usuario aux) {
    Usuario aux1;
    int cantUsuarios = this->getCantidadRegistros();

    for (int x = 0; x < cantUsuarios; x++) {
        aux1 = this->getRegistro(x);
        if (aux.getUsuario() == aux1.getUsuario() && aux1.getEstado() == true) {
            if (aux.getContrasena() == aux1.getContrasena()) {
                return 1; // Encontró y las credenciales son correctas
            } else {
                return -1; // Contraseña incorrecta
            }
        }
    }

    return -1; // No se encontró el usuario
}

		std::string  archivoUsuario::getNombre(std::string nombreUsuario){
		Usuario aux ;
		int cantUsuarios=this->getCantidadRegistros();
		for (int x=0; x<cantUsuarios;x++){
			aux=this->getRegistro(x);
			if (aux.getUsuario() == nombreUsuario ){
				return aux.getNombre();
			}
		}
		return "Vacio";
		}

	void archivoUsuario::eliminarUsuarioPorId(int id){
	Usuario aux ;
	char r;
	bool encontrado=false ;
	int valor ;
	int cantUsuarios=this->getCantidadRegistros();

	for(int x=0; x<cantUsuarios;x++){
		aux=this->getRegistro(x);
		if (aux.getID() == id && aux.getEstado()==true  ){
			encontrado=true;
			cout << endl << "Usuario: "<< endl ;
			aux.mostrarUsuario();
			cout << endl ;
			cout << "Estas seguro de eliminar este registros: s/n: "<< endl ;
			cin >> r ;
			if (r=='s'|| r=='S'){
				valor=this->eliminarUsuario(x);
				if (valor==1){
					cout <<"Eliminado con exito!" << endl ;
				}else {
					cout <<"No se pudo eliminar"<< endl;
				}
			}else {
					cout<< "De acuerdo"<< endl;
			}
		}
	}

	if (encontrado==false){
		cout << "No se encontro este id de usuario, por lo tanto no se pudo eliminar!"<< endl ;
	}

	}

	int archivoUsuario::eliminarUsuario(int pos){
	Usuario aux;
	FILE *p;
	p=fopen(_nombre,"rb+");
	if (p==NULL){
		cout << "No se pudo abrir el archivo!"<< endl ;
		return -1;
	}
	int valor ;
	fseek(p,sizeof(Usuario)*pos,0);
	fread(&aux,sizeof(Usuario),1,p);
	aux.setEstado(false);
	fseek(p,sizeof(Usuario)*pos,0);
	valor=fwrite(&aux,sizeof(Usuario),1,p);
	fclose(p);
	return valor ;
	}


	int archivoUsuario::cargarUsuario(){
	Usuario aux ;
	aux.cargarUsuario();
	if (this->grabarRegistro(aux)==1){
		return 1;
	}
	return -1; ///validar en menu

	}

	int archivoUsuario::cargarUsuarioAdministrador(){
	Usuario aux ;
	aux.cargarUsuarioAdministrador();
	if (this->grabarRegistro(aux)==1){
		return 1;
	}
	return -1; ///validar en menu


	}


	void archivoUsuario::modificarUsuarioPorID(int id){
	Usuario aux ;
	char r;
	bool encontrado=false ;
	int valor ;
	int cantUsuarios=this->getCantidadRegistros();

	for(int x=0; x<cantUsuarios;x++){
		aux=this->getRegistro(x);
		if (aux.getID() == id && aux.getEstado()==true  ){
			encontrado=true;
			cout << endl << "Usuario: "<< endl ;
			aux.mostrarUsuario();
			cout << endl ;
			cout << "Estas seguro de modificar este registros?  s/n: "<< endl ;
			cin >> r ;
			if (r=='s'|| r=='S'){
					if (aux.getAdministrador()==true){
						valor=this->modificarUsuarioAdministrador(x,aux.getID());
				if (valor==1){
					cout <<"Modificado con exito!" << endl ;
				}else {
					cout <<"No se pudo modificado"<< endl;
				}
				}
					else{

				valor=this->modificarUsuario(x,aux.getID());
				if (valor==1){
					cout <<"Modificado con exito!" << endl ;
				}else {
					cout <<"No se pudo modificar"<< endl;
				}
			}

		}
				else {
					cout<< "De acuerdo"<< endl;
				}
		}
	}

	if (encontrado==false){
		cout << "No se encontro este id de usuario, por lo tanto no se pudo modificar!"<< endl ;
	}


	}

		int archivoUsuario::modificarUsuario(int pos,int idUsuario){
		FILE *p ;
		p=fopen(_nombre,"rb+");
		if (p==NULL){
			cout << "No se pudo acceder al archivo. "<< endl;
			return -1 ;
		}
		int valor ;
		Usuario aux ;
		fseek(p,sizeof(Usuario)*pos,0);
		fread(&aux,sizeof(Usuario),1,p);
		aux.cargarUsuario();
		aux.setID(idUsuario);
		fseek(p,sizeof(Usuario)*pos,0);
		valor=fwrite(&aux,sizeof(Usuario),1,p);
		fclose(p);
		return valor ;
		}

		int archivoUsuario::modificarUsuarioAdministrador(int pos,int idUsuario){
		FILE *p ;
		p=fopen(_nombre,"rb+");
		if (p==NULL){
			cout << "No se pudo acceder al archivo. "<< endl;
			return -1 ;
		}
		int valor ;
		Usuario aux ;
		fseek(p,sizeof(Usuario)*pos,0);
		fread(&aux,sizeof(Usuario),1,p);
		aux.cargarUsuarioAdministrador();
		aux.setID(idUsuario);
		fseek(p,sizeof(Usuario)*pos,0);
		valor=fwrite(&aux,sizeof(Usuario),1,p);
		fclose(p);
		return valor ;


		}
