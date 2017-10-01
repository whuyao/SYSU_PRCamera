#include "SVM_MultiClassifier.h"
#include <iostream>
using namespace alglib;
using namespace std;

SVM_MultiClassifier::SVM_MultiClassifier()
{
	mSvmProblem.y = NULL;
	mSvmProblem.x = NULL;
	mnTrainingDataCount = mnFeatureCount = mnClassCount = 0;
	mpSvmParam = NULL;
	mpSvmModel = NULL;
	mpPredictNodes = NULL;
	//mpProbability  = NULL;
}

SVM_MultiClassifier::~SVM_MultiClassifier()
{
	if (mSvmProblem.y != NULL)
	{
		delete []mSvmProblem.y;
		mSvmProblem.y = NULL;

		for (int i=0; i<mnTrainingDataCount; i++)
			delete []mSvmProblem.x[i];
		delete []mSvmProblem.x;
		mSvmProblem.x = NULL;
	}

	if (mpPredictNodes != NULL)
		delete []mpPredictNodes;
	mpPredictNodes = NULL;


	if (mpSvmParam != NULL)
		svm_destroy_param(mpSvmParam);
	mpSvmParam = NULL;

	if (mpSvmModel != NULL)
		svm_free_and_destroy_model(&mpSvmModel);
	mpSvmModel = NULL;

// 	if (mpProbability != NULL)
// 		delete []mpProbability;
// 	mpProbability = NULL;

	mbIsValid = false;
}

bool SVM_MultiClassifier::loadDataFromAlglibData( alglib::real_2d_array tdata )
{
	mbIsValid = false;

	if (tdata.rows() == 0)
	{
		cout<<"training data is null. error."<<endl;
		return false;
	}

	int i = 0, j = 0;

	mnTrainingDataCount = tdata.rows();
	mnFeatureCount = tdata.cols()-1;
	mnClassCount = 0;

	for (i=0; i<tdata.rows(); i++)
	{
		if (tdata[i][tdata.cols()-1]+1 > mnClassCount)
			mnClassCount = tdata[i][tdata.cols()-1]+1;
	}

	cout<<"Training data count = "<<mnTrainingDataCount<<endl;
	cout<<"Feature count = "<<mnFeatureCount<<endl;
	cout<<"Class count = "<<mnClassCount<<endl;

	if (mSvmProblem.y != NULL)
	{
		delete []mSvmProblem.y;
		mSvmProblem.y = NULL;

		for (int i=0; i<mnTrainingDataCount; i++)
			delete []mSvmProblem.x[i];
		delete []mSvmProblem.x;
		mSvmProblem.x = NULL;
	}

	mSvmProblem.l = mnTrainingDataCount;
	mSvmProblem.y = (double*)malloc(sizeof(double)*mnTrainingDataCount); //new double[mnTrainingDataCount];
	mSvmProblem.x = (svm_node**)malloc(sizeof(svm_node*)*mnTrainingDataCount);//new struct svm_node*[mnTrainingDataCount];

	for (i=0; i<mnTrainingDataCount; i++)
	{
		mSvmProblem.y[i] = tdata[i][tdata.cols() - 1]; //从0开始
		mSvmProblem.x[i] = (svm_node*)malloc(sizeof(svm_node)*(mnFeatureCount+1));//new struct svm_node[mnFeatureCount+1];	//最后一列index=-1
		
		for (j=0; j<mnFeatureCount; j++)
		{
			mSvmProblem.x[i][j].index = j+1;
			mSvmProblem.x[i][j].value = tdata[i][j];
		}
		mSvmProblem.x[i][mnFeatureCount].index= -1;
	}

	cout<<"load alglib support data success."<<endl;

	//
	if (mpPredictNodes != NULL)
		delete []mpPredictNodes;
	mpPredictNodes = new svm_node[mnFeatureCount+1]; //最后一列为-1

// 	if (mpProbability != NULL)
// 		delete []mpProbability;
// 	mpProbability = new double[mnClassCount];

	return true;

}

