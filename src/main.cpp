#include <iostream>
#include "procesadorArchivoTxt.h"
#include "persona.h"
#include "lectorPersona.h"

int main (){
    
    ProcesadorArchivoTxt procesador {"personas.txt"};
    procesador.CrearArchivoPersonas("personas.dat");

    LectorPersona lector {"personas.dat"};
    Persona persona1 = lector.ObtenerPersona(20);

    cout << "Persona: " << persona1.getId() << " " << persona1.getNombre() << " " << persona1.getApellido() << " " << persona1.getCorreo() << endl;

    return 0;
}