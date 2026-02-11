// Analisis.h
#ifndef ANALISIS_H
#define ANALISIS_H

#include "Procesos.h"
#include <vector>

void analizarProcesos(std::vector<Proceso>* procesos,
                      int modo,
                      const std::vector<std::string>& sospechososUsuario);

#endif
