#include "lectorPersona.h"
#include "./excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "./excepciones/excepcionPersonaNoExiste.h"

LectorPersona::LectorPersona(string nombreArchivoEntrada){

    archivoEntrada.open(nombreArchivoEntrada, ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw new ExcepcionNoSePuedeAbrirArchivo();
    }
}

Persona LectorPersona::ObtenerPersona(int idPersona){

    Persona personaLeida;

    long posicionPersona = sizeof(Persona) * (idPersona-10);

    archivoEntrada.seekg(0, ios::end);
    long fileSize = archivoEntrada.tellg();


    if (posicionPersona > fileSize || posicionPersona < 0)
    {
        throw new ExcepcionPersonaNoExiste();
    }

    archivoEntrada.seekg(posicionPersona);
    archivoEntrada.read((char *) &personaLeida, sizeof(Persona));

    return personaLeida;

}

void LectorPersona::Cerrar(){
    archivoEntrada.close();
}