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
    	while(getline(rdMaquina, linea)){
			string id=linea.substr(0,linea.find(','));
			if(id==to_string(this->getId())){
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
bool Maquina::addMaquina(){
	ofstream wrMaquinas("maquinas.txt",ios::app);
	if(!wrMaquinas){
		return false;
	}else{
		if(this->validarMaquina()){ //Si puedo insertar la maquina
			wrMaquinas<<this->getId()<<","<<this->getNucleos()<<","<<this->getDescrip()<<endl;
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
bool Maquina :: deleteMaquina(){
	ifstream rdReservas("maquinas.txt");
	ofstream wrReservas("temporal.txt");
	int lineasFichAntiguo=0,lineasFichNuevo=0;
	string linea;

	if(!this->validarMaquina()){ //Existe usuario en mi lista	
		while(getline(rdReservas, linea)){
			string dni=linea.substr(0,linea.find(','));
			if(atoi(dni.c_str())==this->getId()){
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
	rename("temporal.txt","maquinas.txt");
	return true;
}


/**
 *Cambia todas las propiedades de una maquina
 *Para ello lo elimino y lo inserto
 *Devuelve true si lo modifica correctamente y false si no lo hace
 */
bool Maquina::changesMaquina(Maquina maquina){
	if(maquina.deleteMaquina()){
		return maquina.addMaquina();
	}
	return false;
}

/**
 * Devuelve una máquina 
 * 
 */
void Maquina::showMaquinas(){
	ifstream rdMaquina("maquinas.txt");
	string linea;
	string id,nucleos,descrip;
	while(getline(rdMaquina,linea)){
		stringstream ss(linea);
		getline(ss,id,',');
		getline(ss,nucleos,',');
		getline(ss,descrip,',');
		cout<<id<<"."<<" Nucleos: "<<nucleos<<". Descripcion: "<<descrip<<endl;
	}
}