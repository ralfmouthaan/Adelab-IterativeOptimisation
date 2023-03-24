#pragma once

#include "Spinnaker.h"
#include "SpinGenApi/SpinnakerGenApi.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace Spinnaker;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;

class clsBlackfly
{

protected:

    std::string SerialNo = "22492860";
    PixelFormatEnums PixelFormat = PixelFormatEnums::PixelFormat_Mono8;
    SystemPtr pSystem;
    CameraPtr pCam;
    ImageProcessor ImgProcessor;

    ImagePtr CaptureImage_SpinnakerPtr();
    cv::Mat CaptureImage_CVMat();

public:

    int Width;
    int Height;

    clsBlackfly();
    ~clsBlackfly();

    double GetExposure();
    void SetExposure(double Exposure);
    double GetGain();
    void SetGain(double Gain);
    double GetFrameRate();
    void SetupTrigger(const char* Trigger);

    cv::Mat GetImage();
    void ExecuteTrigger();

};

