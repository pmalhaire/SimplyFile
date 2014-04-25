#include <QApplication>

#include <QWebSettings>

#include "simplywidget.h"
#include "simplyview.h"
#include "simplyweb.h"
#include <QFileInfo>
#include <QUrl>

#define DEBUG


int main(int argc, char **argv)
{
	QApplication app(argc, argv);
#ifdef DEBUG
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
#endif
   SimplyWidget appView;
   QString fileName("html/index.html");
   QUrl adress = QUrl::fromLocalFile(QFileInfo(fileName).absoluteFilePath());
   appView.m_SimplyView->m_SimplyWeb->setUrl(adress);
   appView.m_SimplyView->m_SimplyWeb->load(adress);
   appView.show();
   return app.exec();
    //app.quit();


    /*




    QGraphicsScene *scene = new QGraphicsScene;
    app->setScene(scene);
    scene->addItem(view);
    scene->setActiveWindow(view);
    view->resize(600,800);
    //setFrameShape(QFrame::NoFrame);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




    //appView->setScene(scene);


    QString fileName("file://SimplyFile/index.htm");
    view->setUrl(QUrl::fromLocalFile(QFileInfo(fileName).absoluteFilePath()));
    appView->show();
    return app.exec();*/
}
