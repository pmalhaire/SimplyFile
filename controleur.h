#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QStringList>
#include <QDir>

namespace Controleur
{
    //returnlist of files in the path
    QString dir(QString i_rootPath, QString  i_path);
    //list files in a dir (excluding dirs)
    QStringList *  listFiles(QString i_dir);
    //list dir in a dir (excluding files) 2 entries file and ext
    QStringList *  listDirs(QString i_dir);
}

#endif // CONTROLEUR_H
