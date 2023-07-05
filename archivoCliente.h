#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H
#include "Cliente.h"

class archivoCliente
{
	public:
		archivoCliente();
		archivoCliente (string ruta);
		int getCantidadRegistros();
		int  grabarRegistro(Cliente obj);
		bool leerArchivo();
		Cliente getRegistro(int pos);
		Cliente buscarCliente(int id);

	private:
		char _nombre[30];
};

#endif // ARCHIVOCLIENTE_H
