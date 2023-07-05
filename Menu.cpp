
#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdio>
#include "Cliente.h"
#include "Fecha.h"
#include"Usuario.h"
#include "Venta.h"
#include "Libro.h"
#include "Funciones.h"
#include "ArchivoVenta.h"
#include "archivoUsuario.h"
#include <conio.h>
#include "archivoStockVenta.h"
#include "archivoAutor.h"
using namespace std;


#include "Menu.h"

Menu::Menu()
{
	//ctor
}
void Menu::mensajeBienvenida(){
	cout << endl << endl << endl ;
	cout << "========================================================="<< endl;
	cout << "BBBBB    OOOO   H    H  EEEEE  M     M  IIIII  AAAAA" << endl;
    cout << "B    B  O    O  H    H  E      MM   MM    I   A    A" << endl;
    cout << "BBBBB   O    O  HHHHHH  EEEE   M M M M    I   AAAAAA" << endl;
    cout << "B    B  O    O  H    H  E      M  M  M    I   A    A" << endl;
    cout << "BBBBB    OOOO   H    H  EEEEE  M     M  IIIII A    A" << endl;
    cout << endl;
    cout << "========================================================="<< endl;
    cout << "\t"<<"	Bienvenido a Bohemia" << endl;
    cout << endl << endl << endl ;
    system("pause");
    system("cls");


}

void Menu::mensajeDespedida(){
 std::cout << "                                 ___,------,\n"
                 "             _,--.---.         __,--'         /\n"
                 "           ,' _,'_`._ \\    _,-'           ___,|\n"
                 "          ;--'       `^-.,'        __,---'   ||\n"
                 "        ,'               \\     ,'        _,-'   \n"
                 "       /                  \\ ,'      _,-'       \n"
                 "      :                    .      ,'            : \n"
                 "      |                    :     `.            |:\n"
                 "      |           _,-      |       `-,'          ::\n"
                 "     ,'____ ,  ,-'  `.   , |,         `.        : \\\n"
                 "     ,'    `-,'       ) / \\/ \\          \\        : :\n"
                 "     |      _\\   o _,-'    '-.           `.      \\ \\\n"
                 "      `o_,-'  `-,-' ____   ,` )-.______,'  `.     : :\n"
                 "       \\-\\    _,---'    `-. -'.\\  `.  /     `.    \\ \\\n"
                 "        / `--'             `.   \\   \\:        \\    \\,.\\\n"
                 "       (              ____,  \\  |    \\\\        \\   : \\\\\n"
                 "        )         _,-'    `   | |    | \\        \\   \\_\\\\\n"
                 "       /      _,-'            | |   ,'-`._      _\\   \\,'\n"
                 "       `-----' |`-.           ;/   (__ ,' `-. _;-'`\\           _,--'\n"
                 "     ,'        |   `._     _,' \\-._/  Y    ,-'      \\      _,-'\n"
                 "    /        _ |      `---'    :,-|   |    `     _,-'\\_,--'   \\\n"
                 "   :          `|       \\`-._   /  |   '     `.,-' `._`         \\\n"
                 "   |           _\\_    _,\\/ _,-'|                     `-._       \\\n"
                 "   :   ,-         `.-'_,--'    \\                         `       \\\n"
                 "   | ,'           ,--'      _,--\\           _,                    :\n"
                 "    )         .    \\___,---'   ) `-.____,--'                      |\n"
                 "   _\\    .     `    ||        :            \\                      ;\n"
                 " ,'  \\    `.    )--' ;        |             `-.                  /\n"
                 "|     \\     ;--^._,-'         |                `-._            _/_\\\n"
                 "\\    ,'`---'                  |                    `--._____,-'_'  \\\n"
                 " \\_,'                         `._                          _,-'     `\n"
                 "          -hrr-             ,-'  `---.___           __,---'\n"
                 "                          ,'             `---------'\n"
                 "                        ,'\n";

		cout <<"\t"<<"Apruebenme xd! " <<endl ;

 }

