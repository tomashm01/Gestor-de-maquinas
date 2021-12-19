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

	int id;
	string dniUser;
	int idMaquina;
	int maxdias_;
	string fechain_;
	string fechaout_;

public:

	Reserva(int id,string dniUser,int idMaquina, int maxdias,string fechain, string fechaout);

	string getDni();
	int getDias();
	int getId();
	int getIdMaquina();
	string getFechaIn();
	string getFechaOut();
	string toString();
	
	void setId(int id);
	void setIdMaquina(int id);
	void setDni(string idReserva);
	void setDias(int maxdias);
	void setFechaIn(string fechain);
	void setFechaOut(string fechaout);

	bool validarReserva();
	bool addReserva();
	bool deleteReserva();
	Reserva showReservaByDni(string dniUser);
	bool changeReserva(Reserva reserve);
	void showReservas(string dni);

};

#endif 