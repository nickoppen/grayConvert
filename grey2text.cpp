#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

void usage(char *argv[])
{
        cout << "usage: " << argv[0] << " <image> [-o <textfile>]" << endl;
        exit(-1);
}

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
    cout << " the type is:" << img.type() << endl;

    if (argc == 2)
    {
        cout << "width " << sz.width << endl << "height " << sz.height << endl;
        cout << "image " << img;
        return 0;
    }

    if (argc == 4)
    {
        if(strcmp(argv[2], "-o") == 0)
        {
            ofstream outfile;
            outfile.open(argv[3]);

            outfile << "width " << sz.width << endl << "height " << sz.height << endl;
            outfile << "image " << img;
            outfile.close();
        }
        else
            usage(argv);
    }
    else
        usage(argv);


    return 0;
}



