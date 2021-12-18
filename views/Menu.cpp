#include "Menu.h";

Menu::Menu(int opcion,string titulo,vector<string> opciones){
    this->opcion=opcion;
    this->titulo=titulo;
    this->opciones=opciones;
}
void Menu::mostrar(){
    do{
        for(int i=0;i<this->opciones.size();i++){
            cout<<i+1<<". "<<this->opciones[i]<<endl;
        }
        cin>>this->opcion;
    }while(this->opcion<1 || this->opcion>this->opciones.size());
}
