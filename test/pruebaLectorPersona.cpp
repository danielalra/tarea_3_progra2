#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/escritorPersona.h"
#include "../src/lectorPersona.h"
#include "../src/excepciones/excepcionPersonaNoExiste.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"

using namespace std;

namespace{

    TEST(LectorTest, Prueba_ExcepcionLecturaPersonaNoExiste1) {

        Persona personaPrueba1 {10, "Nombre", "Apellido", "Correo"};

        EXPECT_THROW({

            EscritorPersona escritor {"pruebaLeerPersona1.dat"};
            escritor.EscribirPersona(personaPrueba1);
            escritor.Cerrar();

            LectorPersona lector {"pruebaLeerPersona1.dat"};
            personaPrueba1 = lector.ObtenerPersona(80);
            lector.Cerrar();

        }, ExcepcionPersonaNoExiste);

    }

    TEST(LectorTest, Prueba_ExcepcionLecturaPersonaNoExiste2) {

        Persona personaPrueba2 {10, "Nombre", "Apellido", "Correo"};

        EXPECT_THROW({

            EscritorPersona escritor {"pruebaLeerPersona2.dat"};
            escritor.EscribirPersona(personaPrueba2);
            escritor.Cerrar();

            LectorPersona lector {"pruebaLeerPersona2.dat"};
            personaPrueba2 = lector.ObtenerPersona(9);
            lector.Cerrar();

        }, ExcepcionPersonaNoExiste);

    }

    TEST(LectorTest, Prueba_ExcepcionFormatoInvalido) {


        EXPECT_THROW({

            LectorPersona lector {"pruebaFormatoInvalido.txt"};
            Persona personaPrueba = lector.ObtenerPersona(10);
            lector.Cerrar();

        }, ExcepcionPersonaNoExiste);

    }
}