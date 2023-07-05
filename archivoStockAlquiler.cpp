
#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdio>
using namespace std;
#include "archivoStockAlquiler.h"
#include "Libro.h"

archivoStockAlquiler::archivoStockAlquiler()
{
	strcpy(_nombre, "stockalquiler.dat");
}

archivoStockAlquiler::archivoStockAlquiler(	string nombre){
	strcpy(_nombre, nombre.c_str());
}

archivoStockAlquiler::cargarStock(){
FILE *p ;
p=fopen(_nombre , "ab");
if (p==NULL){
	cout << "No se pudo acceder al archivo. " ;
	return -1 ;
}
Libro aux ;
aux.cargarLibroAlquiler();
int valor = fwrite(&aux,sizeof(Libro),1,p);
fclose(p);
return valor ;

}
archivoStockAlquiler::contarRegistros(){
FILE *p ;
p=fopen(_nombre , "rb");
if (p==NULL){
	cout << "No se pudo acceder al archivo. ";
	return -1;
}
fseek(p,0,2);
int valor = ftell(p);
fclose(p);
return valor/sizeof(Libro);

}

