#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QStringList>
#include <QtGlobal>

#include "error.h"
#include "messagehelper.h"

int main(int argc, char *argv[])
{
    QString path;
    QDir folder;
    QFile *file;
    QFileInfo fileInfo;
    QStringList filenames;

    if(argc < 2)
    {
        MessageHelper::Error("Missing argument. Format: ./renombre [PATH]");
        return Errors::NO_PARAM;
    }

    path = QString(argv[1]);
    folder = QDir(path);

    if(!folder.exists())
    {
        MessageHelper::Error("This folder does not exist.");
        return Errors::NO_EXISTS;
    }

    if(!folder.isReadable())
    {
        MessageHelper::Error("This folder is not readable.");
        return Errors::NOT_READABLE;
    }

    if(folder.isRelative())
    {
        folder.makeAbsolute();
    }

    MessageHelper::Info("Initializing renaming process on folder " + folder.absolutePath().toStdString());

    filenames = QStringList(folder.entryList(QStringList() << "*.*", QDir::Files, QDir::Name));

    if(filenames.empty())
    {
        MessageHelper::Error("This folder is empty.");
        return Errors::EMPTY;
    }


    foreach(QString filename, filenames)
    {
        file = new QFile(folder.absolutePath() + "/" + filename);
        fileInfo = QFileInfo(file->fileName());

        if((folder.absolutePath() + "/" + filename) == file->fileName().toLower())
        {
            MessageHelper::Warning("File named " + fileInfo.fileName().toStdString() + " already has lowercase name format.");
            delete file;
            continue;
        }

        if(!file->rename(folder.absolutePath() + "/" + filename.toLower()))
        {
            MessageHelper::Warning("File named " + fileInfo.fileName().toStdString()  + " could not be renamed.");
            delete file;
            continue;
        }

        MessageHelper::Success(fileInfo.fileName().toStdString()  + " was sucessfully renamed to " + filename.toLower().toStdString());
        delete file;
    }

    return 0;
}
