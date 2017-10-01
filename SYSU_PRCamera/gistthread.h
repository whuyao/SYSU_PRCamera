#ifndef GISTTHREAD_H
#define GISTTHREAD_H

#include <QThread>
#include "opencv2/opencv.hpp"

class GISTThread : public QThread
{
	Q_OBJECT

public:
	GISTThread(QObject *parent);
	~GISTThread();

signals:
	void sig_message(QString smsg);
	void finished();

public:
	void setParam(cv::Mat* pImg, float*& pGist, int& nDimension);
	void run();

private:
	long mnFID;
	cv::Mat* mpProcImg;
	float* mpGist;
	int * mpnDimension;

};

#endif // GISTTHREAD_H
