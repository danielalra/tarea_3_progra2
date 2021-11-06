#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {

    int id;
    char nombre[15];
    char apellido[15];
    char correo[50];

    public:
    Persona(int id, string nombre, string apellido, string correo);  
    Persona();

    int getId();
    string getNombre();
    string getApellido();
    string getCorreo();
};

#endif