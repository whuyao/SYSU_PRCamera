#include "sysu_prcamera.h"
#include <QtCore>
#include <QtGui>
//#include <gistthread.h>
#include "compute_gist.h"
#include "trainsvmdlg.h"
#include "loadsvmdlg.h"
#include <QtWidgets>
using namespace std;
using namespace cv;

SYSU_PRCamera::SYSU_PRCamera(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	ui.featureList->clear();


	//settings
	QSettings _sets;
	QString sclassmsg = _sets.value("App/Classes", "default").toString();
	QStringList sclasslist = sclassmsg.split("/", QString::SkipEmptyParts);
	ui.classCombo->clear();
	QString stemplist;
	foreach (QString stitle, sclasslist)
	{
		stitle = stitle.toStdString().data();
		if (!stemplist.contains(stitle))
		{
			ui.classCombo->addItem(stitle);
			stemplist.append(stitle);
		}
	}
	
	//获取摄像头个数
	int camera_count = -1;
	int i = 0;
	while (1)
	{
		++camera_count;
		if (!mcVideo.open(camera_count))
			break;
		mcVideo.release();
	}
	addOutput(QString("camera count = %1").arg(camera_count));

	if (camera_count <= 0)
	{
		addOutput("no avail camera. error.");
		mbIsCameraRuning = false;
	}

	for (i=0; i<camera_count; i++)
		ui.cameraId->addItem(QString("camera - %1").arg(i+1));
	ui.cameraId->setCurrentIndex(0);
	

	///////////////////////
	mnProcSize = 256;
	mnCurrentTime = QDateTime::currentDateTime().toTime_t();

	mbIsCameraRuning = false;
	addOutput("program starting...");
	addOutput("finding camera...");

	if (!mcVideo.open(0))
	{
		addOutput("no avail camera. error.");
		mbIsCameraRuning = false;
	}
	else
	{
		addOutput("ok, camera 1 (default) running...");
		mbIsCameraRuning = true;
		mImgSrc = Mat::zeros(mcVideo.get(CV_CAP_PROP_FRAME_HEIGHT), mcVideo.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3); 
		mImgProc = Mat::zeros(mnProcSize, mnProcSize, CV_8UC3);

		//启动
		mTimerCamera.start(100);
		connect(&mTimerCamera, SIGNAL(timeout()), this, SLOT(updateCamera()));
	}

	//
	//
	msCurrentDir = QCoreApplication::applicationDirPath()+"/data";
	QDir _dir(msCurrentDir);
	if (!_dir.exists(msCurrentDir))
		_dir.mkdir(msCurrentDir);
	addOutput(QString("file will be save to ")+msCurrentDir);	


	//
	mTimerProgram.start(500);
	msSVMClassList.clear();


	//connections
    connect(ui.actionRunCamera, SIGNAL(triggered()), this, SLOT(runCamera()));
    connect(ui.actionCloseCamera, SIGNAL(triggered()), this, SLOT(closeCamera()));
    connect(ui.actionSavePhoto, SIGNAL(triggered()), this, SLOT(savePhoto()));
    connect(ui.actionClearSettings, SIGNAL(triggered()), this, SLOT(clearSettings()));
    connect(ui.actionExportSamples, SIGNAL(triggered()), this, SLOT(exportSamples()));
    connect(ui.actionTrainSVM, SIGNAL(triggered()), this, SLOT(trainSVM()));
    connect(ui.actionLoadSVM, SIGNAL(triggered()), this, SLOT(loadSVM()));
    connect(ui.actionSVMPredict, SIGNAL(triggered()), this, SLOT(precictCurrentImage()));
	connect(ui.lunchCamera, SIGNAL(clicked()), this, SLOT(startCamera()));
	//connect(ui.actionExtractCurrent, SIGNAL(activated()), this, SLOT(computeCurrentGIST()));
	connect(&mTimerProgram, SIGNAL(timeout()), this, SLOT(runUsual()));



}

