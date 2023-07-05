
#include <iostream>
#include <locale.h>
#include "Libro.h"
#include "Funciones.h"
#include <cstring>
#include "ArchivoVenta.h"
#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include <fstream>
#include <iomanip>
#include "archivoStockVenta.h"
#include <filesystem>
#include <string>
#include "archivoUsuario.h"
#include <conio.h>

using namespace std;


void mostrarTicket(int idVenta, Fecha fechaVenta,Cliente cliente  ){
ArchivoVenta ventas ;
archivoStockVenta stock ;
Venta aux ;
float importeTotal=0;
int cantVentas=ventas.contarRegistros();
cout <<endl<<"===================================================================="<< endl;
cout << "Ticket de la venta: #" << idVenta<< endl ;
cout <<endl<<"--------------------------------------------------------------------"<< endl;
cout <<"Fecha de la venta:" << fechaVenta.toString("dd/mm/yyyy")<< endl ;
cout << "Nombre Cliente: " << cliente.getNombre() <<endl ;
cout << "Apellido Cliente: " << cliente.getApellido()<<endl ;
cout <<endl<<"--------------------------------------------------------------------"<< endl;
cout << setw(35)<< setiosflags(ios::left)<< "PRODUCTO" ;
cout << setw(10)<< setiosflags(ios::left)<< "CANTIDAD" ;
cout << setw(15)<< setiosflags(ios::left)<< "IMPORTE" ;
cout <<endl<<"--------------------------------------------------------------------"<< endl;
cout << endl;
///este es por que hay ventas con el mismo nro de id
for (int x=0; x<cantVentas; x++){
	aux=ventas.leerRegistro(x);
	if (aux.getIdVenta() == idVenta&& aux.getEstado()==true ){

	cout << setw(35)<< setiosflags(ios::left)<<stock.getNombreProducto(aux.getIdProducto());
	cout << setw(5)<< setiosflags(ios::right)<< aux.getCantidadVendida();
	cout << setw(10)<< setiosflags(ios::left)<<aux.getImporte() ;
	importeTotal+=aux.getImporte();
	cout << endl ;
	}
}
cout <<endl<<"--------------------------------------------------------------------"<< endl;
cout << setw(35)<< setiosflags(ios::left)<<"TOTAL: ";
cout << setw(5)<< setiosflags(ios::right)<< "  $ ";
cout << setw(10)<<setiosflags(ios::left)<<importeTotal;
cout <<endl<<"===================================================================="<< endl;


}

void imprimirTicket(int idVenta, Fecha fechaVenta,Cliente cliente , string nombreArchivo ){
	float importeTotal=0;
    ArchivoVenta ventas ;
archivoStockVenta stock ;
Venta aux ;

int cantVentas=ventas.contarRegistros();
    std::ofstream archivo(nombreArchivo);


    if (archivo.is_open()) {
        // Escribir los datos de la venta en el archivo
archivo<<endl<<"-------------------------------------------------------"<< endl;
archivo<< "Ticket de la venta: #" << idVenta<< endl ;
archivo<<endl<<"-------------------------------------------------------"<< endl;
archivo<<"Fecha de la venta:" << fechaVenta.toString("dd/mm/yyyy")<< endl ;
archivo<< "Nombre Cliente: " << cliente.getNombre() <<endl ;
archivo<< "Apellido Cliente: " << cliente.getApellido()<<endl ;
archivo<<endl<<"-------------------------------------------------------"<< endl;
archivo<< setw(35)<< setiosflags(ios::left)<< "PRODUCTO" ;
archivo<< setw(10)<< setiosflags(ios::left)<< "CANTIDAD" ;
archivo<< setw(15)<< setiosflags(ios::left)<< "IMPORTE" ;
archivo<<endl<<"-------------------------------------------------------"<< endl;
archivo << endl;
for (int x=0; x<cantVentas; x++){
	aux=ventas.leerRegistro(x);
	if (aux.getIdVenta() == idVenta && aux.getEstado()==true ){
	archivo << setw(35)<< setiosflags(ios::left)<<stock.getNombreProducto(aux.getIdProducto());
	archivo << setw(5)<< setiosflags(ios::right)<< aux.getCantidadVendida();
	archivo << setw(10)<< setiosflags(ios::left)<< aux.getImporte() ;
	importeTotal+=aux.getImporte();
	archivo << endl ;
	}
}
archivo<<endl<<"-------------------------------------------------------"<< endl;
archivo<< setw(35)<< setiosflags(ios::left)<<"TOTAL: ";
archivo<< setw(5)<< setiosflags(ios::right)<< " $ ";
archivo<< setw(10)<<setiosflags(ios::left)<<importeTotal;
archivo<<endl<<"-------------------------------------------------------"<< endl;
archivo<< endl << "GRACIAS POR SU COMPRA!"<< endl;
archivo<<endl<<"-------------------------------------------------------"<< endl;

        archivo.close();
        cout << "El ticket se ha generado exitosamente." << endl;
    } else {
        cout << "No se pudo crear el archivo del ticket." << endl;
    }
}

string generarNombreTicket(int idVenta) {
string extension = ".txt"; // Extensión del archivo
string nombreArchivo = "ticketVta" + std::to_string(idVenta) + extension;
    return nombreArchivo;
}

/*int  loginFuncionesAdministrador(){

	Usuario aux ;
	int contIntentos = 3;
	archivoUsuario usuarios;
	string nombreUsuario;
	string pass;
	cout << "====================================" << std::endl;
	cout << "BIENVENIDO AL  LOGIN:!" << std::endl;
	cout << "====================================" << std::endl;
	cin.ignore();
	cout << "Nombre de usuario: ";
	getline(cin,nombreUsuario);

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
*/
int loginFuncionesAdministrador() {
    Usuario aux;
    int contIntentos = 3;
    archivoUsuario usuarios;
    string nombreUsuario;
    string pass;
    cout << "====================================" << std::endl;
    cout << "BIENVENIDO AL  LOGIN:!" << std::endl;
    cout << "====================================" << std::endl;
    cin.ignore();

    while (contIntentos != 0) {
        cout << "Nombre de usuario: ";
        getline(cin, nombreUsuario);

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
        int validacion = usuarios.validarUsuarioAdministrador(aux);

        if (validacion == 1) {
            system("cls");
            cout << "====================================" << std::endl;
            cout << "Hola! " << usuarios.getNombre(nombreUsuario) << endl;
            cout << "====================================" << std::endl;
            return 1;
        } else if (validacion == -1) {
            contIntentos--;

            if (contIntentos == 0) {
                cout << "Demasiados intentos fallidos. No se puede realizar la accion." << endl;
            } else {
                cout << "El usuario o contrasena ingresado es erroneo o no tiene el rol administrador, por favor intente otra vez." << endl;
                cout << "Intentos restantes: #" << contIntentos << endl;
            }

            system("pause");
            system("cls");
        }
    }

    return -1;
}





	void cargarCadena(char *pal, int tam){
	int i;
	fflush(stdin);
	for(i=0; i<tam; i++)
	{
	pal[i]=cin.get();
	if(pal[i]=='\n') break;
	}
	pal[i]='\0';
	fflush(stdin);
	}
