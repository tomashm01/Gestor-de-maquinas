/*
 * Usuario.h
 *
 *  Created on: 22 nov. 2021
 *      Author: tomas
 */

#ifndef ENTITIES_USUARIO_H_
#define ENTITIES_USUARIO_H_
#include <list>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Usuario {
private:
	string dni;
	string password;
	string nickname;
	string nombreCompleto;
	string rol;
	static std::list<Usuario> listaUsuarios;
public:
	Usuario(string dni, string password, string nickname, string nombreCompleto,
			string rol);

	string getDni();
	string getPassword();
	string getNickname();
	string getNombre();
	string getRol();
	string toString();

	void setDni(string dni);
	void setPassword(string password);
	void setNickname(string nickname);
	void setNombre(string nombreCompleto);
	void setRol(string rol);

	bool validarUsuario();
	bool addUsuario(Usuario user);
	bool deleteUsuario(Usuario user);
	Usuario showUserByDNI(string dni);
	bool changeUserByDNI(string dni,Usuario user);

};

#endif /* ENTITIES_USUARIO_H_ */
