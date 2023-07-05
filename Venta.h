#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"
#include "Cliente.h"



class Venta
{
	public:
	Venta();
	void setearVenta (int id,Fecha fecha, float importe ,int cantVendida, int idProducto, bool estado, Cliente cliente );
	void setIdVenta (int id);
	void setImporte (float importe);
	void setCantidadVendida (int cantidad);
	void setIdProducto (int idProducto);
	void setEstado (bool estado);
	void setImporteTotal(float importe);


	int generarId();
	float generarImporte(int cant, int id);

	bool validarId(int id);
	int  validarCantidad(int id, int cantidad,int &stockDisponible);


	Cliente getCliente();
	int 	getIdVenta();
	float getImporte();
	int 	getCantidadVendida();
	int 	getIdProducto();
	bool  getEstado();
	int getDia();
	int getMes();
	int getAnio();
	float getImporteTotal();
	Fecha getFecha();

	void modificarVenta(int idVenta );
	void cargar();
	void mostrar();


	private:
	int _idVenta;
	Fecha _fechaVenta;
	float _importe;
	int _cantidadVendida;
	int _idProducto;
	bool _estadoVenta;
	Cliente _clienteVenta;

};

#endif // VENTA_H
