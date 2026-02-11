
#include "Analisis.h"
#include <algorithm>

void analizarProcesos(std::vector<Proceso>* procesos,
                      int modo,
                      const std::vector<std::string>& sospechososUsuario) {

    for (auto& p : *procesos) {

        // Regla 1: nombre sospechoso definido por el usuario
        if (std::find(sospechososUsuario.begin(),
                      sospechososUsuario.end(),
                      p.nombre) != sospechososUsuario.end()) {
            p.sospechoso = true;
            p.razon = "Nombre en lista sospechosa del usuario";
            p.nivelRiesgo = 3;
        }

        // Regla 2: consumo alto de memoria (modo estricto)
        if (modo == 2 && p.memoriaKB > 200000) {
            p.sospechoso = true;
            p.razon = "Consumo elevado de memoria";
            p.nivelRiesgo = 4;
        }

        // Regla 3: nombres comunes usados por malware
        if (modo == 2 &&
            (p.nombre == "svchosts.exe" || p.nombre == "explorer_.exe" || p.nombre == "lsass.exe" )) {
            p.sospechoso = true;
            p.razon = "Nombre similar a proceso del sistema";
            p.nivelRiesgo = 5;
        }
    }
}
