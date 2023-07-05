#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"


class Usuario : public Persona
{
	public:
	Usuario();
	void setUsuario(std::string usuario);
	void setContrasena(std::string contrasena);
	void setEstado(bool estado);

	std::string  getUsuario();
	std::string  getContrasena();
	bool getAdministrador();
	bool  getEstado();
	int getID();
	void setID(int id);
	void cargarUsuario();
	void cargarUsuarioAdministrador();
	void mostrarUsuario();
	void setAdministrador(bool power);

	private:
		int  generarID();
		int _idUsuario;
		char _usuario[30];
		char  _contrasena[30];
		bool _administrador;
		bool _estado;
};

#endif // USUARIO_H
