#include "lectorPersona.h"

LectorPersona::LectorPersona(string nombreArchivoEntrada){

    archivoEntrada.open(nombreArchivoEntrada, ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw "No se puede abrir el archivo";
    }
}

Persona LectorPersona::ObtenerPersona(int idPersona){

    Persona personaLeida;

    long posicionPersona = sizeof(Persona) * (idPersona-10);

    archivoEntrada.seekg(0, ios::end);
    long fileSize = archivoEntrada.tellg();


    if (posicionPersona > fileSize ||posicionPersona<0)
    {
        throw "La persona no existe";
    }

    archivoEntrada.seekg(posicionPersona);
    archivoEntrada.read((char *) &personaLeida, sizeof(Persona));

    return personaLeida;

}

void LectorPersona::Cerrar(){
    archivoEntrada.close();
}