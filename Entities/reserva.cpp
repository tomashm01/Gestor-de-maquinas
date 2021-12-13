#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include "reserva.h"

Reserva::Reserva(int *idReserva, int *max_dias, string *fechain, string *fechaout) 
{
	idReserva_ = idReserva;
	max_dias_ = max_dias;
	fechain_ = fechain;
	fechaout_ = fechaout;
}


int* Reserva::getId() 
{
	return idReserva_;
}
int* Reserva::getDias() 
{
	return max_dias_;
}
string* Reserva::getFechaIn() 
{
	return fechain_;
}
char* Reserva::getfechaOut() 
{
	return fechaout_;
}

char* Reserva::toString()
{
	return getId() + ":" + getDias() + ", fecha de entrada: " + getFechaIn() + " y fecha de salida: " + getfechaOut() + "\n";
}

void Reserva::setId(int *idReserva) 
{
	idReserva_ = idReserva;
}
void Reserva::setDias(int *max_dias) 
{
	max_dias_ = max_dias;
}
void Reserva::setFechaIn(string *fechain) 
{
	fechain_ = fechain;
}
void Reserva::setFechaOut(string *fechaout) 
{
	fechaout_ = fechaout;
}

void Reserva::addReserva(Reserva reserve)
{
		listaReserva.push_back(reserve);
}

bool Reserva::deleteReserva(Reserva reserve)
{
	list<int>::iterator it;

		for (it = listaReserva.begin(); it != listaReserva.end(); ++it)
		{
				if((*it)->getId() == reserve.getId())
				{
					listaReserva.remove(*it);
					return true;
				}
			}
	return false;
}


int Reserva::showReservaByID(int* idReserva)
{
	list<int>::iterator it;

	for (it = listaReserva.begin(); it != listaReserva.end(); ++it)
	{
			if((*it)->getId() == idReserva)
			{
				return (*it);
			}
		}
	return -1;
}

bool Reserva::changeReservaByID(int* idReserva,Reserva reserve)
{
	list<int>::iterator it;

	for (it = listaReserva.begin(); it != listaReserva.end(); ++it)
	{
				if((*it)->getId() == idReserva)
				{
					listaReserva.erase(it);
					listaReserva.insert(it,reserve);
					return true;
				}
			}
		return false;
}

