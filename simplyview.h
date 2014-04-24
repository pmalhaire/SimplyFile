#ifndef SIMPLYVIEW_H
#define SIMPLYVIEW_H

#include <QGraphicsView>
#include "simplyweb.h"

class SimplyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SimplyView(QWidget *parent = 0);
    ~SimplyView();
signals:

public slots:
    void quit();
    QString dir(QString irootPath, QString string);

private slots:
    void addToJavaScript();

signals:
    void quitRequested();

public:
        SimplyWeb *m_SimplyWeb;
};

#endif // SIMPLYVIEW_H
