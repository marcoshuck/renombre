#ifndef ERRORES_H
#define ERRORES_H

enum errores : unsigned int {
    ERR_NO_PARAM=1,
    ERR_NO_EXISTS,
    ERR_EMPTY,
    ERR_NO_WRITABLE
};

#define ERR_MSG_NO_PARAM "No se ha definido ningún directorio"
#define ERR_MSG_NO_EXISTS "El directorio especificado no existe"
#define ERR_MSG_EMPTY "El directorio especificado se encuentra vacío"
#define ERR_MSG_NO_WRITABLE "El directorio no se puede escribir"
#define WNG_MSG_RELATIVE_PATH "La ruta del directorio estaba expresada en formato relativo, y se convirtió al formato absoluto."
#define WNG_MSG_CANT_RENAME "No se pudo renombrar el archivo"

#endif // ERRORES_H
