
#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdio>
using namespace std;
#include "archivoStockVenta.h"
#include "Libro.h"
#include "archivoAutor.h"
#include "ArchivoVenta.h"
#include <iomanip>
#include "Funciones.h"
#include "Usuario.h"
#include "archivoUsuario.h"
#include <conio.h>

archivoStockVenta::archivoStockVenta()
{
	strcpy(_nombre,"stockventa.dat");
}

archivoStockVenta::archivoStockVenta(string ruta){
	strcpy(_nombre,ruta.c_str());
}

		int archivoStockVenta::cargarLibro(){
		FILE *p;
		p=fopen(_nombre,"ab");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ; ;
		}
		Libro libro;
		libro.cargarLibro(); ///hacer que se autogeenre el id;
		int valor=fwrite(&libro,sizeof(Libro),1,p);
		fclose(p);
		return valor ;
		}

		int archivoStockVenta::contarRegistros(){
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ; ;
		}
		fseek(p,0,2);

		int valor = ftell(p);
		fclose(p);
		return valor / sizeof(Libro);
		}

		Libro archivoStockVenta::leerRegistro(int pos ){
		Libro aux ;
		FILE *p;
		p=fopen(_nombre,"rb");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			aux.setIdLibro(-1); ///validar
			return aux ;
		}

		fseek(p,sizeof(Libro)*pos,0);
		fread(&aux,sizeof(Libro),1,p);
		fclose(p);
		return aux ;
		}

		int archivoStockVenta::validarId(int idProducto){
		FILE *p;
		p=fopen(_nombre, "rb");
		if (p==NULL){
			cout << "No se pudo acceder al archivo."<< endl ;
			return -1 ;//no pudo abrir el archivo
		}
		Libro aux ;
		while(fread(&aux,sizeof(Libro),1,p)==1){
			if (aux.getIdLibro() == idProducto){
				return 1;//encontro
			}
		}
		fclose(p);
		return 2;//no encontro

		}
		///este es para cuando modifico una venta
		int  archivoStockVenta::modificarStock(Libro aux ,int pos ){


		FILE *p;
		p=fopen(_nombre,"rb+");
		if(p==NULL){
			cout << "No se pudo abrir el archivo." << endl;
			return -1 ;
		}
		fseek(p,sizeof(Libro)*pos,0);
		int valor=fwrite(&aux,sizeof(Libro),1,p);
		fclose(p);

		return valor ;
		}

		int archivoStockVenta::devolverStock(Venta venta){
		int  cantStock=this->contarRegistros();
		Libro aux ;
		int stock;
		for (int x=0; x<cantStock;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == venta.getIdProducto() && aux.getEstado() == true){
				stock=aux.getStock()+venta.getCantidadVendida();
				aux.setStock(stock);
				int valor=modificarStock(aux,x);
				return valor;
			}
		}
		return -1;
		}

		///este para cuando vendo y se resta
		int archivoStockVenta::modificarStock(int idLibro,int cantidad){
		int cantStock=this->contarRegistros();
		int stock=0;
		Libro aux ;
		for (int x=0; x<cantStock;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == idLibro && aux.getEstado()==true){
				stock=aux.getStock();
				aux.setStock(stock-cantidad);
				int valor= modificarStock(aux,x); ///validar  1 es que lo modifico
				return valor;
			}

		}
		return -1;///no encontro
		}

		string  archivoStockVenta::getNombreProducto(int id){
		Libro aux ;
		int cantLibros=this->contarRegistros();
		for (int x=0 ; x<cantLibros;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == id && aux.getEstado()==true){
				return aux.getDescipcion();
			}
		}

		return "VACIO";

		}

		///este es para cargar stock
		int archivoStockVenta::cargarStock(int id,int cant ){
		int cantStock=this->contarRegistros();
		int stock=0;
		Libro aux ;
		if (cantStock==-1){
			cout << "No hay Registros cargados aun."<< endl ;
		}
		for (int x=0; x<cantStock;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == id && aux.getEstado()==true){
				stock=aux.getStock();
				aux.setStock(stock+cant);
				int valor= modificarStock(aux,x); ///validar  1 es que lo modifico
				return valor;
			}

		}
		return -1;///no encontro

		}

		void archivoStockVenta::listarLibrosStock(){
		int cantLibros=this->contarRegistros();
		Libro aux;
		if (cantLibros==-1){
			cout <<"El archivo esta vacio! "<< endl ;
		}
		for(int x=0 ; x<cantLibros;x++){
			 aux=this->leerRegistro(x);
			 if(aux.getEstado()== true){
				aux.mostrarLibroVenta();
				cout << endl;
			 }
		}



		}

		void archivoStockVenta::modificarLibroPorId(){
		  Libro aux;
        char r;
        bool encontrado=false ;
        int valor;
        int cantLibros=this->contarRegistros();
        int id;
        cout<< "ingrese el Id de libro que quiere modificar "<< endl ;
        cin>>id ;
     for (int x=0; x<cantLibros;x++){
                aux=this->leerRegistro(x);
        if ( aux.getIdLibro()== id && aux.getEstado()== true ){
                        encontrado=true ;
                        cout <<endl <<  "Registro: " << endl ;
                aux.mostrarLibroVenta();
                cout << endl ;
                cout <<"Estas seguro de modificar este registro? s/n : " << endl ;
                cin >> r;
                if (r=='s' || r== 'S'){
                            valor=this->modificarLibro(x,aux.getIdLibro());
                        if (valor==1){
                                cout << "Modificado con exito!"<< endl ;
                        }else {
                                cout << "No se pudo modificar."<< endl ;
                        }
                } else {
                cout << endl  << "De acuerdo." << endl;
                }
        }
     }

     if (encontrado==false){
        cout << endl << "No se encontro ese id de Libro, no se pudo modificar." << endl ;
     }




		}
		int archivoStockVenta::modificarLibro(int pos, int idLibro){
		FILE *p ;
		p=fopen(_nombre , "rb+");
		if(p==NULL){
			cout << "No se pudo acceder al archivo. "<< endl ;
			return -1;
		}
		Libro aux ;
		fseek(p,sizeof(Libro)*pos,0);
		aux.cargarLibro();
		aux.setIdLibro(idLibro);
		int valor ;
		valor=fwrite (&aux , sizeof(Libro),1,p);
		fclose(p);
		return valor ;
		}


	void archivoStockVenta::eliminarLibroPorId(){
        Libro aux;
        char r;
        bool encontrado=false ;
        int valor;
        int cantLibros=this->contarRegistros();
        int id;
        cout<< "ingrese el Id de libro que quiere eliminar: "<< endl ;
        cin>>id ;
     for (int x=0; x<cantLibros;x++){
                aux=this->leerRegistro(x);
        if ( aux.getIdLibro()== id && aux.getEstado()== true ){
                        encontrado=true ;
                        cout <<endl <<  "Registro: " << endl ;
                aux.mostrarLibroVenta();
                cout << endl ;
                cout <<"Estas seguro de eliminar este registro? s/n : " << endl ;
                cin >> r;
                if (r=='s' || r== 'S'){
                            valor= this->eliminarLibro(x);
                        if (valor==1){
                                cout << "Eliminado con exito!"<< endl ;
                        }else {
                                cout << "No se pudo eliminar."<< endl ;
                        }
                } else {
                cout << endl  << "De acuerdo." << endl;
                }
        }
     }

     if (encontrado==false){
        cout << endl << "No se encontro ese id de Libro, no se pudo eliminar." << endl ;
     }
	}


	int archivoStockVenta::eliminarLibro( int pos){
	bool estado=false ;
	FILE *p;
	p=fopen(_nombre, "rb+" );
	if (p==NULL){
	cout <<"No se pudo acceder al archivo."<< endl ;
	return -1 ;
	}
	int valor ;
	Libro obj ;
	fseek(p,sizeof(Libro)*pos,0);
	fread(&obj,sizeof(Venta),1,p);
           obj.setEstado(estado);
              fseek(p,sizeof(Libro)*pos,0);
           valor=fwrite (&obj,sizeof(Libro),1,p);
        fclose(p);
        return valor; ///validar en menu


		}

		///informe
		void archivoStockVenta::stockPorId(int idLibro){
		int cantLibros=this->contarRegistros();
		Libro aux ;
		bool encontro=false ;
		for (int x=0; x<cantLibros;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == idLibro && aux.getEstado() == true){
					encontro=true;
				cout << "Stock Disponible del ID #"<<aux.getIdLibro()<< " es : " << aux.getStock()<< endl ;
			}
		}
		if (encontro==false){
			cout << "No se encontraron libros con ese ID ! "<< endl ;
		}

		}

		void archivoStockVenta::recaudacionPorLibro(int idLibro){
			float  recaudacionTotal=0;
			ArchivoVenta ventas ;
			int cantVentas=ventas.contarRegistros();
			Venta aux ;
			Libro obj;
			int cantLibros=this->contarRegistros();
			///recaudacion mensual
			const int TAM=12 ;
			float vMeses[TAM]={};
			for (int x=0; x<cantVentas ;x++){
					aux=ventas.leerRegistro(x);
			if (aux.getEstado()==true){
				vMeses[aux.getMes()-1]+=aux.getImporte();
				recaudacionTotal+=aux.getImporte();
			}
			}
			obj=this->getLibro(idLibro);
			cout << endl << "Recaudacion" << endl;
			cout << "==========================================" << endl;
			cout << "Libro: " << obj.getDescipcion() << endl;
			cout << "==========================================" << endl;

			string meses[TAM] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};


			cout << left << setw(10) << "Mes" << "CantidadRecaudada" << endl;
			cout << "==========================================" << endl;
			for (int i = 0; i < TAM; ++i) {
			cout << left << setw(10) << meses[i] <<"\t"<< vMeses[i] << endl;
			}

			// Mostrar total recaudado
			cout << "==========================================" << endl;
			cout << left << setw(10) << "Total" << recaudacionTotal << endl;
			cout << "==========================================" << endl;
			cout << endl << endl ;

		}
		void archivoStockVenta::recaudacionPorAutor(int idAutor){
			archivoAutor autores;
			Autor autor;
			float recaudacionTotal=0;
			ArchivoVenta ventas ;
			int cantVentas=ventas.contarRegistros();
			Venta aux ;
			Libro obj;
			string nombre ;
			string apellido;
			bool encontro=false ;
			int cantLibros=this->contarRegistros();
			///recaudacion mensual
			const int TAM=12 ;
			float vMeses[TAM]={};
			for (int x=0; x<cantVentas ;x++){
					aux=ventas.leerRegistro(x);
					obj=this->getLibro(aux.getIdProducto());
			if (obj.getAutor().getId() == idAutor && obj.getAutor().getEstado()==true){
					encontro=true;
				vMeses[aux.getMes()-1]+=aux.getImporte();
				recaudacionTotal+=aux.getImporte();
				nombre=obj.getAutor().getNombre();
				apellido=obj.getAutor().getApellido();
			}
			}

			cout << endl << "Recaudacion" << endl;
			cout << "==========================================" << endl;
			cout << "Autor: " << nombre<<" "<<apellido<< endl;
			cout << "==========================================" << endl;

			// Nombres de los meses
			string meses[TAM] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

			// Mostrar recaudación por mes
			cout << left << setw(10) << "Mes" << "CantidadRecaudada" << endl;
			cout << "==========================================" << endl;
			for (int i = 0; i < TAM; ++i) {
			cout << left << setw(10) << meses[i] <<"\t"<< vMeses[i] << endl;
			}

			// Mostrar total recaudado
			cout << "==========================================" << endl;
			cout << left << setw(10) << "Total" << recaudacionTotal << endl;
			cout << "==========================================" << endl;
			cout << endl << endl ;
		}
		void archivoStockVenta::recaudacionPorGenero(int idGnero){
		const int TAM=7;
		string vGeneros[TAM]={"CienciaFiccion", "Infantil", "Drama", "Fantastico", "Biografias", "Romantico", "Otros" };
		const int tam1=12;
		float vMeses[tam1]={};

			float recaudacionTotal=0;
			ArchivoVenta ventas ;
			int cantVentas=ventas.contarRegistros();
			Venta aux ;
			Libro obj;
			bool encontro=false ;
			int cantLibros=this->contarRegistros();
			///recaudacion mensual
			for (int x=0; x<cantVentas ;x++){
					aux=ventas.leerRegistro(x);
					obj=this->getLibro(aux.getIdProducto());
			if (obj.getGenero() == idGnero){
					encontro=true;
				vMeses[aux.getMes()-1]+=aux.getImporte();
				recaudacionTotal+=aux.getImporte();

			}
			}

			cout << endl << "Recaudacion" << endl;
			cout << "==========================================" << endl;
			cout << "Genero: " <<vGeneros[idGnero-1]<< endl;
			cout << "==========================================" << endl;

			// Nombres de los meses
			string meses[tam1] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

			// Mostrar recaudación por mes
			cout << left << setw(10) << "Mes" << "CantidadRecaudada" << endl;
			cout << "==========================================" << endl;
			for (int i = 0; i < tam1; ++i) {
			cout << left << setw(10) << meses[i] <<"\t"<< vMeses[i] << endl;
			}

			// Mostrar total recaudado
			cout << "==========================================" << endl;
			cout << left << setw(10) << "Total" << recaudacionTotal << endl;
			cout << "==========================================" << endl;
			cout << endl << endl ;




		}



		Libro archivoStockVenta::getLibro(int idLibro){
		int cantLibros=this->contarRegistros();
		bool Encontro=false;
		Libro aux ;
		for (int x=0; x<cantLibros;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == idLibro  && aux.getEstado()==true){
				Encontro=true;
				return aux ;
			}
		}
		if (Encontro==false){
			aux.setIdLibro(-1);
			return aux;///validar
		}

		}

		void archivoStockVenta::mostrarStockPorId(int id){
		int cantLibros=this->contarRegistros();
		Libro aux ;
		bool encontro=false;

		for(int x=0; x<cantLibros;x++){
			aux=this->leerRegistro(x);
			if (aux.getIdLibro() == id && aux.getEstado()==true && encontro==false){
				encontro=true ;
				cout << "La cantidad de stock disponible es : "<< aux.getStock()<< endl ;
			}

		}
		if (encontro==false){
			cout << "No se encontro Libro con ese ID"<< endl ;
		}


		}

		int archivoStockVenta::LoginFuncionesAdministradorStock(){
		Usuario aux ;
	int contIntentos = 3;
	archivoUsuario usuarios;
	string nombreUsuario;
	string pass;
	cout << "====================================" << std::endl;
	cout << "BIENVENIDO AL  LOGIN:!" << std::endl;
	cout << "====================================" << std::endl;
	cout << "Nombre de usuario: ";
	cin >> nombreUsuario;

	cout << "Contrasena: ";
	char ch;
	pass = "";
	while ((ch = _getch()) != '\r') { // Leer caracteres hasta presionar Enter (carácter de retorno de carro)
        if (ch == 8) { // Si se presiona la tecla de retroceso (carácter ASCII 8)
            if (!pass.empty()) {
                pass.pop_back();
                cout << "\b \b"; // Retroceder un espacio, borrar el carácter y retroceder otro espacio
            }
        } else {
            pass += ch;
            cout << "*"; // Mostrar asterisco en lugar del carácter ingresado
        }
    }
	cout << endl;
	cout << "====================================" << std::endl;
	int validacion=0;
	aux.setContrasena(pass);
	aux.setUsuario(nombreUsuario);
	validacion=usuarios.validarUsuarioAdministrador(aux);
	switch(validacion){
	case 1:
	system("cls");
	cout << "====================================" << std::endl;
	cout << "Hola! "<< usuarios.getNombre(nombreUsuario)<< endl ;
	cout << "====================================" << std::endl;
	return 1;
	break;
	case -1:

	cout << "El usuario o contrasena ingresado es erroneo o no tiene el rol administrador, por favor intente otra vez!!."<< endl ;
	contIntentos--;
	cout << "intentos restantes: #" << contIntentos<< endl;
	system("pause");
	system("cls");

	while(contIntentos!=0){
	cout << "====================================" << std::endl;
	cout << " LOGIN:!" << std::endl;
	cout << "====================================" << std::endl;
	cout << "Nombre de usuario: ";
	cin >> nombreUsuario;

	cout << "Contrasena: ";
	char ch;
	pass = "";
	while ((ch = _getch()) != '\r') { // Leer caracteres hasta presionar Enter (carácter de retorno de carro)
	if (ch == 8) { // Si se presiona la tecla de retroceso (carácter ASCII 8)
		if (!pass.empty()) {
		pass.pop_back();
		cout << "\b \b"; // Retroceder un espacio, borrar el carácter y retroceder otro espacio
		}
	} else {
		pass += ch;
		cout << "*"; // Mostrar asterisco en lugar del carácter ingresado
	}
	}
	cout << endl;
	cout << "====================================" << std::endl;
		aux.setContrasena(pass);
		aux.setUsuario(nombreUsuario);
		validacion=usuarios.validarUsuarioAdministrador(aux);
		if (validacion==1){
			system("cls");
			cout << "====================================" << std::endl;
			cout << "Hola! "<< usuarios.getNombre(nombreUsuario)<< endl ;
			cout << "====================================" << std::endl;
			return 1;
		} else { if (validacion==-1){

			if (contIntentos -1 == 0){
				cout << "Demasiados intentos fallidos. No se puede realizar la accion. "<< endl ;
					contIntentos--;
			}else {
				cout << "El usuario o contrasena ingresado es erroneo o no tiene el rol administrador, por favor intente otra vez."<< endl ;
				contIntentos--;
			cout << "intentos restantes: #" << contIntentos<< endl;
			}
			system("pause");
			system("cls");

		}

		}
	}


	if (contIntentos==0){

		return -1;
		}
		break;

	}
		}
