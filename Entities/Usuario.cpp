/*
 * Usuario.cpp
 *
 *  Created on: 22 nov. 2021
 *      Author: tomas
 */

#include "Usuario.h"

Usuario::Usuario(string dni, string password, string nickname,
		string nombreCompleto, string rol) {
	this->dni = dni;
	this->password = password;
	this->nickname = nickname;
	this->nombreCompleto = nombreCompleto;
	this->rol = rol;
}

//GETTERS Y SETTERS
string Usuario::getDni() {
	return this->dni;
}
string Usuario::getPassword() {
	return this->password;
}
string Usuario::getNombre() {
	return this->nombreCompleto;
}
string Usuario::getNickname() {
	return this->nickname;
}
string Usuario::getRol() {
	return this->rol;
}
string Usuario::toString(){
	return this->getDni()+".Nickname: "+this->getNickname()+", rol: "+this->getRol()+"\n";
}

void Usuario::setDni(string dni) {
	this->dni = dni;
}
void Usuario::setPassword(string password) {
	this->password = password;
}
void Usuario::setNickname(string nickname) {
	this->nickname = nickname;
}
void Usuario::setNombre(string nombreCompleto) {
	this->nombreCompleto = nombreCompleto;
}
void Usuario::setRol(string rol) {
	this->rol = rol;
}

/**
* Validar si el usuario ya existe
* Devuelve true si se puede insertar el usuario y false si no se puede porque
* ya existe
*/
bool Usuario::validarUsuario() {

	ifstream rdUsuarios("usuarios.txt");
	if (!rdUsuarios) {
		return false;
	} else {
		string linea;
    	while(getline(rdUsuarios,linea,',')){
    	    if(linea==this->getDni()){
				rdUsuarios.close();
				return false;
			}
    	}
		rdUsuarios.close();
		return true;
	}
}

/**
* Añado usuario al final de la lista
* Devuelve true si se ha insertado y false si no se ha podido
*/
bool Usuario::addUsuario(Usuario user){
	ofstream wrUsuarios("usuarios.txt",ios::app);
	if(!wrUsuarios){
		return false;
	}else{
		if(user.validarUsuario()){ //Si puedo insertar el usuario
			wrUsuarios<<user.getDni()<<","<<user.getPassword()<<","<<user.getNickname()<<","<<user.getNombre()<<","<<user.getRol()<<endl;
			wrUsuarios.close();
			return true;
		}else{
			wrUsuarios.close();
			return false;
		}
	}
}

/**
* Borrar usuario de la lista
* Devuelve true si se ha podido eliminar y false si no se ha podido
*/
bool Usuario::deleteUsuario(string dni){
	ifstream rdUsuarios("usuarios.txt");
	if(this->validarUsuario()){ //Existe usuario en mi lista
		string linea;
		while(getline(rdUsuarios,linea,',')){
			if(linea==dni){//Elimino la linea entera
				linea.clear();
			}
		}
		rdUsuarios.close();
		return true;
	}
	return false;
}

/**
* Muestra el usuario por dni
* Devuelve el Usuario encontrado con ese id si lo encuentra o devuelve -1
* si no lo ha encontrado ese dni
*/
Usuario Usuario::showUserByDNI(string dni){
	ifstream rdUsuarios("usuarios.txt");
	string linea;
	while(getline(rdUsuarios,linea)){
		stringstream ss(linea);
		if(linea.substr(0,linea.find(','))==dni){
			string dni,password,nickname,nombreCompleto,rol;
			getline(ss,dni,',');
			getline(ss,password,',');
			getline(ss,nickname,',');
			getline(ss,nombreCompleto,',');
			getline(ss,rol);
			Usuario userReturn=Usuario(dni,password,nickname,nombreCompleto,rol);
			rdUsuarios.close();
			return userReturn;
		}
	}
	return (Usuario("-1","","","",""));
}

/**
*Cambia todas las propiedades de un usuario
*Para ello lo elimino y lo inserto
*Devuelve true si lo modifica correctamente y false si no lo hace
*/
bool Usuario::changeUserByDNI(Usuario user){
	if(deleteUsuario(user.getDni())){
		return addUsuario(user);
	}
	return false;
}


