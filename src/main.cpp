#ifndef UNIT_TEST

#include <iostream>
#include "procesadorArchivoTxt.h"
#include "persona.h"
#include "lectorPersona.h"

int main (){

    ProcesadorArchivoTxt procesador {"personas.txt"};
    procesador.CrearArchivoPersonas("personas.dat");
    procesador.Cerrar();

    LectorPersona lector {"personas.dat"};
    Persona persona1 = lector.ObtenerPersona(15);
    Persona persona2 = lector.ObtenerPersona(22);
    lector.Cerrar();

    cout << "Persona1: " << persona1.getId() << " " << persona1.getNombre() << " " << persona1.getApellido() << " " << persona1.getCorreo() << endl;
    cout << "Persona2: " << persona2.getId() << " " << persona2.getNombre() << " " << persona2.getApellido() << " " << persona2.getCorreo() << endl;
    return 0;
}

#endif