#include "Reserva.h"

Reserva::Reserva(int id,string dniUsuario,int idMaquina, int max_dias, string fechain, string fechaout) {
	this->setId(id);
	this->setIdMaquina(idMaquina);
	this->setDias(max_dias);
	this->setFechaIn(fechain);
	this->setFechaOut(fechaout);
	this->setDni(dniUsuario);
}

//SETTERS Y GETTERS
string Reserva::getDni() {
	return this->dniUser;
}
int Reserva::getId() {
	return this->id;
}
int Reserva::getIdMaquina() {
	return this->idMaquina;
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
	return this->getDni()+".Fecha reserva: "+this->getFechaIn()+", fecha salida: "+this->getFechaOut()+"\n";
}

void Reserva::setDni(string dniUser) {
	this->dniUser = dniUser;
}
void Reserva::setId(int id) {
	this->id = id;
}
void Reserva::setIdMaquina(int idMaquina) {
	this->idMaquina = idMaquina;
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
			string id=linea.substr(0,linea.find(','));
			if(atoi(id.c_str())==this->getId()){
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
			wrReservas<<this->getId()<<","<<this->getDni()<<","<<this->getIdMaquina()<<","<<this->getDias()<<","<<this->getFechaIn()<<","<<this->getFechaOut()<<endl;
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
bool Reserva::deleteReserva(){
	ifstream rdReservas("reservas.txt");
	ofstream wrReservas("temporal.txt");
	int lineasFichAntiguo=0,lineasFichNuevo=0;
	string linea;

	if(!this->validarReserva()){ //Existe usuario en mi lista	
		while(getline(rdReservas, linea)){
			string id=linea.substr(0,linea.find(','));
			if(atoi(id.c_str())==this->getId()){
				lineasFichAntiguo++;
				continue;
			}else{
				wrReservas<<linea<<endl;
				lineasFichNuevo++;
				lineasFichAntiguo++;
			}
    	}
	}
	if(lineasFichAntiguo==lineasFichNuevo){ //Si son mismas lineas no se ha eliminado
		return false;
	}
	rename("temporal.txt","reservas.txt");
	return true;
}

/**
 * Muestra la Reserva por dni
 * Devuelve la Reserva encontrada con ese id si lo encuentra o devuelve -1
 * si no lo ha encontrado ese id
 */
Reserva Reserva::showReservaByDni(string dniUser){
	ifstream rdReserva("reservas.txt");
	string linea;

	while(getline(rdReserva,linea)){

		stringstream ss(linea);
		string id,idMaquina,dniUsuario,maxdias,fechain, fechaout;
		getline(ss,id,',');
		getline(ss,dniUsuario,',');

		if(dniUsuario==dniUser){
			getline(ss,idMaquina,',');
			getline(ss,maxdias,',');
			getline(ss,fechain,',');
			getline(ss,fechaout);
			Reserva userReturn=Reserva(atoi(id.c_str()),dniUsuario,atoi(idMaquina.c_str()),atoi(maxdias.c_str()),fechain,fechaout);
			rdReserva.close();
			return userReturn;
		}
	}
	return Reserva(1,"0",0,0,"","");
}

/**
 *Cambia todas las propiedades de una Reserva
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Reserva::changeReserva(Reserva reserve){
	if(reserve.deleteReserva()){
		return reserve.addReserva();
	}
	return false;
}

//Muestra todas las reservas
void Reserva::showReservas(string dni){
	ifstream rdReserva("reservas.txt");
	string linea;
	string id,fechaIn,fechaOut,maxdias,idMaquina,dniUser;
	while(getline(rdReserva,linea)){
		stringstream ss(linea);
		getline(ss,id,',');
		getline(ss,dniUser,',');
		if(dni==dniUser){
			getline(ss,idMaquina,',');
			getline(ss,maxdias,',');
			getline(ss,fechaIn,',');
			getline(ss,fechaOut,',');
			Reserva rs=Reserva(atoi(id.c_str()),dniUser,atoi(idMaquina.c_str()),atoi(maxdias.c_str()),fechaIn, fechaOut);
			cout<<rs.toString();
		}
		
	}
}