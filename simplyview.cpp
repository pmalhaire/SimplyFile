#include "simplyview.h"
#include "simplyweb.h"
#include "controleur.h"
#include <QWebFrame>

SimplyView::SimplyView(QWidget *parent) :
    QGraphicsView(parent)
{
    m_SimplyWeb=new SimplyWeb();
    setFrameShape(QFrame::NoFrame);



    QGraphicsScene *scene = new QGraphicsScene;
    setScene(scene);

    scene->addItem(m_SimplyWeb);
    scene->setActiveWindow(m_SimplyWeb);
    connect(m_SimplyWeb->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));
    setFixedHeight(800);
    setFixedWidth(600);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SimplyView::~SimplyView()
{
            delete m_SimplyWeb;
}

void SimplyView::quit()
{
    emit quitRequested();
}

QString SimplyView::dir(QString irootPath, QString  string)
{
    return Controleur::dir(irootPath,string);
}

void SimplyView::addToJavaScript()
{
    m_SimplyWeb->page()->mainFrame()->addToJavaScriptWindowObject("Qt", this);
}

void SimplyView::resizeEvent(QResizeEvent *event)
{
    m_SimplyWeb->resize(event->size());
}
