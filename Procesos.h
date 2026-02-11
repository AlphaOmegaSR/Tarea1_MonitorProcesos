
#ifndef PROCESOS_H
#define PROCESOS_H

#include <string>
#include <vector>

struct Proceso {
    int pid;
    std::string nombre;
    size_t memoriaKB;
    bool sospechoso;
    std::string razon;
    int nivelRiesgo;
};

std::vector<Proceso>* obtenerProcesos();

#endif
