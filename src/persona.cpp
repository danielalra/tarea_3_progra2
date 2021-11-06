#include "persona.h"
#include <string>
#include <cstring>

using namespace std;

Persona::Persona(int id, string nombre, string apellido, string correo){
    
    this->id = id;

    strcpy(this->nombre, nombre.c_str());
    strcpy(this->apellido, apellido.c_str());
    strcpy(this->correo, correo.c_str());
}

Persona::Persona(){
    this->id = 0;

    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}

int Persona::getId(){
    return this->id;
}

string Persona::getNombre(){
    return string{this->nombre};
}

string Persona::getApellido(){
        return string{this->apellido};
}

string Persona::getCorreo(){
    return string{this->correo};
}