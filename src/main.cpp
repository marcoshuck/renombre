#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QtGlobal>

#include "error.h"
#include "messagehelper.h"

int main(int argc, char *argv[])
{
    QString *path;
    QDir *folder;
    QFile *file;
    QStringList *filenames;
    if(argc < 2)
    {
        MessageHelper::Error("Missing argument");
        return Errors::NO_PARAM;
    }

    path = new QString(argv[1]);
    folder = new QDir(*path);

    if(!folder->exists())
    {
        MessageHelper::Error("This folder does not exist.");
        return Errors::NO_EXISTS;
    }

    if(folder->isEmpty())
    {
        MessageHelper::Error("This folder is empty.");
        return Errors::EMPTY;
    }

    if(!folder->isReadable())
    {
        MessageHelper::Error("This folder is not readable.");
        return Errors::NOT_READABLE;
    }

    if(folder->isRelative())
    {
        folder->makeAbsolute();
    }

    filenames = new QStringList(folder->entryList(QStringList() << "*.*", QDir::Files, QDir::Name));

    foreach(QString filename, *filenames)
    {
        file = new QFile(folder->absolutePath() + "/" + filename);
        if(!file->rename(folder->absolutePath() + "/" + filename.toLower()))
        {
            MessageHelper::Warning("File named " + file->fileName().toStdString() + " could not be renamed.");
            continue;
        }
        MessageHelper::Success(filename.toStdString() + " was sucessfully renamed to " + filename.toLower().toStdString());
    }
    return 0;
}
