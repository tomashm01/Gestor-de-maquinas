// #include "../Entities/Maquina.h"
// #include "../Entities/Reserva.h"
#include "Usuario.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void){
    Usuario* tomas = new Usuario("Tomas", "12345", "3545geg","miNombre","fef");
	cout<<tomas->toString()<<endl;
	return 0;
}
