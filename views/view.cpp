// #include "../Entities/Maquina.h"
// #include "../Entities/Reserva.h"
#include "../Entities/Usuario.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    //Ejecucion g++ -o ejecutable view.cpp Usuario.cpp
    //Añado usuario al fichero
    ofstream wrUsuarios("usuarios.txt", ios::app);
    if(!wrUsuarios){
        cout << "Error al abrir el fichero" << endl;
        return -1;
    }else{
        Usuario user("4565625","12345678A","nick","nombre","rol");
        //user.addUsuario(user);
        // user.deleteUsuario(user);
        string dni="MIDNI";
        user.setDni(dni);
        user.changeUserByDNI(user);
        
    }


	return 0;
}
