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

void readText(int * grayVals, char * fileName, int * width, int * height)
{
//    FILE * grayFile;
    int sizeInBytes;
    int i,j;
    string txt;
    int * pGrayVals;

    fstream grayFile(fileName, fstream::in);
    if(!grayFile.is_open())
    {
        printf("Something wrong with the input gray file...\n");
        exit(-1);
    }

//    fscanf(grayFile, "%s %d", txt, width);
//    fscanf(grayFile, "%s %d", txt, height);
    grayFile >> txt >> (*width);
    grayFile >> txt >> (*height);
    cout << "width:" << (*width) << " height" << (*height) << endl;

    /// Allocate space to store the gray scale information
    sizeInBytes = (*width) * (*height) * sizeof(int);
    grayVals = (int*)malloc(sizeInBytes);
//    debuggray = malloc(sizeInBytes);

    /// read in the gray scale values
//    fscanf(grayFile, "%s [", txt);
    pGrayVals = grayVals;
    for(i=0; i < (*height); i++)
    {
        for(j=0; j < (*width) - 1; j++)
        {
//            fscanf(grayFile, " %d,", pGrayVals++);
        }
//        fscanf(grayFile, " %d;", pGrayVals++);
    }
    grayFile.close();

}

int main(int argc, char *argv[])
{
    int * grayVals;   /// malloced in readText deleted here
    int width, height;

    if (argc <= 1)
        cout << "what text file?" << endl;
    else
        cout << "Processing: " << argv[1] << endl;

    readText(grayVals, argv[1], &width, &height);

    cout << "grayVals:" << width * height << endl;

    delete grayVals;
    return 0;
}



