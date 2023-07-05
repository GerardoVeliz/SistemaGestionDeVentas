
#include <iostream>
#include <locale.h>
using namespace std;
#include "Venta.h"
#include "Fecha.h"
#include "Cliente.h"
#include "Funciones.h"
#include "ArchivoVenta.h"
#include "archivoStockVenta.h"
#include "archivoCliente.h"
#include <cstring>


	Venta::Venta()
	{
		_idProducto=0;
		_idVenta=0 ;
		_importe=0;
		_cantidadVendida=0;
		_estadoVenta=false ;
	}


	void Venta::setearVenta (int id,Fecha fecha, float importe ,int cantVendida, int idProducto, bool estado, Cliente cliente ){
	_idVenta=id;
	_fechaVenta=fecha;
	_importe=importe;
	_cantidadVendida=cantVendida;
	_idProducto=idProducto;
	_estadoVenta=estado ;
	_clienteVenta=cliente;


	}

	void Venta::setIdVenta (int id){
	_idVenta=id ;
	}
	void Venta::setImporte (float importe){
	_importe=importe;
	}
	void Venta::setCantidadVendida (int cantidad){
	_cantidadVendida=cantidad;
	}
	void Venta::setIdProducto (int idProducto){
	_idProducto=idProducto;
	}
	void Venta::setEstado (bool estado){
	_estadoVenta=estado;
	}

	int Venta::getIdVenta(){
	return _idVenta;
	}
	float Venta::getImporte(){
	return _importe;
	}
	int 	Venta::getCantidadVendida(){
	return _cantidadVendida;
	}
	int 	Venta::getIdProducto(){
	return _idProducto;
	}
	bool  Venta::getEstado(){
	return _estadoVenta;
	}


		int Venta::getDia(){
	return _fechaVenta.getDia();
	}
	int Venta::getMes(){
	return _fechaVenta.getMes();
	}
	int Venta::getAnio(){
	return _fechaVenta.getAnio();
	}

	Fecha Venta::getFecha(){
	return _fechaVenta;

	}


	Cliente Venta::getCliente(){
	return _clienteVenta;
	}

	int Venta::generarId(){

	ArchivoVenta ventas ;
	int cantId=ventas.contarRegistros();
	return cantId+1;

	ArchivoVenta ventas1;
	int cantidadId=ventas1.contarRegistros();
	return cantidadId;


	}

	///lo uso en modificar
	void Venta::modificarVenta(int idVenta){
		float ImporteTotal=0;///guardar el total
		bool salir=false;
		int stockDisponible;
		char  opcion;
		archivoCliente clientes;
		ArchivoVenta ventas ;
		archivoStockVenta stock;
		Venta venta;


		Fecha fecha;
		float importe ;
		int cantVendida;
		int idProducto;
		Cliente cliente ;
		int idCliente;


		while (salir == false){
	cout <<"ingrese el id del producto: "  << endl ;
	cin >> idProducto;
	if (validarId(idProducto)==true){
		cout << "Ingrese la cantidad: "<< endl ;
		cin >>cantVendida;
		if (validarCantidad(idProducto,cantVendida,stockDisponible)== 1){
			importe=generarImporte(cantVendida , idProducto);
			ImporteTotal+=importe;
			cout << endl << "Fechas de la venta: "<< endl ;
			fecha.cargarFecha();
			cout << endl << "Datos del Cliente: "<< endl ;
			cout << "Es un cliente registrado? s/n"<< endl ;
			cin >>opcion;
			if (opcion=='s' || opcion== 'S'){

				cout << "ingrese el numero de Cliente (id) : "<< endl ;
				cin >> idCliente ;

				///funcion que busque clientes y que me traiga los datos segun ese id noombre apellido y dni ;
				cliente=clientes.buscarCliente(idCliente);
				if (cliente.getDni() > 0 ){
					_clienteVenta=cliente ;
				} else { if (cliente.getDni()==0){
					cout << "No se encontro el cliente!, continuara su compra en forma anonima " << endl ;
					cliente.setApellido("anonimo");
					cliente.setNombre("anonimo");
					cliente.setId(-1);
				}

				}
				///funcion para setear toda la venta con las propiedades
				this->setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				this->setEstado(true);
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(this->getIdProducto(),this->getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
					salir=true;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
					salir=true;
				}

			} else  { if (opcion='n' || opcion == 'N'){
				cout << endl << "Quiere registrar al cliente? : s/n"<<endl ;
				cin>> opcion;
				if (opcion == 's' || opcion == 'S'){
				cliente.cargarCliente();
				if (clientes.grabarRegistro(cliente)==1){
					cout << "Cliente registrado con exito!"<< endl ;
				} else {
					cout <<"No se pudo registrar el nuevo cliente! " << endl;
				}
				///funcion para setear toda la venta con las propiedades
				this->setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				this->setEstado(true);
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(this->getIdProducto(),this->getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
					salir=true;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
					salir=true;
				}
				}else { /// no quiero registrar entonces guardo el cliente pordefecto

				///va a registrar el cliente con el nombre apellido y dni vacios porque no quise registrar al cliente
				///funcion para setear toda la venta con las propiedades
				this->setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				this->setEstado(true);
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(this->getIdProducto(),this->getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
					salir=true;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
					salir=true;
				}

				}
			}

			}
		} else {
			cout << "No hay stock disponible para realizar la venta!  vuelva a intentarlo."<< endl ;
			cout << "stock disponible de este producto: " << stockDisponible << endl;
			salir=true ;
		}
	} else {
	cout << "El Id de producto ingresado no es valido o no existe , por favor intente otra vez! "<< endl ;
	salir =true;
			}

		}

	}



	bool Venta::validarId(int id){
	archivoStockVenta  libros ;
	Libro aux ;
	int cantLibros=libros.contarRegistros();
	bool Encontro=false ;
	for (int x=0; x<cantLibros; x++){
		aux=libros.leerRegistro(x);
		if (aux.getIdLibro() == id && aux.getEstado()==true && Encontro==false){
			Encontro=true;
			return Encontro;
		}
	}
	return Encontro;
	}

	int  Venta::validarCantidad(int id, int cantidad, int &stockDisponible){
		archivoStockVenta  libros ;
	Libro aux ;
	int cantLibros=libros.contarRegistros();
	bool Encontro=false ;
	for (int x=0; x<cantLibros; x++){
		aux=libros.leerRegistro(x);
		if (aux.getIdLibro() == id && aux.getEstado()==true && Encontro==false){
			Encontro=true;
			if (aux.getStock() >= cantidad){
				stockDisponible=aux.getStock();
				return 1; ///hay stock
			}
		}
	}
	stockDisponible=aux.getStock();
				return -1;

	}


