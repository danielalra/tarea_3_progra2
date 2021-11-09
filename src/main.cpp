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
    Persona persona1 = lector.ObtenerPersona(80);
    lector.Cerrar();

    cout << "Persona: " << persona1.getId() << " " << persona1.getNombre() << " " << persona1.getApellido() << " " << persona1.getCorreo() << endl;

    return 0;
}

#endif