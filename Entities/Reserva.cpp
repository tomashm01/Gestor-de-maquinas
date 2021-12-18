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
string Reserva::toString(){
	return to_string(this->getId())+".Fecha reserva: "+this->getFechaIn()+", fecha salida: "+this->getFechaOut()+"\n";
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
    	while(getline(rdReserva, linea)){
			string id=linea.substr(0,1);
			if(stoi(id)==this->getId()){
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
bool Reserva::addReserva(){

	ofstream wrReservas("reservas.txt",ios::app);
	if(!wrReservas){
		return false;
	}else{
		if(this->validarReserva()){ //Si puedo insertar la reserva
			wrReservas<<this->getId()<<","<<this->getDias()<<","<<this->getFechaIn()<<","<<this->getFechaOut()<<endl;
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
bool Reserva::deleteReserva(int idEliminar){
	ifstream rdReserva("reservas.txt");
	ofstream wrReservas("reservas.txt",ios::app);
		string linea;
		while(getline(rdReserva, linea)){
			string id=linea.substr(0,1);
			if(stoi(id)==idEliminar){
				wrReservas<<linea.erase(0,linea.find("\n"));
				return true;
			}
    	}
	wrReservas.close();
	rdReserva.close();
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
		stringstream ss(linea);
		if(stoi(linea.substr(0,linea.find(',')))==id){
			string id,maxdias,fechain, fechaout;
			getline(ss,id,',');
			getline(ss,maxdias,',');
			getline(ss,fechain,',');
			getline(ss,fechaout);
			Reserva userReturn=Reserva(stoi(id),stoi(maxdias),fechain,fechaout);
			rdReserva.close();
			return userReturn;
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
	if(this->deleteReserva(reserve.getId())){
		return this->addReserva();
	}
	return false;
}
