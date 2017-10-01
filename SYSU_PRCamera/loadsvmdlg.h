#ifndef LOADSVMDLG_H
#define LOADSVMDLG_H

#include <QDialog>
#include "ui_loadsvmdlg.h"
#include "SVM_MultiClassifier.h"

class LoadSVMDlg : public QDialog
{
	Q_OBJECT

public:
	LoadSVMDlg(QWidget *parent = 0);
	~LoadSVMDlg();

signals:
	void sig_message(QString smsg);

public slots:
	void loadClassifiers();
	void openSVMFile();

public:
	void setClassifier(SVM_MultiClassifier* pClassifier, int nFeatureCount, QStringList sClassList);


private:
	Ui::LoadSVMDlg ui;
	SVM_MultiClassifier* mpClassifier;
	int mnFeatureCount;
	QStringList msClassList;
};

#endif // LOADSVMDLG_H
