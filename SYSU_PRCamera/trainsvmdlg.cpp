#include "trainsvmdlg.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

TrainSVMDlg::TrainSVMDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	mpClassifier = NULL;
	connect(ui.sampleBtn, SIGNAL(clicked()), this, SLOT(loadSamples()));
	connect(ui.svmBtn, SIGNAL(clicked()), this, SLOT(setOutputFilename()));
	connect(ui.trainBtn, SIGNAL(clicked()), this, SLOT(train()));
	connect(ui.cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

TrainSVMDlg::~TrainSVMDlg()
{

}

void TrainSVMDlg::setTrainFile( QString sfilename )
{
	ui.sampleFile->setText(sfilename);
}

void TrainSVMDlg::setClassifier( SVM_MultiClassifier* pClassifier )
{
	mpClassifier = pClassifier;
}

void TrainSVMDlg::loadSamples()
{
	QString sfilename = QFileDialog::getOpenFileName(this, "Sample File", "/", "Samples (*.samples)");
	if (sfilename.isEmpty())
		return;
	ui.sampleFile->setText(sfilename);
}

void TrainSVMDlg::setOutputFilename()
{
	QString sfilename = QFileDialog::getSaveFileName(this, "Sample File", "/", "SVM File (*.svmdat)");
	if (sfilename.isEmpty())
		return;
	ui.svmFile->setText(sfilename);
}

void TrainSVMDlg::train()
{
	QString sSampleFile = ui.sampleFile->text();
	QString sSVMFile = ui.svmFile->text();

	if (mpClassifier == NULL || sSVMFile.isEmpty() || sSampleFile.isEmpty())
	{
		QMessageBox::warning(this, "Warning", "please input SVM pointer and I/O files first.");
		return;
	}

	if (!loadTrainDataset(sSampleFile) || mdDataset.rows() == 0)
	{
		QMessageBox::warning(this, "Warning", "load train samples file error.");
		return;
	}

	////
	double dRatio = ui.train_rate->value();
	double dgamma = ui.gamma->value();
	double dC = ui.dC->value();
	double dOA, dKappa;

	emit sig_message(QString("training ratio = %1, gamma = %2, penalty = %3").arg(dRatio, 0, 'f', 4).arg(dgamma, 0, 'f', 4).arg(dC, 0, 'f', 4));

	//按照比例生成数据集
	int nTrainingCount = int(mdDataset.rows() * dRatio);
	QList<int> select_ids;
	select_ids.clear();

	alglib::real_2d_array trainingdata;
	trainingdata.setlength(nTrainingCount, mdDataset.cols());
	int i, j;
	for (i=0; i<nTrainingCount; i++)
	{
		int nIdx = rand()%mdDataset.rows();
		if (select_ids.contains(nIdx) || nIdx>= mdDataset.rows())
			continue;

		select_ids.append(nIdx);
		for (j=0; j<mdDataset.cols(); j++)
			trainingdata[i][j] = mdDataset[nIdx][j];
	}

	//
	emit sig_message("training...");
	mpClassifier->loadDataFromAlglibData(trainingdata);
	mpClassifier->setSVMParameters(dgamma, dC, RBF, -1);
	mpClassifier->training(sSVMFile.toStdString().data());	
	mpClassifier->outputSVMModelOverallAccuracy(mdDataset, dOA, dKappa);
	emit sig_message("train SVM model success.");

	emit sig_message(QString("during training process, validation overall accuracy = %1, kappa = %2").arg(dOA, 0, 'f', 6).arg(dKappa, 0, 'f', 6));
	emit sig_message(QString("SVM training file have been saved to %1").arg(sSVMFile));

	//close();
}

bool TrainSVMDlg::loadTrainDataset(QString sfilename)
{
	int nDataCount = 0, nFeatureCount = 0;
	
	QFile _file(sfilename);
	if (!_file.open(QIODevice::ReadOnly))
	{
		emit sig_message("load samples data fail. error.");
		return false;
	}

	QTextStream _in(&_file);

	QString smsg = _in.readLine();
	QStringList slist =smsg.split(", ", QString::SkipEmptyParts);
	nFeatureCount = slist.size()- 2;

	msClassList.clear();
	//////////////////////////////////////////////////////////////////////////
	while (!_in.atEnd())
	{
		smsg = _in.readLine();
		slist =smsg.split(", ", QString::SkipEmptyParts);

		if (slist.size() != nFeatureCount+2)
			continue;

		nDataCount++;

		QString sClass = slist[slist.size()-1].trimmed().toLower();
		if (!msClassList.contains(sClass))
			msClassList.append(sClass);
	}

	emit sig_message(QString("training data count = %1").arg(nDataCount));
	emit sig_message(QString("training feature count = %1").arg(nFeatureCount));
	emit sig_message(QString("training class count = %1").arg(msClassList.size()));

	mdDataset.setlength(nDataCount, nFeatureCount+1);
	////
	_in.seek(0);
	smsg = _in.readLine();
	slist =smsg.split(", ", QString::SkipEmptyParts);
	
	int i=0, j=0;
	while (!_in.atEnd())
	{
		smsg = _in.readLine();
		slist =smsg.split(", ", QString::SkipEmptyParts);

		if (slist.size() != nFeatureCount+2)
			continue;

		QString sClass = slist[slist.size()-1].trimmed().toLower();
		int nID = msClassList.indexOf(sClass);

		for (j=0; j<nFeatureCount; j++)
		{
			mdDataset[i][j]= slist[1+j].trimmed().toDouble();
		}
		mdDataset[i][nFeatureCount] = nID;

		i++;
	}

	emit sig_message("load training dataset success.");

	_file.close();
	return true;
}
