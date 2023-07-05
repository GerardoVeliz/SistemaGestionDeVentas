#ifndef AUTOR_H
#define AUTOR_H

#include "Persona.h"


class Autor : public Persona
{
	public:
		Autor();
		Autor(int id , bool estado );
		void setId(int id );
		void setEstado(bool estado);
		int getId();
		bool getEstado();
		void cargarAutor();
		void mostrarAutor();
		int generarId();

	protected:

	private:

	int _idAutor;
	bool _estado ;
};

#endif // AUTOR_H
