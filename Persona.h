#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
	public:
		Persona();
		Persona(std::string nombre, std::string apellido , int dni );

	void setNombre( std::string nombre);
	void setApellido(std::string apellido);
	void setDni(int dni );
	std::string  getNombre();
	std::string getApellido();
	int  getDni();


	private:
		char _nombre [30];
		char _apellido [30];
		int _dni ;

};

#endif // PERSONA_H
