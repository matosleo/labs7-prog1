#ifndef ENTRADAINVALIDA_H
#define ENTRADAINVALIDA_H

#include <stdexcept>
using std::invalid_argument;

class EntradaInvalida: public invalid_argument
{
public:
	EntradaInvalida() : invalid_argument("Entrada Inválida"){}
};

#endif