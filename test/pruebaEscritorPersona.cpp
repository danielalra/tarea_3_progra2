#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/escritorPersona.h"
#include "../src/lectorPersona.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"

using namespace std;

namespace {
    TEST(EscritorTest, Prueba_GetLibro){

        int idPersona {1};
        string nombre = "Nombre";
        string apellido = "Apellido";
        string correo = "Correo";

        Persona personaPrueba {1, "Nombre", "Apellido", "Correo"};

        EXPECT_EQ(personaPrueba.getId(), idPersona);
        EXPECT_EQ(personaPrueba.getNombre(), nombre);
        EXPECT_EQ(personaPrueba.getApellido(), apellido);
        EXPECT_EQ(personaPrueba.getCorreo(), correo);

    }
   

    TEST(EscritorTest, Prueba_EscribirPersona) {
        
        Persona personaPrueba1 {1, "Nombre", "Apellido", "Correo"};

        EscritorPersona escritor {"pruebaEscribirPersona.dat"};
        escritor.EscribirPersona(personaPrueba1);
        escritor.Cerrar();

        LectorPersona lector {"pruebaEscribirPersona.dat"};
        Persona personaLeida = lector.ObtenerPersona(0);
        lector.Cerrar();

        EXPECT_EQ(personaLeida.getId(), personaPrueba1.getId());
        EXPECT_EQ(personaLeida.getNombre(), personaPrueba1.getNombre());
        EXPECT_EQ(personaLeida.getApellido(), personaPrueba1.getApellido());
        EXPECT_EQ(personaLeida.getCorreo(), personaPrueba1.getCorreo());
    }
}
