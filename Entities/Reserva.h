#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>

#ifndef RESERVA_H
#define RESERVA_H

class Reserva {

private:

	int idReserva_;
	int maxdias_;
	char* fechain_;
	char* fechaout_;
	static std::list<Reserva> listaReserva;

public:

	Reserva(int idReserva, int maxdias,char* fechain, char* fechaout);

	int getId();
	int getDias();
	char* getFechaIn();
	char* getFechaOut();
	char* toString();

	void setId(int idReserva);
	void setDias(int maxdias);
	void setFechaIn(char* fechain);
	void setFechaOut(char* fechaout);

	bool addReserva(Reserva reserve);
	bool deleteReserva(Reserva reserve);
	Reserva showReservaByID(int idReserva);
	bool changeReservaByID(int idReserva,Reserva reserve);
	bool validarReserva();
};

#endif 