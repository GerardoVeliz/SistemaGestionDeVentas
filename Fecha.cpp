
#include "Fecha.h"
#include <iostream>
using namespace std ;

        Fecha::Fecha(){
            fechaPorDefecto();  //uso la funcion que hice en el constructor
        }
        Fecha::Fecha(int d, int m,int a){
        _dia=d;
        _mes=m;
        _anio=a;
        if (_dia < 0||_mes <= 0 || _anio <= 0 || _mes > 12){
            fechaPorDefecto();
        }else {
        int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (esBisiesto()){
            dias[1]++;
        }
        if (_dia > dias [_mes-1]){
            fechaPorDefecto();
        }
        }
        }

        void Fecha::fechaPorDefecto(){
            _dia=1;
            _mes=1;
            _anio=1900;
        }

        void Fecha::setDia(int d){
            _dia=d;
        }

        void Fecha::setMes(int m){
            _mes=m;
        }
        void Fecha::setAnio(int a){
            _anio=a;
        }
        int Fecha::getDia(){
            return _dia;
        }
        int Fecha::getMes(){
            return _mes;
        }
        int Fecha::getAnio(){
            return _anio;
        }
        bool Fecha::esBisiesto(){
        if ((_anio%4==0 && _anio % 100 !=0)|| _anio%400==0){
            return true ;
        }
        return false ;
        }
        std::string Fecha::toString (std::string formatoFecha){
        std:: string dd=std::to_string(_dia);///creo 3 string sonde guardar la fecha con el formato 0+_dia
        std:: string mm=std::to_string(_mes);///ademas dentro ya estan incializadas con los dias mes anio del private
        std:: string yyyy=std::to_string(_anio);
        std:: string fechaFormateada=" "; ///fecha formateada es el string que va a retornar con la fecha
        if(_dia < 10){
            dd="0"+std::to_string(_dia); /// estas son validaciones para que me ponga un 0 delante del numero si
                                            ///los dias son unidades osea menores a 10 ,

        }
        if (_mes<10){
            mm="0"+std::to_string(_mes);
        }

        if (formatoFecha=="dd/mm/yyyy"){
            fechaFormateada= dd+ "/" + mm + "/" + yyyy;
        } else {
            if (formatoFecha=="yyyy/mm/dd"){
                fechaFormateada= yyyy+"/" + mm + "/" + dd ;
            } else {
                fechaFormateada= dd+ "/" + mm + "/" + yyyy;
            }
        }
        return fechaFormateada;
        }

         void Fecha::restarDia(){
             int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (esBisiesto()){
            dias[1]++;
        }
        _dia--;
        if (_dia == 0 ){
            _dia=dias[11];
            _mes--;
            if (_mes < 1){
                _mes=12;
                _anio--;
            }
        }
         }
                 void Fecha::restarDias(int dia){
                 if (dia>0){
                    for (int x=0 ; x<dia ; x++){
                        restarDia();
                    }
                 }
                 }


         void Fecha::agregarDia(){
              int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (esBisiesto()){
            dias[1]++;
        }
             _dia++ ;
             if (_dia>dias[_mes-1]){
                _dia=1 ;
                _mes++ ;
                if (_mes>12){
                    _mes=1;
                    _anio++;
                }
             }



         }
        void Fecha::agregarDias(int dia ){
            if (dia>0){
            for (int x=0 ; x<dia ; x++){
                agregarDia();
            }

            }
        }

        void Fecha::cargarFecha(){
        cout <<"INGRESAR DIA: ";
        cin>>_dia;
        cout <<"INGRESAR MES: ";
        cin>>_mes;
        cout <<"INGRESAR ANIO: ";
        cin>>_anio;
        }
