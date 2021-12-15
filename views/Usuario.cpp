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
	return this->getDni()+"."+this->getNickname()+", rol: "+this->getRol()+"\n";
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

	if(listaUsuarios.size()<1) return true; //Si la lista esta vacia

	for (auto it=listaUsuarios.begin();it!=listaUsuarios.end();++it){
		//Existe usuario con ese dni
		if(it->getDni()==this->getDni()){
			return false;
		}
	}

	return true;
}

/**
 * Añado usuario al final de la lista
 * Devuelve true si se ha insertado y false si no se ha podido
 */
bool Usuario::addUsuario(Usuario user){
	if(user.validarUsuario()){ //Si puedo insertar el usuario
		listaUsuarios.push_back(user);
		return true;
	}
	return false;
}

/**
 * Borrar usuario de la lista
 * Devuelve true si se ha podido eliminar y false si no se ha podido
 */
bool Usuario::deleteUsuario(Usuario user){
	if(user.validarUsuario()){ //Existe usuario en mi lista
		for (auto it=listaUsuarios.begin();it!=listaUsuarios.end();++it){
				//Existe usuario con ese dni
				if(it->getDni()==user.getDni()){
					listaUsuarios.remove(*it);
					return true;
				}
			}
	}
	return false;
}

/**
 * Muestra el usuario por dni
 * Devuelve el Usuario encontrado con ese id si lo encuentra o devuelve -1
 * si no lo ha encontrado ese dni
 */
Usuario Usuario::showUserByDNI(string dni){
	for (auto it=listaUsuarios.begin();it!=listaUsuarios.end();++it){
			//Existe usuario con ese dni
			if(it->getDni()==dni){
				return *it;
			}
		}
	return (Usuario("-1","","","",""));
}

/**
 *Cambia todas las propiedades de un usuario
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Usuario::changeUserByDNI(string dni,Usuario user){
	for (auto it=listaUsuarios.begin();it!=listaUsuarios.end();++it){
				//Existe usuario con ese dni
				if(it->getDni()==dni){
					listaUsuarios.erase(it);
					listaUsuarios.insert(it,user);
					return true;
				}
			}
		return false;
}


