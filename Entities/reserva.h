#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>

#ifndef RESERVA_H
#define RESERVA_H

class Usuario 
{

private:

	int *idReserva_;
	int *maxdias_;
	string *fechain_;
	string *fechaout_;
	static std::list<Reserva> listaReservas_;

public:

	Reserva(int *idReserva, int *maxdias, string *fechain, string *fechaout);

	int* getId();
	int* getDias();
	string* getFechaIn();
	string* getFechaOut();
	char* toString();

	void setId(int* idReserva);
	void setDias(char* maxdias);
	void setFechaIn(char* fechain);
	void setFechaOut(char* fechaout);

	void addReserva(Reserva reserve);
	bool deleteReserva(Reserva reserve);
	Reserva showReservaByID(int* idReserva);
	bool changeReservaByID(int* idReserva,Reserva reserve);

};

#endif 