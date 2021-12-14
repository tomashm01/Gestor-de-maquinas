#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>

#ifndef _Maquinas_
#define _Maquinas_

using namespace std;

class Maquina{
    private:
    
    int id_;
    int nucleos_;
    char* descrip_;
    static std::list<Maquina> listaMaquinas;
    

    public:
	Maquina(int id_, int nucleos_, char *descrip_);

    int getId();
	int getNucleos();
	char* getDescrip();
    char* toString();

	void setId(int id_);
	void setNucelos(int nucleos_);
	void setDescrip(char* descrip_);
    	

    bool validarMaquina();

    bool addMaquina(Maquina maquina);

    bool deleteMaquina(Maquina maquina);

    bool changesMaquinaByID(int id_ , Maquina maquina);

};

#endif