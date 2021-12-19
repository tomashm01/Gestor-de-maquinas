#ifndef _Maquinas_
#define _Maquinas_

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
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
	    string getDescripcion();

	    void setId(int id_);
	    void setNucleos(int nucleos_);
	    void setDescripcion(string descrip_);

        bool validarMaquina();
        bool addMaquina();
        bool deleteMaquina();
        bool changesMaquina();
        void showMaquinas();

};

#endif