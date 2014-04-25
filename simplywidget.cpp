#include "simplywidget.h"
#include "simplyview.h"
#include <QVBoxLayout>

SimplyWidget::SimplyWidget(QWidget *ip_parent)
    : QWidget(ip_parent)
    , mp_SimplyView(new SimplyView(this))
{
    //QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    connect(mp_SimplyView, SIGNAL(quitRequested()), SLOT(close()));
    QVBoxLayout *p_layout = new QVBoxLayout;
    p_layout->addWidget(mp_SimplyView);
    p_layout->setMargin(0);
    setLayout(p_layout);
}



SimplyWidget::~SimplyWidget(){
    delete mp_SimplyView;
}
