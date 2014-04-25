#include <QApplication>

#include "simplywidget.h"
#include "simplyview.h"
#include "simplyweb.h"
#include <QFileInfo>
#include <QUrl>

#define DEBUG

#ifdef DEBUG
#include <QWebSettings>
#endif

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
#ifdef DEBUG
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
#endif
   SimplyWidget appView;
   QString fileName("html/index.html");
   QUrl adress = QUrl::fromLocalFile(QFileInfo(fileName).absoluteFilePath());
   appView.mp_SimplyView->mp_SimplyWeb->setUrl(adress);
   appView.mp_SimplyView->mp_SimplyWeb->load(adress);
   appView.show();
   return app.exec();
}
