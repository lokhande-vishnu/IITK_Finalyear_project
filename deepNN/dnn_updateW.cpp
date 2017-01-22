#include<iostream>
#include<fstream>
#include<vector>
#include "dnn_updateW.h"

using namespace std;

void dnn_updateW(NET &NN,const vector<double> &dw)
{

    //cout<< "update is working" <<NN.W.size()<<endl;
    //cout<< "dimensions" <<rnum<<" "<<cnum<<endl;
    int index=0;
    for(int il=0;il<NN.W.size();il++)
    {
        int rnum=NN.W[il].w.size();
        int cnum=NN.W[il].w[0].size();


        for(int c=0;c<cnum;c++)
        {
            for(int r=0;r<rnum;r++)
            {
                NN.W[il].w[r][c]+=dw[index];
                index++;
            }
        }

    }
}
