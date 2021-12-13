



#include "maquina.h"
Maquina::Maquina(int id_, int nucleos_, char *descrip_);
	
    this->id_ = id_;
	this->nucleos_ = nucleos_;
	this->descrip_ = descrip_;
}

//GETTERS Y SETTERS
int Maquina::getId() {
	return this->id_;
}
int Maquina::getNucleos() {
	return this->nucleos_;
}
char* Maquina::getDescrip() {
	return this->descrip_;

}
char* Maquina::toString(){
	return this->getId()+"."+this->getNucleos()+", descripcion: "+this->getDescrip()+"\n";
}

void Maquina::setId(int id_) {
	this->id_ = id_;
}
void Maquina::setNucelos(int nucleos_) {
	this->nucleos_ = nucleos_;
}
void Maquina::setDescrip(char *descrip_) {
	this->descrip_ = descrip_;
}


/**
 * Validar si la maquina ya existe
 * Devuelve true si se puede insertar la maquina y false si no se puede porque
 * ya existe
 */
bool Maquina:: validarMaquina() {

	if(listaMaquina.size()<1) return true; //Si la lista esta vacia

	for (auto it=listaMaquinas.begin();it!=listaMaquinas.end();++it){
		//Existe maquina con ese Id
		if(*it->getId()==this->getId()){
			return false;
		}
	}

	return true;
}



/**
 * Añado maquinas al final de la lista
 * Devuelve true si se ha insertado y false si no se ha podido
 */
bool Maquina::addMaquina(Maquina maquina){
	if(maquina.validarMaquina()){ //Si puedo insertar la maquina
		listaMaquinas.push_back(maquina);
		return true;
	}
	return false;
}


/**
 * Borrar maquina de la lista
 * Devuelve true si se ha podido eliminar y false si no se ha podido
 */
bool Maquina :: deleteMaquina(Maquina maquina){
	if(maquina.validarMaquina()){ //Existe maquina en mi lista
		for (auto it=listaMaquinas.begin();it!=listaMaquinas.end();++it){
				//Existe maquina con ese id
				if(*it->getId()==maquina.getId()){
					listaMaquinas.remove(*it);
					return true;
				}
			}
	}
	return false;
}


/**
 *Cambia todas las propiedades de una maquina
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Maquina::changesMaquinaByID(int id_,Maquina maquina){
	for (auto it=listaMaquinas.begin();it!=listaMaquinas.end();++it){
				//Existe maquina con ese Id
				if(*it->getId()==id_){
					listaMaquinas.erase(it);
					listaMaquinas.insert(it,maquina);
					return true;
				}
			}
		return false;
}