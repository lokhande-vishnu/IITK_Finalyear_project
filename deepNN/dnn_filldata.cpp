#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include <string>
#include "dnn_filldata.h"

using namespace std;

int ReverseInt ( int i)
{
    unsigned  char CH1, CH2, CH3, ch4;
    CH1 = i & 255 ;
    CH2 = (i >> 8 ) & 255 ;
    CH3 = (i >> 16 ) & 255 ;
    ch4 = (i >> 24 ) & 255 ;
     return (( int ) CH1 << 24 ) + (( int ) CH2 << 16 ) + (( int ) CH3 << 8 ) + ch4;
}

void toonezero(vector<DATA> &data,int i,double temp)
{
    data[i].out.resize(10);
   switch((int)temp)
   {
       case 0 :
           data[i].out[0]=1;
          break;
        case 1 :
           data[i].out[1]=1;
          break;
        case 2 :
           data[i].out[2]=1;
          break;
        case 3 :
           data[i].out[3]=1;
          break;
        case 4 :
           data[i].out[4]=1;
          break;
        case 5 :
           data[i].out[5]=1;
          break;
        case 6 :
           data[i].out[6]=1;
          break;
        case 7 :
           data[i].out[7]=1;
          break;
        case 8 :
           data[i].out[8]=1;
          break;
        case 9 :
           data[i].out[9]=1;
          break;
   }

}


void read_Mnist(string filename, vector<DATA> &data,int NumberOfImages)
{
    ifstream file(filename, ios::binary);
    data.resize(NumberOfImages);
    if (file.is_open())
    {
        int magic_number=0;
        int number_of_images=0;
        int n_rows=0;
        int n_cols=0;
        file.read((char*)&magic_number,sizeof(magic_number));
        magic_number= ReverseInt(magic_number);
        file.read((char*)&number_of_images,sizeof(number_of_images));
        number_of_images= ReverseInt(number_of_images);
        file.read((char*)&n_rows,sizeof(n_rows));
        n_rows= ReverseInt(n_rows);
        file.read((char*)&n_cols,sizeof(n_cols));
        n_cols= ReverseInt(n_cols);

        for(int i=0;i<NumberOfImages;++i)
        {
            data[i].in.resize(n_rows*n_cols);

            for(int r=0;r<n_rows;++r)
            {
                for(int c=0;c<n_cols;++c)
                {
                    unsigned char temp=0;
                    file.read((char*)&temp,sizeof(temp));
                    data[i].in[(n_rows*r)+c]= ((double)temp)/255;

                }
            }
        }
    }
}


void read_Mnist_Label(string filename, vector<DATA> &data,int NumberOfImages)
{
    ifstream file (filename, ios :: binary);
    if (file.is_open ())
    {
        int magic_number = 0 ;
        int NUMBER_OF_IMAGES = 0 ;
        int n_rows = 0 ;
        int n_cols = 0 ;
        file.read (( char *) & magic_number, sizeof (magic_number));
        magic_number = ReverseInt (magic_number);
        file.read (( char *) & NUMBER_OF_IMAGES, sizeof (NUMBER_OF_IMAGES));
        NUMBER_OF_IMAGES = ReverseInt (NUMBER_OF_IMAGES);

        for ( int i = 0 ; i <NumberOfImages; ++ i)
        {
            unsigned  char temp = 0 ;
            file.read (( char *) & temp, sizeof (temp));
            toonezero(data,i,(double)temp);

        }
    }
}


void dnn_filldata(vector<DATA> &data,bool train)
{
    /*MNIST data*/

    if(train)
    {

        int NumberOfImages=60000;
        string filename = "C:\\train-images.idx3-ubyte";
        read_Mnist (filename, data,NumberOfImages);
        filename = "C:\\train-labels.idx1-ubyte";
        read_Mnist_Label (filename, data,NumberOfImages);
        cout << data.size () << endl;
        cout << data[0].out.size() << endl;
        cout << data[0].in.size() << endl;
    }
    else
    {

        int NumberOfImages=10000;
        string filename = "C:\\t10k-images.idx3-ubyte";
        read_Mnist (filename, data,NumberOfImages);
        filename = "C:\\t10k-labels.idx1-ubyte";
        read_Mnist_Label (filename, data,NumberOfImages);
        cout << data.size () << endl;
        cout << data[0].out.size() << endl;
        cout << data[0].in.size() << endl;
    }

}



    /* XOR DATA */
    /*
    if(train)
    {
        data.resize(9);
        int i=0;
        for(int x1=0;x1<=2;x1++) // train for each x
        {
            for (int x2=0;x2<=2;x2++)
            {
                double yd;
                if (fmod(x1+x2,2)==0)
                {
                    data[i].out.push_back(0);
                    data[i].out.push_back(1);
                }
                else
                {
                    data[i].out.push_back(1);
                    data[i].out.push_back(0);
                }
                data[i].in.push_back(x1+0.1);
                data[i].in.push_back(x2+0.1);
                i++;
            }
        }
    }
    else
    {
        cout<<"Testing data is being printed"<<endl;
        data.resize(9);
        int i=0;
        for(int x1=0;x1<=2;x1++) // train for each x
        {
            for (int x2=0;x2<=2;x2++)
            {
                double yd;
                if (fmod(x1+x2,2)==0) {yd=0.1;}
                else {yd=0.9;}
                data[i].in.push_back(x1+0.1);
                data[i].in.push_back(x2+0.1);

                data[i].out.push_back(yd);

                i++;
            }
        }
    }
*/

