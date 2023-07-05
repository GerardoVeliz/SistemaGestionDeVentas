#ifndef ARCHIVOUSUARIO_H
#define ARCHIVOUSUARIO_H

#include "Usuario.h"

class archivoUsuario
{
	public:
		///ctres
		archivoUsuario();
		archivoUsuario (std::string ruta);


		///Manejo de archivos
		int getCantidadRegistros();
		int  grabarRegistro(Usuario obj);
		Usuario getRegistro(int pos);

		///ABML
		void listarArchivoUsuario();///muuestra todos los
		void  listarUsuarioPorId(int id);///por id
		void eliminarUsuarioPorId(int id);
		int cargarUsuario();///usuario normal validar en menu
		int cargarUsuarioAdministrador();///usuario administrador  validar en menu
		void modificarUsuarioPorID(int id);///probar

		///Otras
		std::string getNombre(std::string nombreUsuario);
		Usuario getRegistro( std::string nombre);
		int validarUsuario(Usuario aux);
		int validarUsuarioAdministrador(Usuario aux);

	private:
		int modificarUsuario(int pos, int idUsuario);
		int modificarUsuarioAdministrador(int pos,int idUsuario);
		int eliminarUsuario(int pos);
	char _nombre[30];
};

#endif // ARCHIVOUSUARIO_H
