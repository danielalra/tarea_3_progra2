#include "escritorPersona.h"

EscritorPersona::EscritorPersona(string nombre){

    archivoSalida.open(nombre, ios::out|ios::binary);

    if (!archivoSalida.is_open())
    {
        throw "no se puede abrir el archivo";
    }
}

void EscritorPersona::EscribirPersona(Persona &persona){

    archivoSalida.write((char *) &persona, sizeof(Persona));
}

void EscritorPersona::Cerrar(){
    
    archivoSalida.close();
}