#ifndef _Maquinas_
#define _Maquinas_

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class Maquina{
    private:
        int id_;
        int nucleos_;
        string descrip_;
 
    public:
	    Maquina(int id_, int nucleos_, string descrip_);

        int getId();
	    int getNucleos();
	    string getDescrip();

	    void setId(int id_);
	    void setNucelos(int nucleos_);
	    void setDescrip(string descrip_);

        bool validarMaquina();
        bool addMaquina();
        bool deleteMaquina(Maquina maquina);
        bool changesMaquinaByID(Maquina maquina);

};

#endif