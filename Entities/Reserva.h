#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef RESERVA_H
#define RESERVA_H
using namespace std;

class Reserva {

private:

	int idReserva_;
	int maxdias_;
	string fechain_;
	string fechaout_;

public:

	Reserva(int idReserva, int maxdias,string fechain, string fechaout);

	int getId();
	int getDias();
	string getFechaIn();
	string getFechaOut();
	string toString();
	
	void setId(int idReserva);
	void setDias(int maxdias);
	void setFechaIn(string fechain);
	void setFechaOut(string fechaout);

	bool validarReserva();
	bool addReserva();
	bool deleteReserva();
	Reserva showReservaByID(int idReserva);
	bool changeReserva(Reserva reserve);

};

#endif 