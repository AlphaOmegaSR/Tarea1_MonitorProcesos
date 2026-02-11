
#include "Procesos.h"
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <stdexcept>

std::vector<Proceso>* obtenerProcesos() {
    auto* lista = new std::vector<Proceso>();

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        throw std::runtime_error("No se pudo obtener snapshot de procesos.");

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snapshot, &pe)) {
        CloseHandle(snapshot);
        throw std::runtime_error("Error al recorrer procesos.");
    }

    do {
        Proceso p;
        p.pid = pe.th32ProcessID;
        p.nombre = pe.szExeFile;
        p.memoriaKB = 0;
        p.sospechoso = false;
        p.nivelRiesgo = 0;

        HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, p.pid);
        if (hProc) {
            PROCESS_MEMORY_COUNTERS pmc;
            if (GetProcessMemoryInfo(hProc, &pmc, sizeof(pmc)))
                p.memoriaKB = pmc.WorkingSetSize / 1024;
            CloseHandle(hProc);
        }

        lista->push_back(p);

    } while (Process32Next(snapshot, &pe));

    CloseHandle(snapshot);
    return lista;
}
