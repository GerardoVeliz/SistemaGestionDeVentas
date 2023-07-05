#ifndef ARCHIVOSTOCKALQUILER_H
#define ARCHIVOSTOCKALQUILER_H
#include "Libro.h"

class archivoStockAlquiler
{
	public:
		archivoStockAlquiler();
		archivoStockAlquiler(string nombre);

		int cargarStock();
		int contarRegistros();
		Libro leerRegistro(int pos );

	private:
		char _nombre[30];
};

#endif // ARCHIVOSTOCKALQUILER_H
