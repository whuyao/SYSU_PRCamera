#ifndef TRAINSVMDLG_H
#define TRAINSVMDLG_H

#include <QDialog>
#include "ui_trainsvmdlg.h"
#include "SVM_MultiClassifier.h"

class TrainSVMDlg : public QDialog
{
	Q_OBJECT

public:
	TrainSVMDlg(QWidget *parent = 0);
	~TrainSVMDlg();

signals:
	void sig_message(QString smsg);

public:
	void setTrainFile(QString sfilename);
	void setClassifier(SVM_MultiClassifier* pClassifier);


public slots:
	void loadSamples();
	void setOutputFilename();
	void train();

protected:
	bool loadTrainDataset(QString sfilename);
	

private:
	Ui::TrainSVMDlg ui;

	SVM_MultiClassifier* mpClassifier;
	alglib::real_2d_array mdDataset;

public:
	QStringList msClassList; 
};

#endif // TRAINSVMDLG_H