float Venta::generarImporte(int cant, int id){
	float importe ;
	archivoStockVenta libros;
	Libro aux ;
	int cantLibros=libros.contarRegistros();


	for (int x=0; x< cantLibros ; x++){
		 aux=libros.leerRegistro(x);
		 if (aux.getIdLibro() == id && aux.getEstado( )== true ){
			importe=cant*aux.getImporte();
		 }
	}

	return importe;


	}



//    float  generarImporte(int cant, int id){
//    bool existe=false ;
//    Venta venta1;
//    float importeTotal;
//    ArchivoVenta ventas;
//    int cantVentas=ventas.contarRegistros();
//    for (int x=0; x<cantVentas;x++){
//        venta1=ventas.leerRegistro(x);
//        if (venta1.getIdProducto() == id && venta1.getEstado()== true && existe==false ){
//            importeTotal=venta1.getImporte()*cant;
//            existe=true ;
//	return importeTotal;
//        }
//    }
//
//    if (existe==false){
//        cout <<"No se encontro el id del producto " << endl ;
//        return -1 ;
//    }
//
//    }




	void Venta::cargar(){

		//const int TAM =50;
		//float vProductos[TAM]={};

		bool salir=false;
		int stockDisponible;
		char  opcion;
		archivoCliente clientes;
		ArchivoVenta ventas ;
		archivoStockVenta stock;
		Venta venta;

		int idVenta;
		Fecha fecha;
		float importe ;
		int cantVendida;
		int idProducto;
		Cliente cliente ;
		int idCliente;
		int pos =0;


		idVenta=generarId();

		while (salir == false){
	cout <<"ingrese el id del producto: "  << endl ;
	cin >> idProducto;
	if (validarId(idProducto)==true){
		cout << "Ingrese la cantidad: "<< endl ;
		cin >>cantVendida;
		if (validarCantidad(idProducto,cantVendida,stockDisponible)== 1){
			importe=generarImporte(cantVendida , idProducto);
			//vProductos[pos]=importe;
			cout << endl << "Fechas de la venta: "<< endl ;
			fecha.cargarFecha();
			cout << endl << "Datos del Cliente: "<< endl ;
			cout << "Es un cliente registrado? s/n"<< endl ;
			cin >>opcion;
			if (opcion=='s' || opcion== 'S'){

				cout << "ingrese el numero de Cliente (id) : "<< endl ;
				cin >> idCliente ;

				///funcion que busque clientes y que me traiga los datos segun ese id noombre apellido y dni ;
				cliente=clientes.buscarCliente(idCliente);
				if (cliente.getDni() > 0 ){
					_clienteVenta=cliente ;
				} else { if (cliente.getDni()==0){
					cout << "No se encontro el cliente!, continuara su compra en forma anonima " << endl ;
					cliente.setApellido("anonimo");
					cliente.setNombre("anonimo");
					cliente.setId(-1);
				}

				}
				///funcion para setear toda la venta con las propiedades
				venta.setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				///funcion para guardar venta en el archivo
				if (ventas.grabarVenta(venta)==1){
					cout << "Venta guardada con exito!"<< endl ;
				}else {
						cout <<"No se pudo guardar la venta."<< endl ;
				}
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(venta.getIdProducto(),venta.getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
				}

			} else  { if (opcion='n' || opcion == 'N'){
				cout << endl << "Quiere registrar al cliente? : s/n"<<endl ;
				cin>> opcion;
				if (opcion == 's' || opcion == 'S'){
				cliente.cargarCliente();
				if (clientes.grabarRegistro(cliente)==1){
					cout << "Cliente registrado con exito!"<< endl ;
				} else {
					cout <<"No se pudo registrar el nuevo cliente! " << endl;
				}
				///funcion para setear toda la venta con las propiedades
				venta.setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				///funcion para guardar venta en el archivo
				if (ventas.grabarVenta(venta)==1){
					cout << "Venta guardada con exito!"<< endl ;
				}else {
						cout <<"No se pudo guardar la venta."<< endl ;
				}
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(venta.getIdProducto(),venta.getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
				}
				}else { /// no quiero registrar entonces guardo el cliente pordefecto

				///va a registrar el cliente con el nombre apellido y dni vacios porque no quise registrar al cliente
				///funcion para setear toda la venta con las propiedades
				venta.setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				///funcion para guardar venta en el archivo
				if (ventas.grabarVenta(venta)==1){
					cout << "Venta guardada con exito!"<< endl ;
				}else {
						cout <<"No se pudo guardar la venta."<< endl ;
				}
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(venta.getIdProducto(),venta.getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
				}

				}
			}

			}
		} else {
			cout << "No hay stock disponible para realizar la venta!  vuelva a intentarlo."<< endl ;
			cout << "stock disponible de este producto: " << stockDisponible << endl;
			salir=true ;
		}
	} else {
	cout << "El Id de producto ingresado no es valido o no existe , por favor intente otra vez! "<< endl ;
	salir =true;
	}

			if (salir==false){
			cout << endl<< "Desea agregar otro producto? s/n : "<< endl;
			cin >> opcion;
			}else {
					opcion='n';
					salir=true;
			}

			if (opcion == 'n' || opcion =='N'){
				salir=true;
			} else {



			while (opcion == 's' || opcion =='S'){

				pos++;
				cout <<"ingrese el id del producto: "  << endl ;
				cin >> idProducto;
				if (validarId(idProducto) == true){
					cout << "Ingrese la cantidad: "<< endl ;
					cin >>cantVendida;
					if (validarCantidad(idProducto,cantVendida,stockDisponible)==1){
						importe=generarImporte(cantVendida , idProducto);
						//vProductos[pos]=importe;
						///funcion para setear toda la venta con las propiedades
				venta.setearVenta(idVenta,fecha,importe,cantVendida,idProducto,true,cliente);
				///funcion para guardar venta en el archivo
				if (ventas.grabarVenta(venta)==1){
					cout << "Venta guardada con exito!"<< endl ;
				}else {
						cout <<"No se pudo guardar la venta."<< endl ;
				}
				///funcion para que reste la cantidad vendida en el stock
				if (stock.modificarStock(venta.getIdProducto(),venta.getCantidadVendida())==1){
					cout << "Stock modificado!"<< endl ;
				} else {
					cout << "No se pudo modificar el stock! "<< endl ;
				}
					}else {
							cout << "No hay stock disponible para realizar la venta!  vuelva a intentarlo."<< endl ;
							cout << "stock disponible: " << stockDisponible << endl;
							salir=true ;
							opcion='n';
					}
				}else {
				cout << "El Id de producto ingresado no es valido o no existe , por favor intente otra vez! "<< endl ;
				salir =true;
				opcion='n';
				}

			cout << endl<< "Desea agregar otro producto? s/n : "<< endl;
			cin >> opcion;
			if (opcion=='n'|| opcion == 'N'){
				salir=true ;

						}

					}

				}
			}
			system("pause");
			system("cls");
			char opcionVer;
			char opcionTicket;

			///hay que hacer un if porque si se salio  de la venta por algo y no se cargo nada me lo muestra igual
			cout << "Desea ver el ticket de la compra? s/n: "<< endl ;
			cin>>opcionVer;

			if (opcionVer=='s' || opcionVer=='S'){

            mostrarTicket(idVenta,fecha,cliente);
            cout << endl << endl ;
            cout << "Desea imprimir el ticket? s/n"<< endl ;
            cin >> opcionTicket;
            if (opcionTicket == 's' || opcionTicket=='S'){
                imprimirTicket(idVenta,fecha,cliente,generarNombreTicket(idVenta));
            } else {
                cout <<"Gracias por ahorrar papel!"<< endl ;
            }

			}
			else { //if (opcionVer == 'n' || opcionVer == 'N'){
             cout << "Desea imprimir el ticket? s/n"<< endl ;
            cin >> opcionTicket;
            if (opcionTicket == 's' || opcionTicket == 'S'){
                imprimirTicket(idVenta,fecha,cliente,generarNombreTicket(idVenta));
            } else {
                cout <<"Gracias por ahorrar papel!"<< endl ;
            }
                }

			}


	//validar stock de ese id , si no hay que salga un cartel que diga que no hay stock, y se corta la carga, hacer un switch que me tire los distintos errores, -1 no encontro , -2 no hay stock ;



	void Venta::mostrar(){
	cout<<"============================="<<endl;
	cout << "Id de la venta: #"<< _idVenta<< endl;
	cout<<"============================="<<endl;
	cout <<"Fecha de venta: " << _fechaVenta.toString("dd/mm/yyyy")<< endl ;
	cout << "Datos del cliente: "<< endl;
	_clienteVenta.mostrarCliente();
	cout << "-----------------------------------"<< endl ;
	cout << "Id del producto: #"<< _idProducto<< endl;
	cout << "Cantidad vendida : "<<_cantidadVendida<< endl;
	cout << "Importe: $"<<_importe<< endl;
	cout<<"============================="<<endl;

	}

