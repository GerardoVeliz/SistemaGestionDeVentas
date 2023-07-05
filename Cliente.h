#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"


class Cliente : public Persona
{
	public:
	Cliente(  int id , bool estado );
	Cliente() ;
	void setId(int id);
	void setEstado (bool estado);
	int  	getId();
	bool getEstado();
	void cargarCliente();
	void mostrarCliente();
	int generarId();
	private:
		int _id;
		bool _estado;
};

#endif // CLIENTE_H
