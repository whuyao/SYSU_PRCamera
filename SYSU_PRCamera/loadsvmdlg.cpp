#include "loadsvmdlg.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

LoadSVMDlg::LoadSVMDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	mpClassifier = NULL;
	mnFeatureCount = 0;
	msClassList.clear();


	connect(ui.svmBtn, SIGNAL(clicked()), this, SLOT(openSVMFile()));
	connect(ui.loadBtn, SIGNAL(clicked()), this, SLOT(loadClassifiers()));
	connect(ui.cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

LoadSVMDlg::~LoadSVMDlg()
{

}

void LoadSVMDlg::loadClassifiers()
{
	QString sSVMFile = ui.svmFile->text();

	if (mpClassifier == NULL || sSVMFile.isEmpty())
	{
		QMessageBox::warning(this, "Warning", "please input SVM pointer and SVM model file first.");
		return;
	}

	emit sig_message("loading...");
	mpClassifier->loadSVMClassifier(sSVMFile.toStdString().data(), mnFeatureCount, msClassList.size());
	emit sig_message("load SVM model success.");

	close();
}

void LoadSVMDlg::openSVMFile()
{
	QString sfilename = QFileDialog::getOpenFileName(this, "Sample File", "/", "SVM File (*.svmdat)");
	if (sfilename.isEmpty())
		return;
	ui.svmFile->setText(sfilename);
}

void LoadSVMDlg::setClassifier( SVM_MultiClassifier* pClassifier, int nFeatureCount, QStringList sClassList )
{
	mpClassifier = pClassifier;
	mnFeatureCount = nFeatureCount;
	msClassList = sClassList;
}
