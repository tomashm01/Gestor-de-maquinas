#include "Maquina.h"
Maquina::Maquina(int id_, int nucleos_, string descrip_){
	
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
string Maquina::getDescrip() {
	return this->descrip_;

}

void Maquina::setId(int id_) {
	this->id_ = id_;
}
void Maquina::setNucelos(int nucleos_) {
	this->nucleos_ = nucleos_;
}
void Maquina::setDescrip(string descrip_) {
	this->descrip_ = descrip_;
}


/**
 * Validar si la maquina ya existe
 * Devuelve true si se puede insertar la maquina y false si no se puede porque
 * ya existe
 */
bool Maquina:: validarMaquina() {

	ifstream rdMaquina("maquinas.txt");
    if(!rdMaquina){
		return false;
	}else{
		string linea;
    	while(getline(rdMaquina,linea,',')){
    	    if(stoi(linea)==this->getId()){
				rdMaquina.close();
				return false;
			}
    	}
		rdMaquina.close();
		return true;
	}
}



/**
 * Añado maquinas al final de la lista
 * Devuelve true si se ha insertado y false si no se ha podido
 */
bool Maquina::addMaquina(Maquina maquina){
	ofstream wrMaquinas("maquinas.txt",ios::app);
	if(!wrMaquinas){
		return false;
	}else{
		if(maquina.validarMaquina()){ //Si puedo insertar la maquina
			wrMaquinas<<maquina.getId()<<","<<maquina.getNucleos()<<","<<maquina.getDescrip()<<endl;
			wrMaquinas.close();
			return true;
		}else{
			wrMaquinas.close();
			return false;
		}
	}
}


/**
 * Borrar maquina de la lista
 * Devuelve true si se ha podido eliminar y false si no se ha podido
 */
bool Maquina :: deleteMaquina(Maquina maquina){
	ifstream rdMaquinas("maquinas.txt");
	if(maquina.validarMaquina()){ //Existe maquina en mi lista
		string linea;
		while(getline(rdMaquinas,linea,',')){
			if(stoi(linea)==maquina.getId()){//Elimino la linea entera
				linea.clear();
			}
		}
		rdMaquinas.close();
		return true;
	}
	return false;
}


/**
 *Cambia todas las propiedades de una maquina
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Maquina::changesMaquinaByID(Maquina maquina){
	if(deleteMaquina(maquina)){
		return addMaquina(maquina);
	}
	return false;
}