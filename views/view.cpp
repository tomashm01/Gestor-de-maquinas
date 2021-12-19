#include "../Entities/Maquina.h"
#include "../Entities/Reserva.h"
#include "../Entities/Usuario.h"
#include "Menu.h"
#include <ctime>
#include <ctype.h>
#include <iostream>


char validarDni(int letra){
	char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
	return letras[letra%23];
}

bool verificaDNI(string dni){
  if (dni.length()!=9)
      return 0;
  else
    return (validarDni(atoi(dni.c_str()))==dni[8]);
}


int main(void){

	Menu principal=Menu(0,"Menu Principal",{"Iniciar Sesion","Registrarse","Salir"});
	Menu menuUsuario=Menu(0,"Menu Usuario",{"Reservar","Cancelar reserva","Ver Reservas","Salir"});
	Menu menuMaquina=Menu(0,"Menu Maquina",{"Añadir reserva","Cancelar reserva","Ver Reservas","Salir"});
	Menu menuAdmin=Menu(0,"Menu Administrador",{"Añadir usuario","Eliminar usuario","Ver usuarios","Recuperar contraseña de un usuario","Salir"});

	bool salirApp=false,esUsuario=false,esAdminMaquina=false,esAdminUsuarios=false;
	string nombre,nickname,password,dni,rol,fechain,fechaout,descripcion;
	int id,nucleos,maxdias,idMaquina,diaOut,mesOut,anioOut,opcion=0;
	srand(time(NULL));
	time_t t = time(0);
	struct tm * now = localtime( & t );
	int dia=now->tm_mday;
	int mes=now->tm_mon+1;
	int anio=now->tm_year+1900;

	Usuario usuario=Usuario("","","","","");
	Usuario usuarioTemp=Usuario("","","","","");
	Maquina maquina=Maquina(0,0,"");
	Maquina maquinaTemp=Maquina(0,0,"");
	Reserva reserva=Reserva(0,"0",0,0,"","");
	Reserva reservaTemp=Reserva(0,"0",0,0,"","");

	do{ //Menu principal
		principal.mostrar();
		cin>>opcion;
		principal.setOpcion(opcion);
		switch(principal.getOpcion()){
			case 1:{ //Inicio sesion
				do{
					cout<<"Introduce tu dni: "<<endl;
					cin>>dni;
				}while(!verificaDNI(dni));
				cout<<"Introduce tu password: "<<endl;
				cin>>password;
				
				usuarioTemp=Usuario(dni,password,"","","");
				usuario=usuarioTemp.showUserByDNI(dni);

				if(usuario.getDni()=="-1" || usuario.getPassword()!=password){
					cout<<"Usuario no encontrado"<<endl;
				}else{
					cout<<"Bienvenido "<<usuario.getNombre()<<endl;
					//Comprobar rol
					if(usuario.getRol()=="usuario"){
						esUsuario=true;
					}else if(usuario.getRol()=="adminMaquinas"){
						esAdminMaquina=true;
					}else{
						esAdminUsuarios=true;
					}
					salirApp=true;
				}
				opcion=0;
				break;
			}
			case 2:{ //Registrarse

				cout<<"Introduce tu nombre: "<<endl;
				cin>>nombre;
				cout<<"Introduce tu nickname: "<<endl;
				cin>>nickname;
				do{ //Minimo 8 digitos
					cout<<"Introduce tu password: "<<endl;
					cin>>password;
				}while(password.length()<8);
				do{
					cout<<"Introduce tu dni: "<<endl;
					cin>>dni;
				}while(!verificaDNI(dni));
				rol="usuario";

				usuario=Usuario(dni,password,nickname,nombre,rol);

				if(usuario.addUsuario()){
					cout<<"Usuario registrado correctamente"<<endl;
					salirApp=true;
				}else{
					cout<<"Error al registrar usuario"<<endl;
				}
				opcion=0;
				break;
			}
			case 3: //Cerrar app
				return 0;
		}
	}while(!salirApp);

	do{
		menuUsuario.mostrar();
		cin>>opcion;
		menuUsuario.setOpcion(opcion);

		switch(menuUsuario.getOpcion()){
			case 1:{//Reservar

				do{
					cout<<"Introduce maximo dias de reserva:(0-15 dias) "<<endl;
					cin>>maxdias;
				}while(maxdias<0 || maxdias>15);

				//Obtener dia/mes/año actual y sumar maxdias			
				fechain=to_string(dia)+"/"+to_string(mes)+"/"+to_string(anio);
				//Valido la fecha out es correctamente
				diaOut=maxdias+dia;
				//Valido fecha final
				if(diaOut>31){
					diaOut=diaOut-31;
					mesOut=mes+1;
					if(mesOut>12){
						mesOut=1;
						anioOut=anio+1;
					}
				}else{
					diaOut=dia;
					mesOut=mes;
					anioOut=anio;
				}

				maquinaTemp=Maquina(0,0,"");
				bool bandera=false;
				do{
					maquinaTemp.showMaquinas();
					cout<<"Introduce un id de maquina: "<<endl;
					cin>>idMaquina;
					maquinaTemp=Maquina(idMaquina,0,"");
					if(!maquinaTemp.validarMaquina()) bandera=true;

				}while(!bandera);
				
				id=rand()%1000000;

				fechaout=to_string(diaOut)+"/"+to_string(mesOut)+"/"+to_string(anioOut);
				reservaTemp=Reserva(id,usuario.getDni(),idMaquina,maxdias,fechain,fechaout);

				//Compruebo que la reserva es correcta
				if(reservaTemp.addReserva()){
					reserva=reservaTemp;
					cout<<"Reserva realizada correctamente"<<endl;
				}else{
					cout<<"No se ha podido reservar"<<endl;
				}
				esUsuario=true;
				break;
			}
			case 2:{ //Cancelar reserva 
				cout<<"Introduce tu id de reserva: "<<endl;
				cin>>id;
				reserva=Reserva(id,usuario.getDni(),0,0,"","");
				if(reserva.deleteReserva()){
					cout<<"Reserva cancelada correctamente"<<endl;
				}else{
					cout<<"No se ha podido cancelar la reserva"<<endl;
				}
				esUsuario=true;
				break;
			}
			case 3:{ //Ver reservas
				cout<<"Tus reservas: "<<endl;
				reserva.showReservas(usuario.getDni());
				esUsuario=true;
				break;
			}
			case 4: //Cerrar sesion
				return 0;
		}
	}while(esUsuario);

	
	return 0;

}
