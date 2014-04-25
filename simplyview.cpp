#include "simplyview.h"
#include "simplyweb.h"
#include "controleur.h"
#include <QWebFrame>

SimplyView::SimplyView(QWidget *ip_parent) :
    QGraphicsView(ip_parent)
{
    mp_SimplyWeb=new SimplyWeb();
    setFrameShape(QFrame::NoFrame);

    QGraphicsScene *scene = new QGraphicsScene;
    setScene(scene);

    scene->addItem(mp_SimplyWeb);
    scene->setActiveWindow(mp_SimplyWeb);
    connect(mp_SimplyWeb->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));
    setFixedHeight(800);
    setFixedWidth(600);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SimplyView::~SimplyView()
{
            delete mp_SimplyWeb;
}

void SimplyView::quit()
{
    emit quitRequested();
}

QString SimplyView::dir(QString i_rootPath, QString  i_Path)
{
    return Controleur::dir(i_rootPath,i_Path);
}

void SimplyView::addToJavaScript()
{
    mp_SimplyWeb->page()->mainFrame()->addToJavaScriptWindowObject("Qt", this);
}

void SimplyView::resizeEvent(QResizeEvent *ip_event)
{
    mp_SimplyWeb->resize(ip_event->size());
}
