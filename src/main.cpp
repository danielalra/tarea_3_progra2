#include <iostream>
#include "procesadorArchivoTxt.h"

int main (){
    
    ProcesadorArchivoTxt procesador {"personas.txt"};
    procesador.CrearArchivoPersonas("personas.dat");
    
    return 0;
}