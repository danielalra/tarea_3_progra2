#include "procesadorArchivoTxt.h"
#include <sstream>

ProcesadorArchivoTxt::ProcesadorArchivoTxt(string nombre){
    
    archivoEntradaTxt.open(nombre, ifstream::in);

    if (!archivoEntradaTxt.is_open())
    {
        throw "no se puede abrir el archivo";
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

            id =0;
            nombre = "";
            apellido = "";
            correo = "";

            stream >> id >> nombre >> apellido >> correo;

            Persona persona {id, nombre, apellido, correo};
            escritorPersona.EscribirPersona(persona);
            
        }
        catch (string &excepcion)
        {
            cerr << excepcion << endl;
        }
    }
    escritorPersona.Cerrar();
    this->Cerrar();
}

void ProcesadorArchivoTxt::Cerrar(){
    
    archivoEntradaTxt.close();
}