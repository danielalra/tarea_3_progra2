#ifndef ESCRITORPERSONA_H
#define ESCRITORPERSONA_H

#include <string>
#include <iostream>
#include <fstream>

#include "persona.h"

using namespace std;

class EscritorPersona {

    ofstream archivoSalida;

    public:
    EscritorPersona(string nombre);

    void EscribirPersona(Persona &persona);
    void Cerrar();
    //sfdsfs

};

#endif