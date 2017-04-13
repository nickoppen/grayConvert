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

    grayFile >> txt >> (*width);
    grayFile >> txt >> (*height);
    cout << "width:" << (*width) << " height" << (*height) << endl;

    /// Allocate space to store the gray scale information
    sizeInBytes = (*width) * (*height) * sizeof(int);
    grayVals = (int*)malloc(sizeInBytes);
    int g2D[*width][*height];

    /// read in the gray scale values
//    size_t startPos = txt.find('[', 0);     /// find the opening [
    size_t startPos = 8;            /// skip over "image ["
    for(i=0; i < (*height); i++)
    {
        getline(grayFile, txt, ';');
//        cout << txt << endl;
        for(j=0; j < (*width) - 1; j++)
        {
            cout << txt.substr(startPos, 10);
//            g2D[i][j] = stoi(txt, &startPos);
            sizeInBytes = stoi(txt, &startPos);  //  testing
//            cout << g2D[i][j] << "\t";
            cout << sizeInBytes << "\t";
        }
        cout << endl;
        //getline(grayFile, txt);
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



