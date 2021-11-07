#ifndef PROCESADORARCHIVOTXT_H
#define PROCESADORARCHIVOTXT_H

#include <string>

#include "persona.h"
#include "escritorPersona.h"

//using namespace std;

class ProcesadorArchivoTxt {

  std::ifstream archivoEntradaTxt;

  public:
  ProcesadorArchivoTxt(string nombreArchivo);
  
  void CrearArchivoPersonas();
  void Cerrar();
};

#endif