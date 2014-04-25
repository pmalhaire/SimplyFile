#ifndef SIMPLYVIEW_H
#define SIMPLYVIEW_H

#include <QGraphicsView>
#include "simplyweb.h"

class SimplyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SimplyView(QWidget *ip_parent = 0);
    void resizeEvent(QResizeEvent *ip_event);
    ~SimplyView();
signals:

public slots:
    void quit();
    QString dir(QString i_rootPath, QString i_Path);

private slots:
    void addToJavaScript();

signals:
    void quitRequested();

public:
        SimplyWeb *mp_SimplyWeb;
};

#endif // SIMPLYVIEW_H
