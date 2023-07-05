#ifndef ARCHIVOVENTA_H
#define ARCHIVOVENTA_H
#include "Venta.h"
#include "Libro.h"


class ArchivoVenta
{
    public:
        ArchivoVenta();
        ArchivoVenta(std::string nombre);

        ///ABML
        int cargarVenta();//uso la de venta
        int grabarVenta(Venta venta);//la uso  en  la funcion cargar de Venta
        void  listarArchivoVenta(); // OK
        void eliminarVentaPorId();
        int contarRegistros();

        ///MANEJO DE ARCHIVOS
        Venta leerRegistro(int pos);
        Venta getVenta(int id);
        void modificarVentaPorId(int id );

        ////LISTADOS
        void listarFacturas();
        void listarFacturaPorID(int id);
        void listarPorId(int id );

        ///INFORMES
        void TotalFacturadoPormes(int mes);
        void totalFacturadoPorAnio(int anio);
        void rankingCincoMasVendidos();
        void bestSellerMensual();



        void listarVentaPorIdYFecha(Fecha f, int id);

    private:
        int modificarVenta( int pos, int idVenta  );
        int eliminarVenta(int pos);//ok
        char _nombre[30];
};

#endif // ARCHIVOVENTA_H
