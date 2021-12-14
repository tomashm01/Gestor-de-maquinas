#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>

#ifndef RESERVA_H
#define RESERVA_H
using namespace std;

class Reserva {

private:

	int idReserva_;
	int maxdias_;
	string fechain_;
	string fechaout_;
	static std::list<Reserva> listaReserva;

public:

	Reserva(int idReserva, int maxdias,string fechain, string fechaout);

	int getId();
	int getDias();
	string getFechaIn();
	string getFechaOut();

	void setId(int idReserva);
	void setDias(int maxdias);
	void setFechaIn(string fechain);
	void setFechaOut(string fechaout);

	bool addReserva(Reserva reserve);
	bool deleteReserva(Reserva reserve);
	Reserva showReservaByID(int idReserva);
	bool changeReservaByID(int idReserva,Reserva reserve);
	bool validarReserva();
};

#endif 