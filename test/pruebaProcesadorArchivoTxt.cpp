#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/procesadorArchivoTxt.h"
#include "../src/lectorPersona.h"
#include "../src/excepciones/excepcionFormatoInvalido.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"

using namespace std;

namespace {
    //Error al abrir archivo 
    TEST(ProcesadorTest, Prueba_ExcepcionNoSePuedeAbrirArchivo){


        EXPECT_THROW({

            ProcesadorArchivoTxt procesadorPrueba {"ArchivoNoExistente.txt"};

        }, ExcepcionNoSePuedeAbrirArchivo);

    }

    //Archivo con formato no esperado
   TEST(ProcesadorTest, Prueba_ExcepcionFormatoArchivoTxt){


        EXPECT_THROW({

            ProcesadorArchivoTxt procesadorPrueba {"pruebaFormatoInvalido.txt"};
            procesadorPrueba.CrearArchivoPersonas("pruebaFormatoInvalidoTxt.dat");
            procesadorPrueba.Cerrar();

        }, ExcepcionFormatoInvalido);

    }

    TEST(ProcesadorTest, Prueba_CreacionArchivoPersonas){

        ProcesadorArchivoTxt procesadorPrueba {"personasPrueba.txt"};
        procesadorPrueba.CrearArchivoPersonas("personasPrueba.dat");
        procesadorPrueba.Cerrar();

        LectorPersona lectorPrueba {"personasPrueba.dat"};
        Persona personaPrueba = lectorPrueba.ObtenerPersona(1);
        lectorPrueba.Cerrar();

        EXPECT_EQ(personaPrueba.getId(), 2);
        EXPECT_EQ(personaPrueba.getNombre(), "Nombre2");
        EXPECT_EQ(personaPrueba.getApellido(), "Apellido2");
        EXPECT_EQ(personaPrueba.getCorreo(), "Correo2");
    }

}