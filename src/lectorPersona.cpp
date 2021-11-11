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

Persona LectorPersona::ObtenerPersona(int posicion){

    Persona personaLeida;

    long posicionPersona = sizeof(Persona) * (posicion);

    archivoEntrada.seekg(0, ios::end);
    long fileSize = archivoEntrada.tellg();

    //si la persona ingresada no existe
    if (posicionPersona > fileSize || posicionPersona == fileSize || posicionPersona < 0)
    {
        throw ExcepcionPersonaNoExiste();
    }

    
    archivoEntrada.seekg(posicionPersona);
    archivoEntrada.read((char *) &personaLeida, sizeof(Persona));

    //si el archivo de entrada es de otro tipo y los datos ingresados en personaLeida son incorrectos
    //si dicha personaLeida posee id=0 entonces no contiene datos que se leyeron de una persona en binario
    if(personaLeida.getId() == 0 && personaLeida.getNombre() == "" && personaLeida.getApellido() == "" && personaLeida.getCorreo() == ""){

        throw ExcepcionFormatoInvalido();
    }
    

    return personaLeida;
}

void LectorPersona::Cerrar(){
    archivoEntrada.close();
}