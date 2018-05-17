#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QtGlobal>

#include "errores.h"

#define DEBUG false

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString *rutaDirectorio;
    QDir *directorio;
    QFile *archivo;
    QStringList *listaArchivos;

    if(argc < 2)
    {
        return ERR_NO_PARAM;
    }

    rutaDirectorio = new QString(argv[1]);
    directorio = new QDir(*rutaDirectorio);

    if(!directorio->exists())
    {
        return ERR_NO_EXISTS;
    }

    if(directorio->isEmpty())
    {
        return ERR_EMPTY;
    }

    if(directorio->isReadable())
    {
        return ERR_NO_WRITABLE;
    }

    if(directorio->isRelative())
    {
        directorio->makeAbsolute();
    }

    listaArchivos = new QStringList(directorio->entryList(QStringList() << "*.*", QDir::Files, QDir::Name));

    foreach(QString nombreArchivo, *listaArchivos)
    {
        archivo = new QFile(directorio->absolutePath() + nombreArchivo);
        if(!archivo->rename(nombreArchivo, nombreArchivo.toLower()))
        {
            break;
        }

    }

    return app.exec();
}
