# Renombre
Una aplicación para transformar los nombres de los archivos de un directorio.

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

## Tecnologías
- Qt 5.5
- C++11

Se puede compilar en cualquier plataforma que soporte Qt.
