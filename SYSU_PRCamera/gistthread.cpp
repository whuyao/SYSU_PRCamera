#include "gistthread.h"
#include "gist.h"

using namespace cv;

GISTThread::GISTThread(QObject *parent)
	: QThread(parent)
{
	mnFID = -1;
	mpProcImg = NULL;
	mpGist = NULL;
	mpnDimension = NULL;
}

GISTThread::~GISTThread()
{

}

void GISTThread::setParam(cv::Mat* pImg, float*& pGist, int& nDimension )
{
	mpProcImg = pImg;
	mpGist = pGist;
	mpnDimension = &nDimension;
}

void GISTThread::run()
{
	if (mpProcImg == NULL)
	{
		emit sig_message("mnFID == -1 or Input image is NULL.");
		emit finished();
		return;
	}

	//生成数据
	int nblocks=4;
	int n_scale=4;
	int orientations_per_scale[50]={8,8,8,8};

	int descsize=0;
	/* compute descriptor size */
	int i, j;
	for(i=0;i<n_scale;i++) 
		descsize+=nblocks*nblocks*orientations_per_scale[i];

	descsize*=3; /* color */
	*mpnDimension = descsize;

	////////	
	color_image_t *im=color_image_new(mpProcImg->cols, mpProcImg->rows);

	for (i=0; i<mpProcImg->rows; i++)
	{
		for (j=0; j<mpProcImg->cols; j++)
		{
			im->c1[i*mpProcImg->cols+j] = *((unsigned char*)mpProcImg->data+i*mpProcImg->cols*mpProcImg->channels()+j*mpProcImg->channels()+0);
			im->c2[i*mpProcImg->cols+j] = *((unsigned char*)mpProcImg->data+i*mpProcImg->cols*mpProcImg->channels()+j*mpProcImg->channels()+1);
			im->c3[i*mpProcImg->cols+j] = *((unsigned char*)mpProcImg->data+i*mpProcImg->cols*mpProcImg->channels()+j*mpProcImg->channels()+2);
		}
	}

	mpGist=color_gist_scaletab(im,nblocks,n_scale,orientations_per_scale); 

	color_image_delete(im);

	emit finished();

}
