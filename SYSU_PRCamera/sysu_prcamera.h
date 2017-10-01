#ifndef SYSU_PRCAMERA_H
#define SYSU_PRCAMERA_H

#include <QtGui>
#include "ui_sysu_prcamera.h"
#include "SVM_MultiClassifier.h"
#include <opencv2/opencv.hpp>

#include <QTimer>
#include <QImage>

class SYSU_PRCamera : public QMainWindow
{
	Q_OBJECT

public:
    SYSU_PRCamera(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~SYSU_PRCamera();


protected slots:
	void updateCamera();
	void runCamera();
	void closeCamera();
	void runUsual();
	void savePhoto();	
	void clearSettings();
	void exportSamples();
	void trainSVM();
	void loadSVM();
	void precictCurrentImage();
	void startCamera();

protected:  
	void paintEvent(QPaintEvent *e);  
	void keyPressEvent(QKeyEvent *ev);
	void closeEvent(QCloseEvent *ev);


private slots:
	void addOutput(QString smessage);
	void computeCurrentGIST();



private:
	Ui::SYSU_PRCameraClass ui;
	cv::VideoCapture mcVideo;
	QImage mImgShow;
	cv::Mat mImgSrc;
	cv::Mat mImgProc;	//用于处理的图像
	bool mbIsCameraRuning;

	QTimer mTimerCamera;
	QTimer mTimerProgram;

	uint mnCurrentTime;
	QString msCurrentDir;
	int mnProcSize;
	int mnGISTDimensions;

	SVM_MultiClassifier mSVMClassifier;
	QStringList msSVMClassList;


};

#endif // SYSU_PRCAMERA_H
