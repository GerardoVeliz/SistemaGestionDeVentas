#include <iostream>
#include <cstring>
#include "Venta.h"
#include "Libro.h"
#include "ArchivoVenta.h"
#include "archivoStockVenta.h"
#include "Funciones.h"
#include <iomanip>
using namespace std;

        ArchivoVenta::ArchivoVenta(){
        strcpy(_nombre , "venta.dat");
        }

        ArchivoVenta::ArchivoVenta(std::string nombre){
        strcpy(_nombre,nombre.c_str());
        }




void ArchivoVenta::listarArchivoVenta(){
        Venta aux;
        int cantVentas=this->contarRegistros();
        if (cantVentas== -1 ){

                cout <<"No hay registros en el archivo!." << endl ;
                cout << endl ;
        }  else {

        for (int x=0 ; x< cantVentas;x++){
                        aux=this->leerRegistro(x);
                        if (aux.getEstado() == true){
                        aux.mostrar();
                        cout << endl ;

                        }
                }
        }

}


        Venta ArchivoVenta::leerRegistro(int pos){
        Venta reg;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL){
        cout<<"No se pudo acceder al archivo."<<endl;
        reg.setIdVenta(-1);   ///cuando lo tenga en main validar que este valor sea -1
        return reg;
        }
        fseek(p, sizeof(Venta)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
        }

        void ArchivoVenta::listarPorId(int id ){
                int cont=0 ;
                int cantVentas=this->contarRegistros();
                Venta aux ;
        for (int x=0 ; x<cantVentas;x++){
                        aux=this->leerRegistro(x);
                if (aux.getIdVenta() == id && aux.getEstado()== true){
                        aux.mostrar();
                } else {
                        cont ++ ;
                }
        }
        if (cont==cantVentas){
                cout <<"No se encontro el registro." << endl ;
        }

        }


       void ArchivoVenta::modificarVentaPorId(int id ){
                 Venta aux ;
                 archivoStockVenta stock;
                 int pos;
        char r;
        bool encontrado=false ;
        int valor;
        int cantVentas=this->contarRegistros();
     for (int x=0; x<cantVentas;x++){
                aux=this->leerRegistro(x);
        if (aux.getIdVenta() == id && aux.getEstado()== true ){
                        encontrado=true ;
                        pos=x;
                        cout <<endl <<  "Registro: " << endl ;
                aux.mostrar();
                cout << endl ;
                cout <<"Estas seguro de modificar este registro? s/n : " << endl ;
                cin >> r;
                if (r=='s' || r== 'S'){
                                if (stock.devolverStock(aux)==1){
                                        cout << "Stock devuelto correctamente!"<< endl;
                                }else {
                                        cout << "No se pudo devolver el stock"<<endl ;
                                }
                                valor=this->modificarVenta(pos,aux.getIdVenta());
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
        cout << endl << "No se encontro ese id de venta, no se pudo eliminar." << endl ;
     }


        }

    int ArchivoVenta::modificarVenta(int pos, int idVenta){
            FILE *p;
     p=fopen(_nombre, "rb+" );
     if (p==NULL){
         cout <<"No se pudo acceder al archivo."<< endl ;
         return -1 ;
     }
     Venta aux;
     fseek(p,sizeof(Venta)*pos,0);
     aux.modificarVenta(idVenta);
     int valor ;
     valor=fwrite(&aux,sizeof(Venta),1,p);
     fclose(p);
     return valor ;
     }

     void ArchivoVenta::eliminarVentaPorId(){
             archivoStockVenta stock ;

        Venta aux ;
        char r;
        bool encontrado=false ;
        int valor;
        int cantVentas=this->contarRegistros();
        int id ;
        cout << "Ingrese el Id de la venta a eliminar: "<< endl ;
        cin>> id ;
     for (int x=0; x<cantVentas;x++){
                aux=this->leerRegistro(x);
        if (aux.getIdVenta() == id && aux.getEstado()== true ){
                        encontrado=true ;
                        cout <<endl <<  "Registro: " << endl ;
                aux.mostrar();
                cout << endl ;
                cout <<"Estas seguro de eliminar este registro? s/n : " << endl ;
                cin >> r;
                if (r=='s' || r== 'S'){
                                stock.devolverStock(aux);
                                valor=this->eliminarVenta(x);
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
        cout << endl << "No se encontro ese id de venta, no se pudo eliminar." << endl ;
     }
             }



   int ArchivoVenta::eliminarVenta( int pos){
            bool estado=false ;
    FILE *p;
   p=fopen(_nombre, "rb+" );
   if (p==NULL){
       cout <<"No se pudo acceder al archivo."<< endl ;
       return -1 ;
   }
   int valor ;
   Venta obj ;
   fseek(p,sizeof(Venta)*pos,0);
   fread(&obj,sizeof(Venta),1,p);
           obj.setEstado(estado);
              fseek(p,sizeof(Venta)*pos,0);
           valor=fwrite (&obj,sizeof(Venta),1,p);
        fclose(p);
        return valor; ///validar en menu

   }


        void ArchivoVenta::listarVentaPorIdYFecha(Fecha f , int id ){
        int cont=0 ;
        cout <<endl <<  "Ventas del id #"<< id << " En la fecha : " << f.toString("dd/mm/yyy")<< endl ;
        cout << endl ;

        for (int x=0 ; x<this->contarRegistros();x++){
                if (this->leerRegistro(x).getIdProducto() == id && this->leerRegistro(x).getDia()== f.getDia() && this->leerRegistro(x).getMes () == f.getMes() && this->leerRegistro(x).getAnio()== f.getAnio() && this->leerRegistro(x).getEstado()== true ){
                        this->leerRegistro(x).mostrar();
                        cout << endl ;
                } else {
                cont ++ ;
                }
        }
        if (cont==this->contarRegistros()){
                cout <<endl << "No se encontraron ventas con este id y en esta fecha." << endl ;
        }

        }


         int ArchivoVenta::contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Venta);
    }

    int ArchivoVenta::cargarVenta(){
            Venta reg ;
            FILE *p ;
            p=fopen(_nombre,"ab");
            if (p==NULL){

                cout <<"no se pudo acceder al archivo " << endl ;
                return -1;
            }
            reg.cargar  ();
            if (reg.getImporte()==0){

                return -2;///alguno de los datos ingresados estan mal o el stock no da bien o el id de estan mal
            }else{
            int valor = fwrite(&reg,sizeof (Venta),1,p);
            fclose(p);
            return valor ; /// validar en el menu

            }
    }

    int ArchivoVenta::grabarVenta(Venta venta){
    FILE *p ;
    p=fopen(_nombre ,"ab");
    if (p==NULL){
         cout <<"no se pudo acceder al archivo " << endl ;
                return -1;///validar
    }
    int valor = fwrite(&venta,sizeof(Venta),1,p);
    fclose(p);
    return valor ;




    }

        void ArchivoVenta::listarFacturas(){
        int cantVentas=this->contarRegistros();
        Venta aux ;
        int idAnt;
        for (int x=0; x<cantVentas;x++){
                aux=this->leerRegistro(x);
                if (aux.getEstado() == true  && aux.getImporte() >0  && aux.getIdVenta()!=idAnt ){
                idAnt=aux.getIdVenta();
                mostrarTicket(aux.getIdVenta(),aux.getFecha(),aux.getCliente());
                cout << endl;

                }
        }


        }
        void ArchivoVenta::listarFacturaPorID(int id){
         int cantVentas=this->contarRegistros();
        bool encontro=false ;
        Venta aux ;

        for (int x=0; x<cantVentas;x++){
                aux=this->leerRegistro(x);
                if (aux.getIdVenta()==id && aux.getEstado() == true && encontro==false   ){
                encontro=true;

                mostrarTicket(aux.getIdVenta(),aux.getFecha(),aux.getCliente());
                cout << endl;

                }
        }
        if (encontro==false){
                cout << "No se encontro venta con ese ID."<< endl ;
        }

        }

        	Venta ArchivoVenta::getVenta(int id ){
        	int cantVentas=this->contarRegistros();
        	Venta aux;
        	for (int x=0; x<cantVentas;x++){
                        aux=this->leerRegistro(x);
                        if (aux.getIdVenta() == id && aux.getEstado()==true){
                                return aux ;
                        }
        	}
        	aux.setIdVenta(-1);
        	return aux;
        	}


        void ArchivoVenta::TotalFacturadoPormes(int mes){
        int cantVentas= this->contarRegistros();
        float TotalFacturado=0;
        Venta aux;
        for (int x=0; x<cantVentas;x++){
                aux=this->leerRegistro(x);
                if (aux.getFecha().getMes() == mes && aux.getEstado()==true){
                        TotalFacturado+=aux.getImporte();
                }
        }

        cout << "El total facturado en el mes numero #"<<mes << " fue: $"<< TotalFacturado<< endl ;
        }


        void ArchivoVenta::totalFacturadoPorAnio(int anio){
           int cantVentas=this->contarRegistros();
        float TotalFacturado=0;
        Venta aux;
        for (int x=0; x<cantVentas;x++){
                aux=this->leerRegistro(x);
                if (aux.getFecha().getAnio() == anio && aux.getEstado()==true){
                        TotalFacturado+=aux.getImporte();
                }
        }
cout << "El total facturado en el anio numero #"<<anio << " fue: $"<< TotalFacturado<< endl ;
        }


void ArchivoVenta::rankingCincoMasVendidos() {
    int auxID = 0;
    int auxCont = 0;
    archivoStockVenta stock;
    int cantVentas = this->contarRegistros();
    int cantiLibros = stock.contarRegistros();
    int *vLibros;
    Venta aux;
    Libro obj;

    vLibros = new int[cantiLibros];
    if (vLibros == NULL) {
        cout << "Error al asignar memoria dinámica." << endl;
    }
    int *vCont;
    vCont = new int[cantiLibros];
    if (vCont == NULL) {
        cout << "Error al asignar memoria dinámica." << endl;
    }
    // Vector con el número de ID de los libros
    for (int x = 0; x < cantiLibros; x++) {
        obj = stock.leerRegistro(x);
        vLibros[x] = obj.getIdLibro();
    }
    // Vector con la cantidad vendida en 0
    for (int x = 0; x < cantiLibros; x++) {
        vCont[x] = 0;
    }

    for (int x = 0; x < cantVentas; x++) {
        aux = this->leerRegistro(x);
        for (int i = 0; i < cantiLibros; i++) {
            if (aux.getEstado() == true && aux.getIdProducto() == vLibros[i]) {
                vCont[i] += aux.getCantidadVendida();
            }
        }
    }
///muestro las ventas por si quieren saber si esta bien el ranking
  /*  for (int x=0; x<cantiLibros;x++){
        cout << "libro: " << vLibros[x]<< " cant: "<< vCont[x]<< endl ;
    }*/
///ajustar la condición de finalización del bucle para que no llegue hasta cantiLibros - 1 para que no se vaya fuera del tamaño
    for (int i = 0; i < cantiLibros - 1; i++) {
        for (int j = 0; j < cantiLibros - 1 - i; j++) {
            if (vCont[j] < vCont[j + 1]) {
                std::swap(vCont[j], vCont[j + 1]);
                std::swap(vLibros[j], vLibros[j + 1]);
            }
        }
    }
cout << endl <<endl ;
        cout <<"=================================================================="<< endl ;
        cout <<"Ranking 5 Mas Vendidos! :" << endl ;
        cout <<"=================================================================="<< endl ;
        cout <<setw(6)<<setiosflags(ios::left)<< "ID";
        cout << setw(40)<< setiosflags(ios::left)<< "   Nombre del Libro";
        cout << setw(15)<< setiosflags(ios::left)<< "Cantidad Vendida";
        cout <<endl<< "___________________________________________________________________"<<endl ;


    // Mostrar los cinco libros más vendidos
    for (int x = 0; x < 5; x++) {
        cout <<setw(6)<<setiosflags(ios::left)<< vLibros[x];
        cout << setw(40)<< setiosflags(ios::left)<< stock.getLibro( vLibros[x]).getDescipcion();
        cout << setw(15)<< setiosflags(ios::left)<< vCont[x];
        cout << endl ;
    }
          cout <<endl<< "___________________________________________________________________"<<endl ;
        cout <<"=================================================================="<< endl ;
    delete[] vLibros;
    delete[] vCont;
}

void ArchivoVenta::bestSellerMensual(){

    archivoStockVenta stock;
    int cantVentas = this->contarRegistros();
    int cantiLibros = stock.contarRegistros();
    int *vLibros;
    Venta aux;
    Libro obj;

    vLibros = new int[cantiLibros];
    if (vLibros == NULL) {
        cout << "Error al asignar memoria dinámica." << endl;
    }
    int *vCont;
    vCont = new int[cantiLibros];
    if (vCont == NULL) {
        cout << "Error al asignar memoria dinámica." << endl;
    }
    // Vector con el número de ID de los libros
    for (int x = 0; x < cantiLibros; x++) {
        obj = stock.leerRegistro(x);
        vLibros[x] = obj.getIdLibro();
    }
    // Vector en 0
    for (int x = 0; x < cantiLibros; x++) {
        vCont[x] = 0;
    }

    for (int x = 0; x < cantVentas; x++) {
        aux = this->leerRegistro(x);
        for (int i = 0; i < cantiLibros; i++) {
            if (aux.getEstado() == true && aux.getIdProducto() == vLibros[i]) {
                vCont[i] += aux.getCantidadVendida();
            }
        }
    }
///muestro las ventas por si quieren saber si esta bien el ranking
  /*  for (int x=0; x<cantiLibros;x++){
        cout << "libro: " << vLibros[x]<< " cant: "<< vCont[x]<< endl ;
    }*/
///ajustar la condición de finalización del bucle para que no llegue hasta cantiLibros - 1 para que no se vaya fuera del tamaño
    for (int i = 0; i < cantiLibros - 1; i++) {
        for (int j = 0; j < cantiLibros - 1 - i; j++) {
            if (vCont[j] < vCont[j + 1]) {
                std::swap(vCont[j], vCont[j + 1]);
                std::swap(vLibros[j], vLibros[j + 1]);
            }
        }
    }
    cout << endl <<endl ;
        cout <<"=================================================================="<< endl ;
        cout <<"BestSeller! :" << endl ;
        cout <<"=================================================================="<< endl ;
        cout <<setw(6)<<setiosflags(ios::left)<< "ID";
        cout << setw(40)<< setiosflags(ios::left)<< "   Nombre del Libro";
        cout << setw(15)<< setiosflags(ios::left)<< "Cantidad Vendida";
        cout <<endl<< "___________________________________________________________________"<<endl ;

        cout <<setw(6)<<setiosflags(ios::left)<< vLibros[0];
        cout << setw(40)<< setiosflags(ios::left)<< stock.getLibro( vLibros[0]).getDescipcion();
        cout << setw(15)<< setiosflags(ios::left)<< vCont[0];
        cout << endl ;

          cout <<endl<< "___________________________________________________________________"<<endl ;
        cout <<"=================================================================="<< endl ;
    delete[] vLibros;
    delete[] vCont;


}






