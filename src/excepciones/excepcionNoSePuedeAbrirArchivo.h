#ifndef EXCEPCIONNOSEPUEDEABRIRARCHIVO_H
#define EXCEPCIONNOSEPUEDEABRIRARCHIVO_H

#include <exception>

class ExcepcionNoSePuedeAbrirArchivo : public std::exception
{
    public:
    ExcepcionNoSePuedeAbrirArchivo() noexcept = default;
    ~ExcepcionNoSePuedeAbrirArchivo() = default;

    virtual const char* what() const noexcept {
        return "No se puede abrir el archivo.";
    }

};

#endif