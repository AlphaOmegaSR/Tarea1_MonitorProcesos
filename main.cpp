
#include <iostream>
#include <vector>
#include <string>
#include "Procesos.h"
#include "Analisis.h"
#include "Registro.h"

int main() {
    try {
        int modo;
        std::string archivo;
        int n;

        std::cout << "Modo de analisis (1 = basico, 2 = estricto): ";
        std::cin >> modo;
        if (modo < 1 || modo > 2)
            throw std::invalid_argument("Modo invalido.");

        std::cout << "Archivo de salida: ";
        std::cin >> archivo;

        std::cout << "Cantidad de procesos sospechosos definidos por el usuario: ";
        std::cin >> n;

        std::vector<std::string> listaUsuario;
        for (int i = 0; i < n; i++) {
            std::string nombre;
            std::cout << "Nombre proceso sospechoso #" << i + 1 << ": ";
            std::cin >> nombre;
            listaUsuario.push_back(nombre);
        }

        auto* procesos = obtenerProcesos();
        analizarProcesos(procesos, modo, listaUsuario);
        registrar(*procesos, archivo);

        std::cout << "\nProcesos activos:\n";
        for (const auto& p : *procesos) {
            std::cout << "PID: " << p.pid
                      << " | " << p.nombre
                      << " | Memoria(KB): " << p.memoriaKB;
            if (p.sospechoso)
                std::cout << "  <-- SOSPECHOSO";
            std::cout << "\n";
        }
        delete procesos;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
