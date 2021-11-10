#include "procesadorArchivoTxt.h"
#include "./excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "./excepciones/excepcionFormatoInvalido.h"

#include <sstream>
#include <iostream>

ProcesadorArchivoTxt::ProcesadorArchivoTxt(string nombre){

    archivoEntradaTxt.open(nombre, ifstream::in);

    if (!archivoEntradaTxt.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo();
    }
    
}

void ProcesadorArchivoTxt::CrearArchivoPersonas(string nombreArchivoGenerado){

    EscritorPersona escritorPersona {nombreArchivoGenerado};
    
    string linea {""};
    int id {0};
    string nombre {""};
    string apellido {""};
    string correo {""};


    while (std::getline(archivoEntradaTxt, linea)) {

    try
    {
        istringstream stream(linea);

        id = 0;
        nombre = "";
        apellido = "";
        correo = "";

        stream >> id >> nombre >> apellido >> correo;


        string idString = to_string(id);


        if (id==0)
        {
            ExcepcionFormatoInvalido e;
            throw e;
        }

        Persona persona {id, nombre, apellido, correo};
        escritorPersona.EscribirPersona(persona);

    }

    catch(ExcepcionFormatoInvalido e){

        throw e;
    }
        
            
    }
    escritorPersona.Cerrar();
    this->Cerrar();
}

void ProcesadorArchivoTxt::Cerrar(){
    
    archivoEntradaTxt.close();
}