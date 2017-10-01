#include "sysu_prcamera.h"
#include <QtGui>
//#include <QtCore/QTextCodec>
#include <QtCore/QSettings>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//set code for locale, support chinese
//	QTextCodec* codec =QTextCodec::codecForLocale();
//	QTextCodec::setCodecForCStrings(codec);
//	QTextCodec::setCodecForTr(codec);

	QSettings settings("Sun Yat-sen University", "PRCamera"); //  公司或组织名  // 应用程序名
	QCoreApplication::setOrganizationName("SYSU");
	QCoreApplication::setOrganizationDomain("www.geosimulation.cn"); // 专为Mac OS X 准备的
	QCoreApplication::setApplicationName("PRCamera");


	SYSU_PRCamera w;
	w.show();
	return a.exec();
}
