# GESTOR DE MAQUINAS

  App creada en Ingenieria del software para gestionar las máquinas de reserva. 

  Esta aplicación ha sido realizad en 2º de Ingeniería Informática, donde usamos C++ para implementarlo y CUTE para el Testing.

## Datos a tener en cuenta en la ejecución de la aplicación:
Hay que dejar un espacio vacío al final de los ficheros, si no se deja la app inserta los datos en la ultima linea:

- usuarios.txt
- reservas.txt
- maquinas.txt

## Compilación del proyecto
``` 
g++ -std=c++11 -o ejecutable view.cpp ../Entities/Maquina.cpp  ../Entities/Usuario.cpp ../Entities/Reserva.cpp Menu.cpp
```

## Ejecución

Dirigirse a la carpeta /views del proyecto y ejecutar:
```
./ejecutable
```