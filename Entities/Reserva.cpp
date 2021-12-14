#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include "Reserva.h"

Reserva::Reserva(int idReserva, int max_dias, char* fechain, char* fechaout) {
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
char* Reserva::getFechaIn() {
	return fechain_;
}
char* Reserva::getFechaOut() {
	return this->fechaout_;
}

char* Reserva::toString(){
	return getId() + ":" + getDias() + ", fecha de entrada: " + getFechaIn() + " y fecha de salida: " + getfechaOut() + "\n";
}

void Reserva::setId(int idReserva) {
	idReserva_ = idReserva;
}
void Reserva::setDias(int max_dias) {
	this->maxdias_ = max_dias;
}
void Reserva::setFechaIn(char* fechain) {
	this->fechain_ = fechain;
}
void Reserva::setFechaOut(char* fechaout) {
	this->fechaout_ = fechaout;
}

/**
 * Validar si la Reserva ya existe
 * Devuelve true si se puede insertar la reserva y false si no se puede porque
 * ya existe
 */
bool Reserva::validarReserva() {

	if(listaReserva.size()<1) return true; //Si la lista esta vacia

	for (auto it=listaReserva.begin();it!=listaReserva.end();++it){
		//Existe Reserva con ese id
		if(it->getId()==this->getId()){
			return false;
		}
	}

	return true;
}

/**
 * Añado Rserva al final de la lista
 * Devuelve true si se ha insertado y false si no se ha podido
 */
bool Reserva::addReserva(Reserva reserve){
	if(reserve.validarReserva()){ //Si puedo insertar el Reserva
		listaReserva.push_back(reserve);
		return true;
	}
	return false;
}
/**
 * Borrar Reserva de la lista
 * Devuelve true si se ha podido eliminar y false si no se ha podido
 */
bool Reserva::deleteReserva(Reserva reserve){
	if(reserve.validarReserva()){ //Existe Reserva en mi lista
		for (auto it=listaReserva.begin();it!=listaReserva.end();++it){
				//Existe Reserva con ese dni
				if(it->getId()==reserve.getId()){
					listaReserva.remove(*it);
					return true;
				}
			}
	}
	return false;
}

/**
 * Muestra la Reserva por dni
 * Devuelve la Reserva encontrada con ese id si lo encuentra o devuelve -1
 * si no lo ha encontrado ese id
 */
Reserva Reserva::showReservaByID(int id){
	for (auto it=listaReserva.begin();it!=listaReserva.end();++it){
			//Existe Reserva con ese id
			if(it->getId()==id){
				return *it;
			}
		}
	return Reserva(-1,0,"","");
}

/**
 *Cambia todas las propiedades de una Reserva
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Reserva::changeReservaByID(int idReserva,Reserva reserve){
	for (auto it=listaReserva.begin();it!=listaReserva.end();++it){
				//Existe Reserva con ese id
				if(it->getId()==idReserva){
					listaReserva.erase(it);
					listaReserva.insert(it,reserve);
					return true;
				}
			}
		return false;
}
