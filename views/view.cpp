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
	Menu menuUsuario=Menu(0,"Menu Usuario",{"Reservar","Cancelar reserva","Ver Reservas","Recuperar contraseña","Salir"});
	Menu menuMaquina=Menu(0,"Menu Maquina",{"Añadir maquina","Eliminar maquina","Ver maquinas","Cambiar maquinas","Salir"});
	Menu menuAdmin=Menu(0,"Menu Administrador",{"Añadir usuario","Eliminar usuario","Ver usuarios","Modificar usuario","Salir"});

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
					if(usuario.getRol()=="adminMaquinas"){
						esAdminMaquina=true;	
					}else if(usuario.getRol()=="adminUsuarios"){
						esAdminUsuarios=true;
					}else{
						esUsuario=true;
					}
					salirApp=true;
				}
				cout<<usuario.getRol()<<endl;
				opcion=0;
				break;
			}
			case 2:{ //Registrarse
				cin.ignore();
				cout<<"Introduce tu nombre: "<<endl;
				getline(cin,nombre);
				cout<<"Introduce tu nickname: "<<endl;
				cin>>nickname;
				cin.ignore();
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

	if(esUsuario){
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
				case 4:{//Cambiar contraseña
					do{
						cout<<"Introduce tu nueva contraseña: "<<endl;
						cin>>password;	
					}while(password.length()<8);
					usuario.setPassword(password);
					if(usuario.changeUser()){
						cout<<"Contraseña cambiada correctamente"<<endl;
					}else{
						cout<<"No se ha podido cambiar la contraseña"<<endl;
					}
				}
				case 5: {//Cerrar sesion
					return 0;
				}
			}
		}while(esUsuario);
	}

	else if(esAdminUsuarios){
		do{
			menuAdmin.mostrar();
			cin>>opcion;
			menuAdmin.setOpcion(opcion);
			switch(menuAdmin.getOpcion()){
				case 1:{//Añadir usuario
					cin.ignore();
					cout<<"Introduce el nombre(sin espacios ni comas): "<<endl;
					getline(cin,nombre);

					cout<<"Introduce el nickname: "<<endl;
					cin>>nickname;

					do{
						cout<<"Introduce la password: "<<endl;
						cin>>password;
					}while(password.length()<8);
					
					do{
						cout<<"Introduce el dni: "<<endl;
						cin>>dni;
					}while(!verificaDNI(dni));

					do{
						cout<<"Introduce su rol: "<<endl;
						cin>>rol;
					}while(rol!="usuario" && rol!="adminUsuarios" && rol!="adminMaquinas");

					usuario=Usuario(dni,password,nickname,nombre,rol);

					if(usuario.addUsuario()){
						cout<<"Usuario registrado correctamente"<<endl;
						salirApp=true;
					}else{
						cout<<"Error al registrar usuario"<<endl;
					}
					break;
				}
				case 2:{ //Eliminar usuario
					usuario.showAllUsers();
					cout<<"Introduce el dni a eliminar: "<<endl;
					cin>>dni;
					usuario=Usuario(dni,"","","","");
					if(usuario.deleteUsuario()){
						cout<<"Usuario eliminado correctamente"<<endl;
					}else{
						cout<<"No se ha podido eliminar el usuario"<<endl;
					}
					break;
				}
				case 3:{//Ver usuarios
					usuario.showAllUsers();
					break;
				}
				case 4:{ //Cambiar datos usuario
					usuario.showAllUsers();
					cout<<"Introduce el dni del usuario a modificar: "<<endl;
					cin>>dni;
					cin.ignore();
					usuarioTemp=Usuario(dni,"","","","");

					cout<<"Introduce el nuevo nombre: "<<endl;
					getline(cin,nombre);
					cout<<"Introduce el nuevo nickname: "<<endl;
					cin>>nickname;

					cout<<"Introduce la nueva password: "<<endl;
					cin>>password;

					usuarioTemp.setNombre(nombre);
					usuarioTemp.setNickname(nickname);
					usuarioTemp.setPassword(password);

					if(usuarioTemp.changeUser()){
						cout<<"Usuario modificado correctamente"<<endl;
					}else{
						cout<<"No se ha podido modificar el usuario"<<endl;
					}
					break;
				}
				case 5:{//Salir
					return 0;
				}
			}
		}while(esAdminUsuarios);
	}else{
		do{
			menuMaquina.mostrar();
			cin>>opcion;
			menuMaquina.setOpcion(opcion);
			switch(menuMaquina.getOpcion()){

				case 1:{// Añadir maquina
					id=rand()%1000000;
					cout<<"Introduce los nucleos de la máquina: "<<endl;
					cin>>nucleos;
					cin.ignore();
					cout<<"Introduce una descripcion: "<<endl;
					getline(cin,descripcion);

					maquinaTemp=Maquina(id,nucleos,descripcion);
					if(maquinaTemp.addMaquina()){
						cout<<"Maquina registrada correctamente"<<endl;
						maquina=maquinaTemp;
					}else{
						cout<<"Error al registrar maquina"<<endl;
					}
					break;
				}
				case 2:{ //Eliminar maquina
					maquina.showMaquinas();
					cout<<"Introduce el id de la maquina a eliminar: "<<endl;
					cin>>id;
					maquina=Maquina(id,0,"");
					if(maquina.deleteMaquina()){
						cout<<"Maquina eliminada correctamente"<<endl;
					}else{
						cout<<"No se ha podido eliminar la maquina"<<endl;
					}
					break;
				}
				case 3:{//Ver maquinas
					maquina.showMaquinas();
					break;
				}
				case 4:{//Cambiar maquina
					maquina.showMaquinas();
					cout<<"Introduce el id de la maquina a modificar: "<<endl;
					cin>>id;

					maquinaTemp=Maquina(id,0,"");

					cout<<"Introduce los nuevos nucleos: "<<endl;
					cin>>nucleos;
					cin.ignore();
					cout<<"Introduce la nueva descripcion: "<<endl;
					getline(cin,descripcion);

					maquinaTemp.setNucleos(nucleos);
					maquinaTemp.setDescripcion(descripcion);

					if(maquinaTemp.changesMaquina()){
						cout<<"Maquina modificada correctamente"<<endl;
					}else{
						cout<<"No se ha podido modificar la maquina"<<endl;
					}
					break;
				}
				case 5: { //Salir
					return 0;
				}
			}


		}while(esAdminMaquina);
	}
	
	return 0;

}
