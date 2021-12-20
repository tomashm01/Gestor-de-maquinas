#include "test.h"
#include "cute.h"

void inicioSesionUsuario() {
	Usuario user=Usuario("31880317V", "12345678", "Juan", "Perez", "");

	ASSERT_EQUAL(false, user.validarUsuario()); //Existe usuario 
	ASSERT_EQUAL(true, user.validarUsuario()); //No existe usuario
}

void registrarUsuario(){
	Usuario user=Usuario("31880317V", "12345678", "Juan", "Perez", "");

	ASSERT_EQUAL(true, user.addUsuario()); //Usuario registrado correctamente
	ASSERT_EQUAL(false, user.addUsuario()); //Usuario ya existe
}

void realizarReserva(){
	Reserva reserva=Reserva(1,"31880317V",2,10,"15/10/2021","15/10/2021");

	ASSERT_EQUAL(true, reserva.addReserva()); //Reserva realizada correctamente
	ASSERT_EQUAL(false, reserva.addReserva()); //Reserva ya existe

}

void cancelarReserva(){
	Reserva reserva=Reserva(1,"31880317V",2,10,"15/10/2021","15/10/2021");

	ASSERT_EQUAL(true, reserva.deleteReserva()); //Reserva cancelada correctamente
	ASSERT_EQUAL(false, reserva.deleteReserva()); //Reserva no existe
}

void insertarMaquina(){
	Maquina maquina=Maquina(1,2,"Maquina de test");

	ASSERT_EQUAL(true, maquina.addMaquina()); //Maquina insertada correctamente
	ASSERT_EQUAL(false, maquina.addMaquina()); //Maquina ya existe

}

void eliminarMaquina(){
	Maquina maquina=Maquina(1,2,"Maquina de test");

	ASSERT_EQUAL(true, maquina.deleteMaquina()); //Maquina eliminada correctamente
	ASSERT_EQUAL(false, maquina.deleteMaquina()); //Maquina no existe
}

cute::suite make_suite_test() {
	cute::suite s { };
	s.push_back(CUTE(inicioSesionUsuario));
	s.push_back(CUTE(registrarUsuario));
	s.push_back(CUTE(realizarReserva));
	s.push_back(CUTE(cancelarReserva));
	s.push_back(CUTE(insertarMaquina));
	s.push_back(CUTE(eliminarMaquina));
	return s;
}
