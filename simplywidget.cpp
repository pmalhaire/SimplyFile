#include "simplywidget.h"
#include "simplyview.h"
#include <QVBoxLayout>

SimplyWidget::SimplyWidget(QWidget *parent)
    : QWidget(parent)
    , m_SimplyView(new SimplyView(this))
{
    //QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    connect(m_SimplyView, SIGNAL(quitRequested()), SLOT(close()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_SimplyView);
    layout->setMargin(0);
    setLayout(layout);
}



SimplyWidget::~SimplyWidget(){
    delete m_SimplyView;
}
