#include "Reserva.h"

Reserva::Reserva(int idReserva, int max_dias, string fechain, string fechaout) {
	this->setDias(max_dias);
	this->setFechaIn(fechain);
	this->setFechaOut(fechaout);
	this->setId(idReserva);
}

//SETTERS Y GETTERS
int Reserva::getId() {
	return idReserva_;
}
int Reserva::getDias() {
	return this->maxdias_;
}
string Reserva::getFechaIn() {
	return fechain_;
}
string Reserva::getFechaOut() {
	return this->fechaout_;
}

void Reserva::setId(int idReserva) {
	idReserva_ = idReserva;
}
void Reserva::setDias(int max_dias) {
	this->maxdias_ = max_dias;
}
void Reserva::setFechaIn(string fechain) {
	this->fechain_ = fechain;
}
void Reserva::setFechaOut(string fechaout) {
	this->fechaout_ = fechaout;
}

/**
 * Validar si la Reserva ya existe
 * Devuelve true si se puede insertar la reserva y false si no se puede porque
 * ya existe
 */
bool Reserva::validarReserva() {

	ifstream rdReserva("reservas.txt");
    if(!rdReserva){
		return false;
	}else{
		string linea;
    	while(getline(rdReserva,linea,',')){
    	    if(stoi(linea)==this->getId()){
				rdReserva.close();
				return false;
			}
    	}
		rdReserva.close();
		return true;
	}
}

/**
 * Añado Reserva al final de la lista
 * Devuelve true si se ha insertado y false si no se ha podido
 */
bool Reserva::addReserva(Reserva reserve){

	ofstream wrReservas("reservas.txt",ios::app);
	if(!wrReservas){
		return false;
	}else{
		if(reserve.validarReserva()){ //Si puedo insertar la reserva
			wrReservas<<reserve.getId()<<","<<reserve.getDias()<<","<<reserve.getFechaIn()<<","<<reserve.getFechaOut()<<endl;
			wrReservas.close();
			return true;
		}else{
			wrReservas.close();
			return false;
		}
	}
}
/**
 * Borrar Reserva de la lista
 * Devuelve true si se ha podido eliminar y false si no se ha podido
 */
bool Reserva::deleteReserva(Reserva reserve){
	ifstream rdReserva("reservas.txt");
	if(reserve.validarReserva()){ //Existe reserva en mi lista
		string linea;
		while(getline(rdReserva,linea,',')){
			if(stoi(linea)==reserve.getId()){//Elimino la linea entera
				linea.clear();
			}
		}
		rdReserva.close();
		return true;
	}
	return false;
}

/**
 * Muestra la Reserva por dni
 * Devuelve la Reserva encontrada con ese id si lo encuentra o devuelve -1
 * si no lo ha encontrado ese id
 */
Reserva Reserva::showReservaByID(int id){
	ifstream rdReserva("reservas.txt");
	string linea;
	while(getline(rdReserva,linea)){
		if(linea.find(id)!=string::npos){
			Reserva resReturn=Reserva(stoi(linea.substr(0,linea.find(','))),stoi(linea.substr(linea.find(',')+1,linea.find(',')+1)),linea.substr(linea.find(',')+2,linea.find(',')+2),linea.substr(linea.find(',')+3,linea.find(',')+3));
			rdReserva.close();
			return resReturn;
		}
	}
	return Reserva(-1,0,"","");
}

/**
 *Cambia todas las propiedades de una Reserva
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Reserva::changeReservaByID(Reserva reserve){
	if(deleteReserva(reserve)){
		return addReserva(reserve);
	}
	return false;
}
