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


    int id = personaLeida.getId();
    string nombre = personaLeida.getNombre();
    string apellido = personaLeida.getApellido();
    string correo = personaLeida.getCorreo();

    //si el archivo de entrada es de otro tipo y los datos ingresados en personaLeida son incorrectos
    //los el id o los .length() son 0 en caso de no ingresar datos o 1 al ingresar dato que no respeta al formato
    //por ejemplo leer un .zip donde las primeras posiciones contienen informacion que no son string, char, etc ahi se guardan en la variable (nombre, apellido o correo) como un string de length() = 1;
    if((id == 0) || (nombre.length() < 2) || (apellido.length() < 2) || (correo.length() < 2)){

        throw ExcepcionFormatoInvalido();
    }
    

    return personaLeida;
}

void LectorPersona::Cerrar(){
    archivoEntrada.close();
}