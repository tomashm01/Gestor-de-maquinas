#include "../Entities/Maquina.h"
#include "../Entities/Reserva.h"
#include "../Entities/Usuario.h"
#include "Menu.h"

int main(void){

	Menu principal=Menu(0,"Menu Principal",{"Iniciar Sesion","Registrarse","Salir"});
	Menu menuUsuario=Menu(0,"Menu Usuario",{"Reservar","Cancelar reserva","Ver Reservas","Salir"});
	Menu menuMaquina=Menu(0,"Menu Maquina",{"Añadir reserva","Cancelar reserva","Ver Reservas","Salir"});
	Menu menuAdmin=Menu(0,"Menu Administrador",{"Añadir usuario","Eliminar usuario","Ver usuarios","Recuperar contraseña de un usuario","Salir"});

	bool salirApp=false,esUsuario=false,esAdminMaquina=false,esAdminUsuarios=false;
	string nombre,nickname,password,dni,rol;
	Usuario usuario=Usuario("","","","","");
	Usuario temporal=Usuario("","","","","");

	do{ //Menu principal
		principal.mostrar();
		switch(principal.getOpcion()){
			case 1: //Inicio sesion
				cout<<"Introduce tu dni: "<<endl;
				cin>>dni;
				cout<<"Introduce tu password: "<<endl;
				cin>>password;
				
				temporal=Usuario(dni,password,"","","");
				usuario=temporal.showUserByDNI(dni);

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
				
				break;
			case 2: //Registrarse

				cout<<"Introduce tu nombre: "<<endl;
				cin>>nombre;
				cout<<"Introduce tu nickname: "<<endl;
				cin>>nickname;
				do{ //Minimo 8 digitos
					cout<<"Introduce tu password: "<<endl;
					cin>>password;
				}while(password.length()<8);
				cout<<"Introduce tu dni: "<<endl;
				cin>>dni;
				rol="usuario";

				usuario=Usuario(dni,password,nickname,nombre,rol);

				if(usuario.addUsuario()){
					cout<<"Usuario registrado correctamente"<<endl;
					salirApp=true;
				}else{
					cout<<"Error al registrar usuario"<<endl;
				}
				
				break;
			case 3: //Cerrar app
				return 0;
		}
	}while(!salirApp);

	do{ //Menu usuario
		if(esUsuario){
			menuUsuario.mostrar();
		}
	}while(esUsuario);

	do{ //Menu admin de usuarios
		if(esAdminUsuarios){
			menuAdmin.mostrar();
		}
	}while(esAdminUsuarios);

	do{ //Menu admin de maquinas
		if(esAdminMaquina){
			menuMaquina.mostrar();
		}
	}while(esAdminMaquina);
	
	
	return 0;

}
