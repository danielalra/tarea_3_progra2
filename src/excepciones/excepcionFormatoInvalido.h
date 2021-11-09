#ifndef EXCEPCIONFORMATOINVALIDO_H
#define EXCEPCIONFORMATOINVALIDO_H

#include <exception>

class ExcepcionFormatoInvalido : public std::exception
{
    public:
    ExcepcionFormatoInvalido() noexcept = default;
    ~ExcepcionFormatoInvalido() = default;

    virtual const char* what() const noexcept {
        return "El formato del archivo es invalido";
    }

};

#endif