bool SVM_MultiClassifier::setSVMParameters( double dgamma /*= -1*/, double dC /*= 1*/, int kenerel_type /*= SIGMOID*/, int nr_weight /*= -1*/, int* weight_label/*=NULL*/, double* weight/*=NULL*/, int poly_degree /*= 3*/, double coef0 /*= 0*/, double cache_size /*= 1000*/, double eps /*= 1e-5*/, double shrinking /*= 1*/  )
{
	if (mpSvmParam != NULL)
		svm_destroy_param(mpSvmParam);
	mpSvmParam = new svm_parameter;

	if (dgamma < 0)
		dgamma = 1.0f/(double)mnFeatureCount;

	mpSvmParam->svm_type = C_SVC;
	mpSvmParam->kernel_type = kenerel_type;
	mpSvmParam->probability = 1;

	mpSvmParam->degree = poly_degree;
	mpSvmParam->gamma = dgamma;
	mpSvmParam->C = dC;
	mpSvmParam->cache_size = cache_size;
	mpSvmParam->eps = eps;
	mpSvmParam->shrinking = shrinking;

	if (nr_weight >= 0)
	{
		mpSvmParam->nr_weight = nr_weight;
		mpSvmParam->weight_label = 0; //(int *)malloc(sizeof(int)*mpSvmParam->nr_weight);
		mpSvmParam->weight = 0; //(double *)malloc(sizeof(double)*mpSvmParam->nr_weight);
		if (nr_weight > 0)
		{
			mpSvmParam->weight_label = (int *)malloc(sizeof(int)*mpSvmParam->nr_weight);
			mpSvmParam->weight = (double *)malloc(sizeof(double)*mpSvmParam->nr_weight);
			memcpy(mpSvmParam->weight_label, weight_label, sizeof(int)*nr_weight);
			memcpy(mpSvmParam->weight, weight, sizeof(double)*nr_weight);
		}
	}
	else
	{
		mpSvmParam->nr_weight = mnClassCount;
		mpSvmParam->weight_label = (int *)malloc(sizeof(int)*mpSvmParam->nr_weight);
		mpSvmParam->weight = (double *)malloc(sizeof(double)*mpSvmParam->nr_weight);

		for (int i=0; i<mnClassCount; i++)
		{
			mpSvmParam->weight_label[i] = i;
			mpSvmParam->weight[i] = dC;	//分配权重
		}
	}
	
	//检查数据集
	const char* sCheck = svm_check_parameter(&mSvmProblem, mpSvmParam);
	if (strcmp(sCheck, "success") == 0)
	{
		cout<<"set parameters success."<<endl;
		return true;
	}
	else
	{
		cout<<sCheck<<endl;
		cout<<"set parameters fail. error." <<endl;
		return false;
	}
}


bool SVM_MultiClassifier::training( const char* sSaveFilename )
{
	if (mpSvmModel != NULL)
		svm_free_and_destroy_model(&mpSvmModel);
	
	mpSvmModel = svm_train(&mSvmProblem, mpSvmParam);


	svm_save_model(sSaveFilename, mpSvmModel);
	cout<<"save SVM model to "<<sSaveFilename<<" success."<<endl;

	mbIsValid = true;
	return true;
}

bool SVM_MultiClassifier::outputSVMModelOverallAccuracy( alglib::real_2d_array tdata, double& dOA, double& dKappa )
{
	if (mnClassCount <= 0)
	{
		cout<<"class count = 0 during accuracy evaluation. exit."<<endl;
		return false;
	}

	int nTotalCount = tdata.rows();
	int nCorrectCount = 0;

	double** _cm = new double*[mnClassCount];
	for (int i=0; i<mnClassCount; i++)
	{
		_cm[i] = new double[mnClassCount];
		memset(_cm[i], 0, sizeof(double)*mnClassCount);
	}

	int j,k;
	real_1d_array dst;
	for (j=0; j<tdata.rows(); j++)
	{
		real_1d_array prearr;
		prearr.setlength(tdata.cols()-1);
		for (k=0; k<tdata.cols()-1; k++)
		{
			prearr[k] = tdata[j][k];
		}

		int simid = int(predict_class(prearr)+0.5);
		int realid = int(tdata[j][tdata.cols()-1]+0.5);

		if (simid < 0 || realid < 0 || simid >= mnClassCount || realid >= mnClassCount)
		{
			for (int i=0; i<mnClassCount; i++)
				delete []_cm[i];
			delete []_cm;

			cout<<"error id during accuracy evaluation. exit."<<endl;
			return false;
		}

		_cm[realid][simid] += 1;
	}

	computeOA_Kappa(_cm, mnClassCount, dOA, dKappa);
	
	cout<<"Overall Accuracy (OA) of current SVM model = "<<dOA<<endl;
	cout<<"Kappa coefficient (KP) of current SVM model = "<<dKappa<<endl;

	for (int i=0; i<mnClassCount; i++)
		delete []_cm[i];
	delete []_cm;

	return true;
}

bool SVM_MultiClassifier::loadSVMClassifier( const char* sSVMFilename, int nFeatureCount, int nClassCount )
{
	if (mpSvmModel != NULL)
		svm_free_and_destroy_model(&mpSvmModel);

	mnFeatureCount = nFeatureCount;
	mnClassCount = nClassCount;
	mpSvmModel = svm_load_model(sSVMFilename);

	if (mpPredictNodes != NULL)
		delete []mpPredictNodes;
	mpPredictNodes = new svm_node[mnFeatureCount+1]; //最后一列为-1

// 	if (mpProbability != NULL)
// 		delete []mpProbability;
// 	mpProbability = new double[mnClassCount];

	cout<<"load SVM file success."<<endl;

	mbIsValid = true;

	return true;
}

