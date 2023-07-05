#include <iostream>
#include <cstring>

using namespace std;
#include "Cliente.h"
#include "Fecha.h"
#include"Usuario.h"
#include "Venta.h"
#include "Libro.h"
#include "Funciones.h"
#include "ArchivoVenta.h"
#include "Menu.h"
#include "archivoStockVenta.h"
#include "archivoCliente.h"
#include "Cliente.h"
#include <iomanip>
#include "archivoUsuario.h"
#include "archivoAutor.h"



int main(){
archivoAutor autores ;
archivoStockVenta stock;
archivoUsuario usuarios ;
ArchivoVenta ventas ;
//autores.leerArchivo();;
Menu menu ;


menu.mensajeBienvenida();
menu.login();
menu.mensajeDespedida();


return 0; }
