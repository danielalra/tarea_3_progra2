#include "lectorPersona.h"
#include "./excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "./excepciones/excepcionPersonaNoExiste.h"
#include "./excepciones/excepcionFormatoInvalido.h"

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

    //si la persona ingresada no existe
    if (posicionPersona > fileSize || posicionPersona < 0)
    {
        throw ExcepcionPersonaNoExiste();
    }

    //si el archivo de entrada es de otro tipo
    archivoEntrada.seekg(posicionPersona);

    try
    {
        archivoEntrada.read((char *) &personaLeida, sizeof(Persona));
    }
    catch(ExcepcionFormatoInvalido e)
    {
        throw e;
    }
    

    return personaLeida;
}

void LectorPersona::Cerrar(){
    archivoEntrada.close();
}