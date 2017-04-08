#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc <= 1)
        cout << "what image?" << endl;
    else
        cout << "Processing: " << argv[1] << endl;

    Mat img = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    if(img.empty())
    {
        cout << "That image was empty" << endl;
        return -1;
    }
    Size sz = img.size();

    ofstream outfile(".//grey.csv");
    outfile << "width " << sz.width << endl << "height " << sz.height << endl;
    outfile << "image " << img;
    outfile.close();

    return 0;
}



