
#ifndef REGISTRO_H
#define REGISTRO_H

#include "Procesos.h"
#include <vector>
#include <string>

void registrar(const std::vector<Proceso>& procesos,
               const std::string& archivo);

#endif
