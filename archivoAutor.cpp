

#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdio>
using namespace std;

#include "archivoAutor.h"

archivoAutor::archivoAutor()
{
	strcpy(_nombre, "autores.dat");
}


		archivoAutor::archivoAutor(string ruta){
		strcpy(_nombre, ruta.c_str());
		}

		int archivoAutor::getCantidadRegistros(){
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;
		}
		fseek(p,0,2);

		int valor = ftell(p);
		fclose(p);
		return valor / sizeof(Autor);
		}


		int archivoAutor::grabarRegistro(Autor obj){
		FILE *p;
		p=fopen(_nombre,"ab");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;

		}
		int valor=fwrite(&obj, sizeof(Autor),1,p);
		fclose(p);
		return valor;

		}



		int archivoAutor::leerArchivo(){
			Autor aux;
				FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return false  ;
		}
		while (fread(&aux,sizeof(Autor),1,p)==1){
				if (aux.getEstado()){
			aux.mostrarAutor();
			cout << endl ;

				}
		}
			fclose(p);
			return true ;

		}
		Autor archivoAutor::getRegistro(int pos){
					Autor aux ;
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			aux.setDni(-1); ///validar
			return aux ;
		}

		fseek(p,sizeof(Autor)*pos,0);
		fread(&aux,sizeof(Autor),1,p);
		fclose(p);
		return aux ;

		}


		Autor archivoAutor::getRegistroId(int idAutor){
		int  cantAutor=this->getCantidadRegistros();
		Autor aux;
		bool encontro=false;
		for (int x=0; x<cantAutor;x++){
			aux=this->getRegistro(x);
			if (aux.getId() == idAutor && aux.getEstado()==true){
				encontro=true ;
				return aux;
			}
		}

		if (encontro==false){
			cout << "Id de autor no encontrado!"<< endl;
			aux.setId(-1);
			return aux ; ///validar en menu o funcion
		}


		}
