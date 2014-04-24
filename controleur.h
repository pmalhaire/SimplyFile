#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QStringList>
#include <QDir>

namespace Controleur
{
    //returnlist of files in the path
    QString dir(QString irootPath, QString  ipath);
    //list files in a dir (excluding dirs)
    QStringList *  listFiles(QString sDir);
    //list dir in a dir (excluding files) 2 entries file and ext
    QStringList *  listDirs(QString sDir);
}

#endif // CONTROLEUR_H
