# Renombre
[![Build Status](https://travis-ci.org/marcoshuck/renombre.svg?branch=master)](https://travis-ci.org/marcoshuck/renombre) ![Version](https://img.shields.io/badge/version-1.0.0-blue.svg) ![C++](https://img.shields.io/badge/c++-11-orange.svg) ![Qt](https://img.shields.io/badge/qt-5.10.1-green.svg) 

## Objetivo
Si tengo un directorio en el que quiero modificar varios archivos con el formato de nombre UnArchivoDeEjemplo.alg.o, la aplicación te los deja con el formato unarchivodeejemplo.alg.o

## Uso
```
./renombre [PATH]
```
**PATH:** Puede ser absoluto o relativo, técnicamente funciona en ambos.

## Compilación
Este proyecto fue compilado con MinGW para 32 bits. Para ver como realizar la compilación, dirigirse a la documentación de Qt.

**IMPORTANTE:** Una vez compilado, utilizar las librerías en la carpeta /lib y ponerlas en la misma ubicación que el ejecutable generado para que funcione.
