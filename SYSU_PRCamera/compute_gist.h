#ifndef SYSU_CAMERA_GIST_COMPUTE_H
#define SYSU_CAMERA_GIST_COMPUTE_H

#include "opencv2/opencv.hpp"
bool gist_run(cv::Mat* pImg, float*& pGist, int& nDimension);

#endif