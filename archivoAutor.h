#ifndef ARCHIVOAUTOR_H
#define ARCHIVOAUTOR_H
#include "Autor.h"
#include <string>

class archivoAutor
{
	public:
		archivoAutor();
		archivoAutor(std::string ruta);
		int getCantidadRegistros();
		int  grabarRegistro( Autor obj);
		int leerArchivo();
		Autor getRegistro(int pos);
		Autor getRegistroId(int idAutor);




	private:
		char _nombre[30];
};

#endif // ARCHIVOAUTOR_H
