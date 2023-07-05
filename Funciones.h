#include "Venta.h"
#include <string>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///funciones globales

void mostrarTicket(int idVenta, Fecha fechaVenta,Cliente cliente  );
void imprimirTicket(int idVenta, Fecha fechaVenta,Cliente cliente,std::string nombreArchivo  );
std::string generarNombreTicket(int idVenta) ;
int loginFuncionesAdministrador();



#endif // FUNCIONES_H_INCLUDED