SYSU_PRCamera::~SYSU_PRCamera()
{
	mcVideo.release();
	mbIsCameraRuning = false;

	/////
	//save combobox
	QSettings _sets;
	QString smsg;
	QStringList slist;
	for (int i=0; i<ui.classCombo->count(); i++)
	{
		if (slist.contains(ui.classCombo->itemText(i).trimmed().toLower()))
			continue;
		slist.append(smsg);
		smsg += ui.classCombo->itemText(i).trimmed().toLower()+"/";
	}

	_sets.setValue("App/Classes", smsg);

	
}

void SYSU_PRCamera::updateCamera()
{
	if (mbIsCameraRuning == false)
	{
		addOutput("can not find camera.");
		mTimerCamera.stop();
	}

	mcVideo>>mImgSrc;  
	if(mImgSrc.data)  
	{  
		cvtColor(mImgSrc, mImgSrc, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR  
		mImgShow = QImage((uchar*)(mImgSrc.data), mImgSrc.cols, mImgSrc.rows, QImage::Format_RGB888).scaled(ui.cameralbl->size()); 
		cv::resize(mImgSrc, mImgProc, cv::Size(mnProcSize, mnProcSize));
		this->update();  //发送刷新消息  
	}  
}

void SYSU_PRCamera::runCamera()
{
	if (mbIsCameraRuning)
	{
		addOutput("camera is running now...");
		return;
	}

	addOutput("finding camera...");

	if (!mcVideo.open(0))
	{
		addOutput("no avail camera. error.");
		mbIsCameraRuning = false;
	}

	addOutput("ok, camera 1 (default) running...");
	mbIsCameraRuning = true;

	mImgSrc = Mat::zeros(mcVideo.get(CV_CAP_PROP_FRAME_HEIGHT), mcVideo.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3); 
	mImgProc = Mat::zeros(mnProcSize, mnProcSize, CV_8UC3);


	//启动
	mTimerCamera.start(100);
	connect(&mTimerCamera, SIGNAL(timeout()), this, SLOT(updateCamera()));
}

void SYSU_PRCamera::closeCamera()
{
	if (mbIsCameraRuning)
	{
		mTimerCamera.stop();
		mcVideo.release();
		mbIsCameraRuning = false;
		addOutput("close camera.");
	}
	
}

void SYSU_PRCamera::runUsual()
{
	ui.timeLbl->setText(QString("Time: ")+QDateTime::currentDateTime().toString("yyyy/mm/dd hh:MM:ss"));

	mnCurrentTime = QDateTime::currentDateTime().toTime_t();
	ui.utcLbl->setText(QString("UTC: ")+QString::number(mnCurrentTime));
}

void SYSU_PRCamera::savePhoto()
{
	if (!mbIsCameraRuning)
	{
		addOutput("camera is not running. error.");
		return;
	}

	QString sClass = ui.classCombo->currentText().trimmed().replace(" ", "");
    QString sfilename = msCurrentDir+"/IMG_"+QString::number(mnCurrentTime)+"_"+sClass+".bmp";
    //cv::imwrite(sfilename.toStdString().data(), mImgProc);
    mImgShow.scaled(mnProcSize, mnProcSize).save(sfilename);

	addOutput(QString("current photo have been saved to %1").arg(sfilename));

	///////
	computeCurrentGIST();
}

void SYSU_PRCamera::clearSettings()
{
	int btn = QMessageBox::question(this, "QUIT", "clear current class types?", QMessageBox::Ok|QMessageBox::Cancel);
	QSettings _sets;
	if (btn == QMessageBox::Cancel)
	{
		//save combobox
		QString smsg;
		QStringList slist;
		for (int i=0; i<ui.classCombo->count(); i++)
		{
			if (slist.contains(ui.classCombo->itemText(i).trimmed().toLower()))
				continue;
			slist.append(smsg);
			smsg += ui.classCombo->itemText(i).trimmed().toLower()+"/";
		}

		_sets.setValue("App/Classes", smsg);
	}
	else
		_sets.remove("App/Classes");

	ui.classCombo->clear();
	ui.classCombo->addItem("default");
}

void SYSU_PRCamera::exportSamples()
{
	QString sfilename = QFileDialog::getSaveFileName(this, "Save", "/", "Sample files (*.samples)");
	if (sfilename.isEmpty())
		return;

	if (ui.featureList->toPlainText().isEmpty())
	{
		cout<<"feature data is NULL. error."<<endl;
		return;
	}

	QFile _file(sfilename);
	if (!_file.open(QIODevice::WriteOnly))
	{
		addOutput("create sample file fail. error.");
		return;
	}

	QTextStream _in(&_file);
	_in<<ui.featureList->toPlainText()<<"\r\n";

	_in.flush();
	_file.flush();
	_file.close();

	addOutput(QString("save sample file success. filename = %1").arg(sfilename));

}

void SYSU_PRCamera::trainSVM()
{
	int nBtn = QMessageBox::question(this, "Q!", "train SVM using current samples ?", QMessageBox::Ok|QMessageBox::Cancel);
	QString temp_filename = "./temp.samples";
	if (nBtn == QMessageBox::Ok)
	{
		QFile _file(temp_filename);
		if (!_file.open(QIODevice::WriteOnly))
		{
			addOutput("create temporary sample file fail. error.");
			return;
		}

		QTextStream _in(&_file);
		_in<<ui.featureList->toPlainText()<<"\r\n";
		//temp_filename = _file.fileName();

		_in.flush();
		_file.flush();
		_file.close();

		addOutput(QString("save temporary sample file success. filename = %1").arg(temp_filename));
	}


	///////
	TrainSVMDlg dlg(this);
	dlg.setClassifier(&mSVMClassifier);
	dlg.setTrainFile(temp_filename);
	connect(&dlg, SIGNAL(sig_message(QString)), this, SLOT(addOutput(QString)));
	dlg.exec();
	msSVMClassList = dlg.msClassList;

	if (mSVMClassifier.isValid())
		addOutput("train SVM success.");
	else
		addOutput("train SVM fail.");

}

void SYSU_PRCamera::loadSVM()
{
	int i=0;
	msSVMClassList.clear();
	for (i=0; i<ui.classCombo->count(); i++)
		msSVMClassList.append(ui.classCombo->itemText(i).trimmed().toLower());

	LoadSVMDlg dlg(this);
	dlg.setClassifier(&mSVMClassifier, mnGISTDimensions, msSVMClassList);
	connect(&dlg, SIGNAL(sig_message(QString)), this, SLOT(addOutput(QString)));
	dlg.exec();

	if (mSVMClassifier.isValid())
		addOutput("load SVM success.");
	else
		addOutput("load SVM fail.");
}

void SYSU_PRCamera::precictCurrentImage()
{
	if (!mSVMClassifier.isValid() || msSVMClassList.empty())
	{
		addOutput("please train or load SVM classifier first. quit.");
		return;
	}


	if (!mbIsCameraRuning)
	{
		addOutput("camera is not running.");
		return;
	}

	float* pGist;

	uint nCurrentId = mnCurrentTime;
	gist_run(&mImgProc, pGist, mnGISTDimensions);
	alglib::real_1d_array predict_arr;
	alglib::real_1d_array dst_arr;

	predict_arr.setlength(mnGISTDimensions);
	for (int i = 0; i<mnGISTDimensions; i++)
		predict_arr[i] = pGist[i];

	//delete []pGist;
	free(pGist);

	//////////////////////////////
	mSVMClassifier.predict_probabilities(predict_arr, dst_arr);

	if (dst_arr.length() != msSVMClassList.size())
	{
		addOutput("invalid SVM classifier. error.");
		mSVMClassifier.setValid(false);
	}


	int nMaxId = 0;
	double dMaxProb = dst_arr[0];
	for (int i=0; i<dst_arr.length(); i++)
	{
		if (dst_arr[i] >= dMaxProb)
		{
			nMaxId = i;
			dMaxProb = dst_arr[i];
		}
	}


	///////
	addOutput(QString("class probability of current photo (id = %1): ").arg(nCurrentId));
	for (int i=0; i<dst_arr.length(); i++)
	{
		addOutput(QString("\tclass id = %1, class name = %2, probability = %3%%").arg(i).arg(msSVMClassList[i]).arg(dst_arr[i]*100, 0, 'f', 4));
	}
	addOutput(QString("class of current photo (id = %4) = %1 (class id = %2, probability = %3).").arg(msSVMClassList[nMaxId]).arg(nMaxId).arg(dst_arr[nMaxId]*100, 0, 'f', 4).arg(nCurrentId));


	//delete []pGist;
}

void SYSU_PRCamera::startCamera()
{
	mbIsCameraRuning = false;
	int nCurIdx = ui.cameraId->currentIndex();
	mcVideo.release();

	if (!mcVideo.open(nCurIdx))
	{
		addOutput("no avail camera. error.");
		mbIsCameraRuning = false;
	}
	else
	{
		addOutput(QString("ok, camera %1 running...").arg(nCurIdx+1));
		mbIsCameraRuning = true;
		mImgSrc = Mat::zeros(mcVideo.get(CV_CAP_PROP_FRAME_HEIGHT), mcVideo.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3); 
		mImgProc = Mat::zeros(mnProcSize, mnProcSize, CV_8UC3);

		//启动
		mTimerCamera.start(100);
		connect(&mTimerCamera, SIGNAL(timeout()), this, SLOT(updateCamera()));
	}

}

void SYSU_PRCamera::computeCurrentGIST()
{
	if (!mbIsCameraRuning)
	{
		addOutput("camera is not running.");
		return;
	}

	float* pGist;

// 	GISTThread _gistthread(this);
// 
// 	QEventLoop loop;
// 	connect(&_gistthread, SIGNAL(finished()), &loop, SLOT(quit()));
// 	connect(&_gistthread, SIGNAL(sig_message(QString)), this, SLOT(addOutput(QString)));
// 
// 	_gistthread.setParam(&mImgProc, pGist, nDimension);
// 	_gistthread.run();
// 	
// 
// 	
// 	loop.exec();
// 

	gist_run(&mImgProc, pGist, mnGISTDimensions);
	//output
	int nCurrentTime = mnCurrentTime;
	QString smsg = QString::number(nCurrentTime);
	int i=0;
	for (i=0; i<mnGISTDimensions; i++)
	{
		smsg += QString(", ")+ QString::number(pGist[i], 'f', 4);
	}
	smsg += ", "+ui.classCombo->currentText();
// 	//addOutput(smsg);

	if (ui.featureList->toPlainText() == 0)
	{
		QString stitle = "unix_time, ";
		for (int i=0; i<mnGISTDimensions; i++)
			stitle += QString("F%1, ").arg(i);
		stitle += "class_name";

		ui.featureList->append(stitle);
	}
	ui.featureList->append(smsg);
	
	addOutput(QString("add sample (id = %1) success.").arg(nCurrentTime));

	//delete []pGist;
	free(pGist);

}

void SYSU_PRCamera::paintEvent( QPaintEvent *e )
{
	ui.cameralbl->setPixmap(QPixmap::fromImage(mImgShow));
	ui.cameralbl->show(); 
}

void SYSU_PRCamera::keyPressEvent( QKeyEvent *ev )
{
	if (ev->modifiers() == Qt::ControlModifier && ev->key() == Qt::Key_T)
		savePhoto();
	if (ev->modifiers() == Qt::ControlModifier && ev->key() == Qt::Key_P)
		precictCurrentImage();
	if (ev->modifiers() == Qt::ControlModifier && (ev->key() >= Qt::Key_0 && ev->key() <= Qt::Key_9))
	{
		int currentKey = ev->key() - Qt::Key_0;
		if (currentKey < -1 || currentKey>=ui.classCombo->count())
			ui.classCombo->setCurrentIndex(currentKey);
	}
	


	QMainWindow::keyPressEvent(ev);
	
}

void SYSU_PRCamera::closeEvent( QCloseEvent *ev )
{
	int nbtn = QMessageBox::question(this, "QUIT", "Quit program ?", QMessageBox::Ok|QMessageBox::Cancel);
	if (nbtn == QMessageBox::Cancel)
	{
		ev->ignore();
		return;
	}

	//exit(0);

	QMainWindow::closeEvent(ev);
}

void SYSU_PRCamera::addOutput( QString smessage )
{
	ui.output->append(QDateTime::currentDateTime().toString("yyyymmdd hh:MM:ss")+" >> "+smessage);
}
