#ifndef LECTORPERSONA_H
#define LECTORPERSONA_H

#include <string>
#include <fstream>

#include "persona.h"

using namespace std;

class LectorPersona {

    ifstream archivoEntrada;

    public:
    LectorPersona(string nombreArchivo);

    Persona ObtenerPersona(int idPersona);
    void Cerrar();

};

#endif