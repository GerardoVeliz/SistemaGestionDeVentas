
#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdio>
using namespace std;

#include "archivoCliente.h"
#include "Cliente.h"

#include "Funciones.h"

archivoCliente::archivoCliente()
{
	strcpy(_nombre,"clientes.dat");
}


		archivoCliente::archivoCliente (string ruta){
			strcpy(_nombre, ruta.c_str());
		}

		int archivoCliente::getCantidadRegistros(){
			FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;
		}
		fseek(p,0,2);

		int valor = ftell(p);
		fclose(p);
		return valor / sizeof(Cliente);
		}


		int  archivoCliente::grabarRegistro(Cliente obj){
			FILE *p;
		p=fopen(_nombre,"ab");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;

		}
		int valor=fwrite(&obj, sizeof(Cliente),1,p);
		fclose(p);
		return valor;

		}


		bool archivoCliente::leerArchivo(){
			Cliente aux;
				FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return false  ;
		}
		while (fread(&aux,sizeof(Cliente),1,p)==1){
			aux.mostrarCliente();
			cout << endl ;
		}
			fclose(p);
			return true ;
		}


		Cliente archivoCliente::getRegistro(int pos){
		Cliente aux ;
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			aux.setDni(-1); ///validar
			return aux ;
		}

		fseek(p,sizeof(Cliente)*pos,0);
		fread(&aux,sizeof(Cliente),1,p);
		fclose(p);
		return aux ;
		}

		Cliente  archivoCliente::buscarCliente(int id){
		int cantClientes=this->getCantidadRegistros();
		Cliente aux;
		for (int x=0; x<cantClientes;x++){
				aux=this->getRegistro(x);
			 if (aux.getId() == id && aux.getEstado() == true){
				return aux ;
			 }


		}
			 cout <<"Cliente no encontrado!"<< endl ;
			 aux.setDni(0);
			 return aux ;///validar dni




		}


