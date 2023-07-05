#ifndef FECHA_H
#define FECHA_H
#include <string>


class Fecha
{
    public:
        Fecha();
        Fecha(int d, int m , int a);
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
        int getDia();
        int getMes();
        int getAnio();
        void cargarFecha();
        void mostrarFecha();
        bool esBisiesto();
        std::string toString(std::string formatoFecha);
        void agregarDias(int dia );
        void restarDias(int dia);


    //protected:

    private:
        int _dia ;
        int _mes;
        int _anio;
        void fechaPorDefecto();
        void agregarDia();
        void restarDia();

};

#endif // FECHA_H
