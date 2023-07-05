#include "Libro.h"
#include <cstring>
#include <string.h>
#include "Venta.h"

#ifndef ARCHIVOSTOCKVENTA_H
#define ARCHIVOSTOCKVENTA_H
class archivoStockVenta
{
	public:
		archivoStockVenta();
		archivoStockVenta(std::string ruta);
		///para cuando modifico la venta o elimino una


		///ABML
		void listarLibrosStock();
		int cargarLibro();
		void eliminarLibroPorId();
		void mostrarStockPorId(int id);
		void modificarLibroPorId();


		///Manejar los archivos
		int contarRegistros();
		Libro leerRegistro(int pos );


		///informe
		void  stockPorId(int idLibro);
		void recaudacionPorLibro(int idLibro);
		void recaudacionPorAutor(int idAutor);
		void recaudacionPorGenero(int idGnero);
		int LoginFuncionesAdministradorStock();


		///Otras

		Libro getLibro(int idLibro);
		int devolverStock(Venta venta);
		///este para cuando cargo el stock
		int cargarStock(int id,int cant );
		///validando el id
		int validarId(int idProducto);
		///este es para cuando modifico una venta
		int  modificarStock(Libro aux,int pos );///hacer
		///este es para cuando se vende
		int modificarStock(int idLibro,int cantidad);
		///para la factura
		std::string  getNombreProducto(int id);
	private:
		int modificarLibro(int pos, int idLibro);
	int eliminarLibro( int pos);
	char _nombre[30];
};

#endif // ARCHIVOSTOCKVENTA_H
