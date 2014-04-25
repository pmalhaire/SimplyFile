#ifndef SIMPLYWIDGET_H
#define SIMPLYWIDGET_H

#include <QWidget>


class SimplyView;

class SimplyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SimplyWidget(QWidget *ip_parent = 0);
    ~SimplyWidget();

signals:

public slots:

public:
    SimplyView* mp_SimplyView;
};

#endif // SIMPLYWIDGET_H
