#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/escritorPersona.h"
#include "../src/lectorPersona.h"
#include "../src/excepciones/excepcionPersonaNoExiste.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "../src/excepciones/excepcionFormatoInvalido.h"

using namespace std;

namespace{

    //leer una persona en una psocion negativa
    TEST(LectorTest, Prueba_ExcepcionLeerPersonaNoExiste1) {

        Persona personaPrueba {1, "Nombre", "Apellido", "Correo"};
        EscritorPersona escritor {"pruebaLeerPersona.dat"};
        escritor.EscribirPersona(personaPrueba);
        escritor.Cerrar();

        EXPECT_THROW({

            LectorPersona lector {"pruebaLeerPersona.dat"};
            Persona personaPruebaActual = lector.ObtenerPersona(-1);
            lector.Cerrar();

        }, ExcepcionPersonaNoExiste);

    }

    //leer a la persona en la poscion siguiente vacia (hay n personas, lea la n+1. En este caso el fileSize = n+1)
    TEST(LectorTest, Prueba_ExcepcionLeerPersonaNoExiste2) {


        EXPECT_THROW({

            LectorPersona lector {"pruebaLeerPersona.dat"};
            Persona personaPruebaActual = lector.ObtenerPersona(1);
            lector.Cerrar();


        }, ExcepcionPersonaNoExiste);

    }

    //leer una persona que no existe, poscion mayor que el fileSize
    TEST(LectorTest, Prueba_ExcepcionLeerPersonaNoExiste3) {

        EXPECT_THROW({

            LectorPersona lector {"pruebaLeerPersona.dat"};
            Persona personaPruebaActual = lector.ObtenerPersona(2);
            lector.Cerrar();
            

        }, ExcepcionPersonaNoExiste);

    }

    TEST(LectorTest, Prueba_ExcepcionFormatoInvalido) {


        EXPECT_THROW({

            LectorPersona lector {"archivoFormatoInvalido.zip"};
            Persona personaPrueba = lector.ObtenerPersona(0);
            lector.Cerrar();

        }, ExcepcionFormatoInvalido);

    }
}