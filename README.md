
[README.md](https://github.com/user-attachments/files/25246718/README.md)

***INFORMACIÓN IMPORTANTE***

Desarrollado por: Sergio Pedro Sepúlveda Rodríguez
## Descripción
Programa modular que obtiene en tiempo real los procesos activos del sistema Windows, analiza posibles riesgos y genera un archivo de registro.

## Módulos
- Procesos.cpp / Procesos.h
  Obtiene los procesos activos usando la API de Windows.

- Analisis.cpp / Analisis.h
  Aplica criterios de riesgo (modo básico o estricto).

- Registro.cpp / Registro.h
  Genera archivo de texto con el análisis.

## Requisitos
- Sistema Windows
- Compilador compatible con Windows API (MinGW o MSVC)

## Instrucciones de compilación (MinGW)
g++ main.cpp Procesos.cpp Analisis.cpp Registro.cpp -o monitor.exe

## Uso
1. Seleccionar modo de análisis
2. Indicar nombre del archivo
3. (Opcional) Agregar procesos sospechosos
4. El sistema muestra resultados y genera archivo

## Criterios de análisis
Modo básico:
- Uso de memoria mayor a 500000 KB

Modo estricto:
- Uso mayor a 200000 KB
- Nombre inusual
- Coincidencia con lista del usuario 

## Enfoque técnico elegido para obtener procesos
Se utilizó la API de Windows "CreateToolhelp32Snapshot()" para capturar un snapshot del estado actual del sistema.