void Menu::login(){
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
    while ((ch = _getch()) != '\r') { // Leer caracteres hasta presionar Enter
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
validacion=usuarios.validarUsuario(aux);
switch(validacion){
case 1:
system("cls");
cout << "==============================================="<< endl;
cout << "Hola! "<< usuarios.getNombre(nombreUsuario)<< endl ;
cout << "==============================================="<< endl;
menuPrincipal();
break;
case -1:

	cout << "El usuario o contrasena ingresado es erroneo, por favor intente otra vez!!."<< endl ;
	contIntentos--;
	cout << "intentos restantes: #" << contIntentos<< endl;
	system("pause");
	system("cls");

	while(contIntentos!=0){
cout << "===================================="<< endl;
cout << "LOGIN: "<< endl ;
cout << "===================================="<< endl;
cout<< "Nombre de usuario: ";
cin >> nombreUsuario ;
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
cout << "===================================="<< endl;
		aux.setContrasena(pass);
		aux.setUsuario(nombreUsuario);
		validacion=usuarios.validarUsuario(aux);

		if (validacion==1){
			system("cls");
			cout << "==============================================="<< endl;
			cout << "Hola! "<< usuarios.getNombre(nombreUsuario)<< endl ;
			cout << "==============================================="<< endl;
			menuPrincipal();
			exit(0);

		} else { if (validacion==-1){

			if (contIntentos -1 == 0){
				cout << "Demasiados intentos fallidos. La aplicacion se cerrara! "<< endl ;
					contIntentos--;
			}else {
				cout << "El usuario o contrasena ingresado es erroneo o, por favor intente otra vez."<< endl ;
				contIntentos--;
			cout << "intentos restantes: #" << contIntentos<< endl;
			}
			system("pause");
			system("cls");

		}

		}
	}
	if (contIntentos==3){

		exit(0);
	}
	break;

}


}


void  Menu::menuPrincipal(){
int opcion;
do{
cout << "==============================================="<< endl;
cout <<"	"<<"-Menu Principal-" <<"			"<< endl ;
cout << "==============================================="<< endl;
cout << "1- Modulo de Venta."<<endl ;
cout << "2- Modulo de Stock."<<endl ;
cout << "3- Modulo de Usuarios."<<endl ;
cout << "4.Creditos: "<< endl;
cout << "0- Salir."<<endl ;
cout << "==============================================="<< endl;
cout << "Ingrese su opcion: "<<endl ;
cin>> opcion;
cout << "==============================================="<< endl;
system("cls");
switch(opcion){
case 1 :
    menuVenta();
    break;
case 2:
    menuStock();
    break;
case 3:
    menuUsuarios();
    break;
case 4 :
	cout << endl << endl ;
	cout << "Desarrollador: "<<endl ;
	cout << "NOMBRE: Gerardo Veliz"<<endl;
	cout << "FACULTAD: UTN FRGP "<< endl ;
	cout<< "LEGAJO: 17111"<< endl;
case 0 :
	cout << endl<< endl << endl ;
	cout <<"Gracias por usar nuestra app, Hasta Pronto! " << endl ;
	cout << endl << endl <<endl;
	system("pause");
default:

        cout <<"Opcion invalida,elige otra." << endl ;

    break;
}

    system("cls");

}while(opcion!=0);

}


void Menu::menuVenta(){

	int mes,anio;
	char r;
	ArchivoVenta ventas;
	Venta aux;
	int id;
	Fecha fecha;
int opcion;
do{
cout << "==============================================="<< endl;
cout <<"	"<<"-Menu Venta-" <<"			"<< endl ;
cout << "==============================================="<< endl;
cout << "1- Cargar Venta."<<endl ;
cout << "2- Listar todas las Ventas ."<<endl ;
cout << "3- Listar por ID de venta ."<<endl ;
cout << "4- Modificar venta."<<endl ;
cout << "5- Eliminar venta."<<endl ;
cout << "6- Listar todas las facturas de ventas."<<endl ;
cout << "7- Listar facturas de ventas por id de venta."<<endl ;
cout << "8- Total facturado por mes. "<<endl ;
cout << "9-Total facturado por anio. "<<endl ;
cout << "10- Ranking 5 Libros mas vendidos. " << endl ;
cout << "11- BestSeller. " << endl ;
cout << "0- Salir."<<endl ;
cout << "==============================================="<< endl;
cout << "Ingrese su opcion: "<<endl ;
cin>> opcion;
cout << "==============================================="<< endl;
 system("cls");
switch(opcion){
case 1 :
	aux.cargar();
	system("pause");
    break;
case 2:
	ventas.listarArchivoVenta();
	system("pause");
    break;

case 3:

	cout << "Ingrese id de Venta: " << endl ;
	cin >> id ;
	ventas.listarPorId(id);
	system("pause");
    break ;
case 4:
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
	cin >>r ;
	if (r=='s' || r=='S'){
	if (loginFuncionesAdministrador()==1){
	cout << "Ingrese id de Venta: " << endl ;
	cin >> id ;
	ventas.modificarVentaPorId(id);
	system("pause");
			}
	}
    break;
case 5:
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
	cin >>r ;
	if (r=='s' || r=='S'){
	if (loginFuncionesAdministrador()==1){
	ventas.eliminarVentaPorId();
	}
	system("pause");
	}
    break;
case 6 :
	ventas.listarFacturas();
	system("pause");
	break;
case 7:
	cout << "Ingrese id de Venta: " << endl ;
	cin >> id ;
	ventas.listarFacturaPorID(id);
	cout << endl << endl ;
	cout <<"Quiere imprimir la factura? s/n : ";
	cin >> r;
	if (r=='s' || r=='S'){
		aux=ventas.getVenta(id);
		imprimirTicket(aux.getIdVenta(),aux.getFecha(),aux.getCliente(),generarNombreTicket(aux.getIdVenta()));
	}else {
		cout << "Gracias por ahorra papel!"<< endl ;

	}
	system("pause");
	break;
	case 8:
		cout <<"Ingrese numero del mes : " ;
		cin >> mes;
		ventas.TotalFacturadoPormes(mes);
		system("pause");
		break;
	case 9 :
		cout <<"Ingrese el anio: " ;
		cin >> anio;
		ventas.totalFacturadoPorAnio(anio);
		system("pause");
		break;
	case 10 :
		ventas.rankingCincoMasVendidos();
		system("pause");
		break;
	case 11 :
		ventas.bestSellerMensual();
		system("pause");
		break;
default:
    if (opcion!=0){
        cout <<"Opcion invalida,elige otra." << endl ;
    }
    break;
}
//    system("pause");
    system("cls");

}while(opcion!=0);





}


void Menu::menuStock(){
int opcion;
int id,cant ;
int login;
char r ;
archivoStockVenta stock ;
archivoAutor autores ;
do{
cout << "==============================================="<< endl;
cout <<"	"<<"-Menu Stock-" <<"			"<< endl ;
cout << "==============================================="<< endl;
cout << "1- Cargar nuevo Libro "<<endl ;
cout << "2- Cargar stock por id."<<endl ;
cout << "3- Listar todos los libro en  stock ."<<endl ;
cout << "4- Listar stock por ID de libro."<<endl ;
cout << "5- Modificar Libro por ID. "<< endl ;
cout << "6- Eliminar un Libro por id "<<endl ;
cout << "7- Recaudacion mensual y total por id de Libro."<< endl ;
cout << "8- Recaudacion mensual y total por id de Autor."<< endl ;
cout << "9- Recaudacion mensual y total por id de Genero."<< endl ;
cout << "0- Salir."<<endl ;
cout << "==============================================="<< endl;
cout << "Ingrese su opcion: "<<endl ;
cin>> opcion;
cout << "==============================================="<< endl;
 system("cls");
switch(opcion){
case 1 :
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
	cin >>r ;
	if (r=='s' || r=='S'){
		if(loginFuncionesAdministrador()==1){
	if (stock.cargarLibro() == 1 ){
		cout <<endl<<"Libro nuevo cargado con exito!"<< endl;
	}else {
		cout <<endl << "No se pudo cargar el nuevo libro! "<< endl ;
	}

		}
system("pause");
	}
    break;
case 2:
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
cin >>r ;
if (r=='s' || r=='S'){
	if (loginFuncionesAdministrador()==1){
	cout << "Ingrese el Id de libro: "<< endl ;
	cin >> id ;
	cout << "Ingrese la cantidad de stock ingresada: "<<endl ;
	cin >> cant ;
	if (stock.cargarStock(id,cant)==1){
		cout << endl <<"Stock cargado con exito ! " << endl ;

	}else {
		cout << endl << "No se pudo cargar el nuevo stock"<< endl ;
	}

	}
	system("pause");
}
	break;
	case 3:
	stock.listarLibrosStock();
	system("pause");
	break;
	case 4:
	cout << "Ingrese el ID de libro: "<< endl ;
	cin >>id ;
	stock.stockPorId(id);
	system("pause");
	break;
	case 5 :
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
	cin >>r ;
	if (r=='s' || r=='S'){
	if (loginFuncionesAdministrador()==1){
	stock.modificarLibroPorId();

	}
	system("pause");
	}
	break;
	case 6:
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
	cin >>r ;
	if (r=='s' || r=='S'){
	if (loginFuncionesAdministrador()==1){
	stock.eliminarLibroPorId();

	}
	system("pause");
}
	break;
	case 7:
	cout << "ingrese el ID de libro: "<< endl ;
	cin>>id;
	stock.recaudacionPorLibro(id);
	system("pause");
    break;
case 8:
	cout << "ingrese el ID de Autor: "<< endl ;
	cin>>id;
	stock.recaudacionPorAutor(id);
	system("pause");
    break;
case 9:
	cout << "ingrese el ID de Genero: "<< endl ;
	cin>>id;
	stock.recaudacionPorGenero(id);
	system("pause");
    break;
case 10 :

	autores.leerArchivo();
	system("pause");
default:
    if (opcion!=0){
        cout <<"Opcion invalida,elige otra." << endl ;
    }
    break;
}

    system("cls");

}while(opcion!=0);

}

/*Crear nuevo usuario  gm:
Nos va a pedir una contraseña para poder crearlo , con 3 intentos , si entra
Nos va a pedir nombre y dni , usuario y pass , los guarda en usuariosgm.dat

Crear nuevo usuario  :
Te pide nombre y dni , un nombre de usuario , y una contraseña , este reg se guarda en el archivo de UsuarioOp.dat
Modificar usuario:
Pide nombre y pass , y te deja modificar , las mismas
Eliminar usuario (solo lo puede hacer un gm) :
*/

void Menu::menuUsuarios(){
int opcion;
int id ;
char r;
archivoUsuario usuarios;
do{
cout << "==============================================="<< endl;
cout <<"	"<<"-Menu Usuario-" <<"			"<< endl ;
cout << "==============================================="<< endl;
cout << "1- Crear un usuario administrador."<<endl ;
cout << "2- Crear usuario vendedor."<<endl ;
cout << "3- Modificar usuario vendedor(cambio de nombre de usuario y contraseña)."<<endl ;
cout << "4- Eliminar usuario vendedor."<<endl ;
cout << "5- Listar Todos los usuarios ."<<endl ;

cout << "0- Salir."<<endl ;
cout << "==============================================="<< endl;
cout << "Ingrese su opcion: "<<endl ;
cin>> opcion;
cout << "==============================================="<< endl;
switch(opcion){
case 1 :
cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
cin >>r ;
if (r=='s' || r=='S'){
		system("cls");
if(loginFuncionesAdministrador()==1){
	if (usuarios.cargarUsuarioAdministrador()==1) {
		cout << "Usuario creado con exito!"<< endl ;
	}else {
		cout << "No se pudo crear el usuario!"<< endl ;
	}
}

}
system("pause");
    break;
case 2:
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
cin >>r ;
if (r=='s' || r=='S'){
			system("cls");
	if(loginFuncionesAdministrador()==1){
	if (usuarios.cargarUsuario()==1) {
		cout << "Usuario creado con exito!"<< endl ;
	}else {
		cout << "No se pudo crear el usuario!"<< endl ;
	}
	}
	}
	system("pause");
    break;
case 3:
	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
cin >>r ;
if (r=='s' || r=='S'){
		system("cls");
	if(loginFuncionesAdministrador()==1){
	cout <<"Ingrese el id del usuario a modificar: "<< endl ;
	cin >>id;
	usuarios.modificarUsuarioPorID(id);

	}}
	system("pause");
    break;
case 4:

	cout << "Debe Presentar credenciales de administrador para realizar esta acccion, Desea continuar ? s/n "<< endl ;
	cin >>r ;
	if (r=='s' || r=='S'){
		system("cls");
	if(loginFuncionesAdministrador()==1){
	cout <<"Ingrese el id del usuario a eliminar: "<< endl ;
	cin >>id;
	usuarios.eliminarUsuarioPorId(id);
	}}
	system("pause");
    break ;
case 5 :
	usuarios.listarArchivoUsuario();
	system("pause");
	break ;
default:
    if (opcion!=0){
        cout <<"Opcion invalida,elige otra." << endl ;
    }
    break;
}

    system("cls");

}while(opcion!=0);





}
