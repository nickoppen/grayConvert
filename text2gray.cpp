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
    uint8_t * grayData;   /// malloced in readText deleted here
    int width, height;

    int i,j;
    int newVal;
    uint8_t * pGrayData;
    string txt;

    if (argc <= 1)
    {
        cout << "What text file?" << endl;
        exit(-1);
    }


    fstream grayFile(argv[1], fstream::in);
    if(!grayFile.is_open())
    {
        printf("Something wrong with the input gray file...\n");
        exit(-1);
    }

    grayFile >> txt >> width;
    grayFile >> txt >> height;

    /// Allocate space to store the gray scale information
    grayData = (uint8_t *)malloc(width * height * sizeof(uint8_t));
    pGrayData = grayData;

    /// read in the gray scale values
    size_t startPos = 8;            /// skip over "image ["
    size_t commaPos;
    for(i=0; i < height; i++)
    {
        getline(grayFile, txt, ';');
        for(j=0; j < width; j++)
        {
            commaPos = txt.find(',', startPos);
            if (commaPos == string::npos)        /// not found
                commaPos = txt.length();

            newVal = stoi(txt.substr(startPos, commaPos - startPos), 0);
            *pGrayData = newVal & 0xFFFF;       /// strip off all bit the last 8 bits
            pGrayData++;

            startPos = commaPos + 1;
        }
        startPos = 0;
    }
    grayFile.close();

    Size imgSize(width, height);
//    cout << "width " << imgSize.width << endl << "height " << imgSize.height << endl;
    Mat img(imgSize, CV_8UC1, grayData, width);
    imwrite("img.tif", img);

    delete grayData;
    return 0;
}



