#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[])
{
 // Open another image
    if(argc > 1) {
        std::string fileLoc = argv[1];
        Mat image, testImage;
        image= cv::imread(fileLoc);

    
        // define bounding rectangle 
        // cv::Rect rectangle(300,70,150,200); // Camera 1
        cv::Rect rectangle(300,100,150,200); // Camera 2

        cv::Mat result; // segmentation result (4 possible values)
        cv::Mat bgModel,fgModel; // the models (internally used)
    
        // GrabCut segmentation
        cv::grabCut(image,    // input image
                        result,   // segmentation result
                                rectangle,// rectangle containing foreground 
                                bgModel,fgModel, // models
                                1,        // number of iterations
                                cv::GC_INIT_WITH_RECT); // use rectangle
    
        // Get the pixels marked as likely foreground
        cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
        // Generate output image
        cv::Mat foreground(image.size(),CV_8UC3,cv::Scalar(0,0,0));
        image.copyTo(foreground,result); // bg pixels not copied
        
        cv::Mat t(testImage.size(),CV_8UC3,cv::Scalar(0,0,0));
        testImage.copyTo(t, result);
        // draw rectangle on original image
        cv::rectangle(image, rectangle, cv::Scalar(255,255,255),1);
        cv::namedWindow("Image");
        cv::imshow("Image",image);

        cv::namedWindow("Test");
        cv::imshow("Test",t);
    
        // display result
        cv::namedWindow("Segmented Image");
        cv::imshow("Segmented Image",foreground);
    
    
        waitKey();
    }
    
    return 0;
}