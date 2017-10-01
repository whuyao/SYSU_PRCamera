#ifndef ALGLIB_SVM_MULTI_CLASSIFIER_H
#define ALGLIB_SVM_MULTI_CLASSIFIER_H


#include "svm.h"
#include "alglib/statistics.h"
#include "alglib/dataanalysis.h"
#include "alglib/alglibmisc.h"

class SVM_MultiClassifier
{
public:
	SVM_MultiClassifier();
	~SVM_MultiClassifier();

public:
	//load data
	bool loadDataFromAlglibData(alglib::real_2d_array tdata);

	//gamma=1/feature_num; (if dgamma < 0, use recommendation value)
	//C=1;
	//if weight_label < 0, use recommendation value
	bool setSVMParameters(double dgamma = -1, double dC = 1, int kenerel_type = SIGMOID, int nr_weight = -1, int* weight_label=NULL, double* weight=NULL, int poly_degree = 3, double coef0 = 0, double cache_size = 1000, double eps = 1e-5, double shrinking = 1);

	//training model via dataset
	bool training(const char* sSaveFilename);
	
	//load model (if using this, u can not load data, set parameters and training model)
	bool loadSVMClassifier(const char* sSVMFilename, int nFeatureCount, int nClassCount);

	//compute current OA of SVM model, test_data (with id at last cols)
	bool outputSVMModelOverallAccuracy(alglib::real_2d_array test_data, double& dOA, double& dKappa);

	//predict probability
	double predict_probabilities(alglib::real_1d_array predata, alglib::real_1d_array& dProbabilities);

	//predict class id
	double predict_class(alglib::real_1d_array predata);

public:
	bool isValid();
	void setValid(bool bisValid);
	int getClassCount();
	int getFeatureCount();

private:
	inline bool computeOA_Kappa(double** _cm, int classCount, double& dOA, double& dKappa);

private:
	int mnTrainingDataCount;
	int mnClassCount;
	int mnFeatureCount;
	svm_problem mSvmProblem;
	svm_node* mpPredictNodes;
	//double* mpProbability;

protected:
	svm_parameter* mpSvmParam;
	svm_model* mpSvmModel;

	bool mbIsValid;
};
























#endif