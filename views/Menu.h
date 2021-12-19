#ifndef _Menu_
#define _Menu_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Menu{
    private:
        int opcion;
        string titulo;
        vector <string> opciones;
 
    public:
	    Menu(int opcion, string titulo, vector<string> opciones);
 
        inline void setOpcion(int opcion) { this->opcion = opcion;};
        inline int getOpcion(){return this->opcion;};
        inline int getOpciones(){return this->opciones.size();};
        void mostrar();
};

#endif