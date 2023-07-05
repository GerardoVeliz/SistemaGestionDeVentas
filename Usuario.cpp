

#include <iostream>
#include <locale.h>
#include <cstring>
using namespace std;
#include "Usuario.h"
#include "archivoUsuario.h"

Usuario::Usuario()
{
strcpy(_usuario,"vacio");
strcpy(_contrasena,"vacio");
_estado=false ;
}

	void Usuario::setUsuario(std::string usuario){
	strcpy(_usuario,usuario.c_str());
	}
	void Usuario::setContrasena(std::string contrasena){
	strcpy(_contrasena,contrasena.c_str());
	}
	void Usuario::setEstado(bool estado){
	_estado=estado;
	}
	std::string  Usuario::getUsuario(){
	std::string nombre ;
	nombre = _usuario;
	return nombre ;
	}
	std::string  Usuario::getContrasena(){
	std::string contrasena;
	contrasena=_contrasena;
	return contrasena;

	}
	bool  Usuario::getEstado(){
	return _estado;
	}
	bool Usuario::getAdministrador(){
	return _administrador;
	}


	void Usuario::cargarUsuario(){
	std::string nombre ;
	std::string apellido;
	int dni;
	cout <<"Ingrese dni: ";
	cin>>dni ;
	cout <<"Ingrese nombre: ";
	cin.ignore();
	getline(cin,nombre);
	cout <<"Ingrese apellido: ";
	getline(cin,apellido);
	cout <<"ingrese nombre de usuario: ";
	cin>>_usuario;
	cout <<"ingrese contrasena : ";
	cin>>_contrasena;
	_estado=true ;
	setAdministrador(false);
	setDni(dni);
	setApellido(apellido);
	setNombre(nombre);
	_idUsuario=generarID();

	}


	void Usuario::cargarUsuarioAdministrador(){
	std::string nombre ;
	std::string apellido;
	int dni;
	cout <<"Ingrese dni: ";
	cin>>dni ;
	cout <<"Ingrese nombre: ";
	cin.ignore();
	getline(cin,nombre);
	cout <<"Ingrese apellido: ";
	getline(cin,apellido);
	cout <<"ingrese nombre de usuario: ";
	cin>>_usuario;
	cout <<"ingrese contrasena : ";
	cin>>_contrasena;
	_administrador=true;
	_estado=true ;
	setDni(dni);
	setApellido(apellido);
	setNombre(nombre);
	_idUsuario=generarID();

	}



	void Usuario::mostrarUsuario(){
	if (this->getAdministrador()==true){
		cout <<"Rol: Administrador"<< endl ;
	}else {if(this->getAdministrador()==false){
		cout << "Rol: Vendedor"<< endl ;
	}
	}
	cout << "Id Usuario: "<<_idUsuario<< endl ;
	cout << "Nombre: " <<getNombre()<< endl;
	cout << "Apellido: " << getApellido()<<endl;
	cout << "Dni: " << getDni()<<endl;
	cout << "Nombre de usuario: "<<_usuario<<endl;
	//cout << "pass: " << _contrasena<< endl ;
	if (_estado==true){
		cout << "Estado: activo"<< endl ;
	}else {
		cout <<"iEstado: inactivo" << endl;
	}

	}

	void Usuario::setAdministrador(bool power){
	_administrador=power;
	}
	int Usuario::getID(){
	return _idUsuario;
	}
	void Usuario::setID(int id){
	_idUsuario=id;
	}

	int Usuario::generarID(){
	archivoUsuario usuarios ;
	int cantUsuarios=usuarios.getCantidadRegistros();
	return cantUsuarios+1;


	}
