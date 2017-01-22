#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "dnn_init.h"

using namespace std;

NET dnn_init(vector<int> Nn)
{
    //cout<< "dnn_init is working" << endl;
    /*
    int Nnarr[] = {3,4,5,1};
    vector<int> Nn (Nnarr, Nnarr + sizeof(Nnarr) / sizeof(Nnarr[0]) );
    */

    //srand((unsigned)time(NULL));
    srand(1);

    NET NN;
    NN.Nn = Nn;

    int nlayers=NN.Nn.size();
    NN.W.resize(nlayers-1);
    for(int p=0;p<nlayers-1;p++)
    {
        int h=NN.Nn[p+1];int l=NN.Nn[p];
        vector < vector < double > > w(h,vector<double>(l));
        for(int i=0;i<h;i++)
        for(int j=0;j<l;j++)
            w[i][j]=-1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2)));
        //float r3 = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));

        NN.W[p].w=w;
    }

    for(int i=0;i<NN.Nn.size()-1;i++)
    {
        NN.Nw.push_back(NN.Nn[i]*NN.Nn[i+1]);
    }



    // Testing by printing out
    /*
    for(int p=0;p<nlayers-1;p++)
    {
        int h=NN.Nn[p+1];int l=NN.Nn[p];
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<l;j++)
            {
                cout<<NN.W[p].w[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"layer complete"<<endl;

    }
    */
    return NN;

}
