#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/procesadorArchivoTxt.h"
#include "../src/excepciones/excepcionFormatoInvalido.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"

using namespace std;

namespace {
    //Error al abrir archivo 
    TEST(ProcesadorTest, Prueba_ExcepcionNoSePuedeAbrirArchivo){


        EXPECT_THROW({

            ProcesadorArchivoTxt procesadorPrueba {"ArchivoNoExistente.txt"};

        }, ExcepcionNoSePuedeAbrirArchivo*);

    }

    //Archivo con formato no esperado
   TEST(ProcesadorTest, Prueba_ExcepcionProcesadorArchivoTxt){


        EXPECT_THROW({

            ProcesadorArchivoTxt procesadorPrueba {"prueba.txt"};
            procesadorPrueba.CrearArchivoPersonas("personasPruebaProcesador.dat");
            procesadorPrueba.Cerrar();

        }, ExcepcionFormatoInvalido*);

    }

}