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
    QFileInfo *fileInfo;
    QStringList *filenames;
    if(argc < 2)
    {
        MessageHelper::Error("Missing argument. Format: ./renombre [PATH]");
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

    MessageHelper::Info("Initializing renaming process on folder " + folder->absolutePath().toStdString());

    filenames = new QStringList(folder->entryList(QStringList() << "*.*", QDir::Files, QDir::Name));

    foreach(QString filename, *filenames)
    {
        file = new QFile(folder->absolutePath() + "/" + filename);
        fileInfo = new QFileInfo(file->fileName());

        if((folder->absolutePath() + "/" + filename) == file->fileName())
        {
            MessageHelper::Warning("File named " + fileInfo->fileName().toStdString() + " already has lowercase name format.");
            continue;
        }

        if(!file->rename(folder->absolutePath() + "/" + filename.toLower()))
        {
            MessageHelper::Warning("File named " + fileInfo->fileName().toStdString()  + " could not be renamed.");
            continue;
        }

        MessageHelper::Success(fileInfo->fileName().toStdString()  + " was sucessfully renamed to " + filename.toLower().toStdString());

        delete file;
        delete fileInfo;
    }

    delete path;
    delete folder;
    delete filenames;

    return 0;
}
