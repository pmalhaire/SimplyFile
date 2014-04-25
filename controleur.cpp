#include "controleur.h"
#include <QDir>
#include <QFileInfo>
#include <QDirIterator>
#include <QtCore>

QString Controleur::dir(QString irootPath, QString  ipath)
{
    QString sDir;

    if(ipath!=irootPath)sDir.append(irootPath);
    //dir.append(QDir::separator());
    sDir.append(ipath);
    QDir dDir(sDir);
    QString answer;
    answer.append("<ul class=\"jqueryFileTree\" style=\"display: none;\">");

    QStringList * aDirs = Controleur::listDirs(sDir);
    QStringListIterator dirIt(*aDirs);
    while (dirIt.hasNext()) {

        QString current = dirIt.next();
        answer.append(
                    "<li class=\"directory collapsed\">");
        answer.append("<a href=\"#\" rel=\"");
        answer.append(sDir.remove(irootPath));
        answer.append("/");
        answer.append(current);
        answer.append("/\">");
        answer.append(current);
        answer.append("</a></li>");

    }
    aDirs->detach();
    QStringList * aFiles = Controleur::listFiles(sDir);
    QStringListIterator fileIt(*aFiles);
    while (fileIt.hasNext()) {
        QString current = fileIt.next();
        answer.append("<li class=\"file ext_");
        answer.append(current);
        answer.append("\">");

        if(fileIt.hasNext()){
            QString current = fileIt.next();
            answer.append("<a href=\"#\" rel=\"/");
            answer.append(dDir.dirName());
            answer.append("/");
            answer.append(current);
            answer.append("\">");
            answer.append(current);
            answer.append("</a></li>");
        }
    }
    answer.append("</ul>");
    aFiles->detach();

    return answer;
}

QStringList * Controleur::listDirs( QString sDir){

    QStringList * result = new QStringList();
    QDirIterator dirIt(sDir,
                       QStringList() << "*",
                       QDir::NoSymLinks | QDir::Dirs | QDir::NoDotAndDotDot
                       );

    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isDir())
        {
            result->append(dirIt.fileName());
        }
    }
    return result;
}


QStringList * Controleur::listFiles( QString sDir){
    QStringList * result = new QStringList();
    QDirIterator fileIt(sDir,
                        QStringList() << "*",
                        QDir::NoSymLinks | QDir::Files | QDir::NoDotAndDotDot);

    while (fileIt.hasNext()) {
        fileIt.next();
        if (QFileInfo(fileIt.filePath()).isFile())
        {
            result->append(fileIt.fileInfo().suffix());
            result->append(fileIt.fileName());
        }
    }
    return result;
}