double SVM_MultiClassifier::predict_probabilities( alglib::real_1d_array predata, alglib::real_1d_array& dProbabilities )
{
	if (mpPredictNodes == NULL)
		mpPredictNodes = new svm_node[mnFeatureCount+1]; //最后一列为-1
// 	if (mpProbability == NULL)
// 		mpProbability = new double[mnClassCount];

	double* pSVMProbility = new double[mnClassCount];

	dProbabilities.setlength(mnClassCount);

	//change
	int i = 0;
	for (i=0; i<mnFeatureCount; i++)
	{
		mpPredictNodes[i].index = i+1;
		mpPredictNodes[i].value = predata[i];
	}
	mpPredictNodes[mnFeatureCount].index = -1;

	//predict
	double dresult = svm_predict_probability(mpSvmModel, mpPredictNodes, pSVMProbility);

	///	
	for (i=0; i<mnClassCount; i++)
		dProbabilities[i] = pSVMProbility[i];

// 	free(mpProbability);
// 	mpProbability = NULL;
	//delete []pSVMProbility;

	return dresult;
}

double SVM_MultiClassifier::predict_class( alglib::real_1d_array predata )
{
	if (mpPredictNodes == NULL)
		mpPredictNodes = new svm_node[mnFeatureCount+1]; //最后一列为-1

	//change
	int i = 0;
	for (i=0; i<mnFeatureCount; i++)
	{
		mpPredictNodes[i].index = i+1;
		mpPredictNodes[i].value = predata[i];
	}
	mpPredictNodes[mnFeatureCount].index = -1;

	//predict
	double dresult = svm_predict(mpSvmModel, mpPredictNodes);

	return dresult;
}

bool SVM_MultiClassifier::isValid()
{
	return mbIsValid;
}

void SVM_MultiClassifier::setValid( bool bisValid )
{
	mbIsValid = bisValid;
}

int SVM_MultiClassifier::getClassCount()
{
	return mnClassCount;
}

int SVM_MultiClassifier::getFeatureCount()
{
	return mnFeatureCount;
}

bool SVM_MultiClassifier::computeOA_Kappa( double** _cm, int classCount, double& dOA, double& dKappa )
{
	//分析混淆矩阵并制作kappa系数
	double _overAllAccu = 0;			//总体分类误差
	double* _commission = new double[classCount];	//错分误差
	double* _omission = new double[classCount];	//漏分误差
	double* _prodAccu = new double[classCount];	//制图精度
	double* _userAccu = new double[classCount];	//用户精度
	double _kappa = 0;					//kappa系数

	memset(_commission, 0, classCount*sizeof(double));
	memset(_omission, 0, classCount*sizeof(double));
	memset(_prodAccu, 0, classCount*sizeof(double));
	memset(_userAccu, 0, classCount*sizeof(double));

	//开始计算
	int i, j;	//i-row, j-col
	double sum_all = 0;
	double* sum_row = new double[classCount];
	double* sum_col = new double[classCount];
	memset(sum_row, 0, classCount*sizeof(double));
	memset(sum_col, 0, classCount*sizeof(double));

	double sum_duijiaoxian = 0;	//对角线和
	for (i=0; i<classCount; i++)
	{
		for (j=0; j<classCount; j++)
		{
			if (i==j)
				sum_duijiaoxian += _cm[i][j];

			sum_all += _cm[i][j];
			sum_row[i] += _cm[i][j];	
			sum_col[j] += _cm[i][j];

		}
	}

	_overAllAccu = sum_duijiaoxian/sum_all;	//总体精度
	for (i=0; i<classCount; i++)
	{
		_commission[i] = (sum_row[i]-_cm[i][i])/sum_row[i];
		_omission[i] = (sum_col[i]-_cm[i][i])/sum_col[i];
		_prodAccu[i] = _cm[i][i]/sum_col[i];
		_userAccu[i] = _cm[i][i]/sum_row[i];
	}

	//计算kappa系数
	double _val = 0;
	for (i=0; i<classCount; i++)
	{
		_val += sum_row[i]*sum_col[i];
	}

	_kappa = (sum_all*sum_duijiaoxian-_val)/(sum_all*sum_all-_val);

	dOA = _overAllAccu;
	dKappa = _kappa;

	delete []_commission;
	delete []_omission;
	delete []_prodAccu;
	delete []_userAccu;
	delete []sum_row;
	delete []sum_col;
	return true;
}
