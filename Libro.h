#ifndef LIBRO_H
#define LIBRO_H

#include "Autor.h"
class Libro
{
	public:
		Libro();
		void setIdLibro(int id );
		void setDescripcion (std::string descripcion);
		void setImporte (float importe);
		void setStock (int stock);
		void setEstado (bool estado);
		void setGenero(int genero);
		void setAutor(int autor);

		 int getIdLibro();
		 std::string  getDescipcion();
		 float  getImporte();
		 int  getStock();
		 bool getEstado();
		 int getGenero();
		 Autor getAutor();

		void cargarLibro();
		void mostrarLibroVenta();

		int  generarId();


	private:
		int _idLibro;
		char _descripcion[35];
		float _importe ;
		int _stock;
		bool _estadoLibro;
		int _genero; ///un vector del 1 al 10 con todos los generos hay 10 generos
		Autor _autor;
};

#endif // LIBRO_H
