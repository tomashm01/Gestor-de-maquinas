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
        Usuario user=Usuario("2","Pepe","Perez","","");
        string dni="25";
        cout<<user.showUserByDNI(dni).toString()<<endl;

        Reserva reserva=Reserva(9,1,"2019-01-01","2019-01-01");
        cout<<reserva.showReservaByID(10).toString()<<endl;
       
        Maquina maquina=Maquina(2,2,"Maquina 1");
        maquina.addMaquina();
        wrReservas.close();
    }


	return 0;
}
