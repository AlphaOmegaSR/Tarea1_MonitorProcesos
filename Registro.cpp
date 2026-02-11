
#include "Registro.h"
#include <fstream>
#include <ctime>
#include <stdexcept>

void registrar(const std::vector<Proceso>& procesos,
               const std::string& archivo) {

    std::ofstream out(archivo);
    if (!out)
        throw std::runtime_error("No se pudo abrir el archivo.");

    time_t now = time(nullptr);

    out << "Fecha y hora: " << ctime(&now);
    out << "Total de procesos: " << procesos.size() << "\n\n";

    out << "=== LISTA COMPLETA ===\n";
    for (const auto& p : procesos) {
        out << "PID: " << p.pid
            << " | Nombre: " << p.nombre
            << " | Memoria(KB): " << p.memoriaKB << "\n";
    }

    out << "\n=== PROCESOS SOSPECHOSOS ===\n";
    for (const auto& p : procesos) {
        if (p.sospechoso) {
            out << "PID: " << p.pid
                << " | " << p.nombre
                << " | Riesgo: " << p.nivelRiesgo
                << " | Razon: " << p.razon << "\n";
        }
    }

    out.close();
}
