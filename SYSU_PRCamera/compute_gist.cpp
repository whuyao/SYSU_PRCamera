#include "compute_gist.h"
#include "gist.h"
#include "standalone_image.h"

bool gist_run( cv::Mat* pImg, float*& pGist, int& nDimension )
{
	if (pImg == NULL)
		return false;

	//生成数据
	int nblocks=4;
	int n_scale=4;
	int orientations_per_scale[4]={8,8,8,8};

	int descsize=0;
	/* compute descriptor size */
	int i, j;
	for(i=0;i<n_scale;i++) 
		descsize+=nblocks*nblocks*orientations_per_scale[i];

	descsize*=3; /* color */

	nDimension = descsize;

	////////	
	color_image_t *im=color_image_new(pImg->cols, pImg->rows);

	for (i=0; i<pImg->rows; i++)
	{
		for (j=0; j<pImg->cols; j++)
		{
			im->c1[i*pImg->cols+j] = *((unsigned char*)pImg->data+i*pImg->cols*pImg->channels()+j*pImg->channels()+0);
			im->c2[i*pImg->cols+j] = *((unsigned char*)pImg->data+i*pImg->cols*pImg->channels()+j*pImg->channels()+1);
			im->c3[i*pImg->cols+j] = *((unsigned char*)pImg->data+i*pImg->cols*pImg->channels()+j*pImg->channels()+2);
		}
	}

	pGist=color_gist_scaletab(im,nblocks,n_scale,orientations_per_scale); 

	color_image_delete(im);

	return true;
}
