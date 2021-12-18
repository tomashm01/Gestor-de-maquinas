#include "../Entities/Maquina.h"
#include "../Entities/Reserva.h"
#include "../Entities/Usuario.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    //Ejecucion g++ -o ejecutable view.cpp 
    //Añado usuario al fichero
    ofstream wrReservas("reservas.txt", ios::app);
    if(!wrReservas){
        cout << "Error al abrir el fichero" << endl;
        return -1;
    }else{
        Usuario user=Usuario("1","Pepe","Perez","","");
        user.deleteUsuario(user.getDni());

        Reserva reserva=Reserva(7,1,"2019-01-01","2019-01-01");
        cout<<reserva.showReservaByID(7).toString()<<endl;
       
        wrReservas.close();
    }


	return 0;
}
