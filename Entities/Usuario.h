/*
 * Usuario.h
 *
 *  Created on: 22 nov. 2021
 *      Author: tomas
 */

#ifndef ENTITIES_USUARIO_H_
#define ENTITIES_USUARIO_H_
#include <list>
using namespace std;

class Usuario {
private:
	char *dni;
	char *password;
	char *nickname;
	char *nombreCompleto;
	char *rol;
	static std::list<Usuario> listaUsuarios;
public:
	Usuario(char *dni, char *password, char *nickname, char *nombreCompleto,
			char *rol);

	char* getDni();
	char* getPassword();
	char* getNickname();
	char* getNombre();
	char* getRol();
	char* toString();

	void setDni(char* dni);
	void setPassword(char* password);
	void setNickname(char* nickname);
	void setNombre(char* nombreCompleto);
	void setRol(char* rol);

	bool validarUsuario();
	bool addUsuario(Usuario user);
	bool deleteUsuario(Usuario user);
	Usuario showUserByDNI(char* dni);
	bool changeUserByDNI(char* dni,Usuario user);

};

#endif /* ENTITIES_USUARIO_H_ */
