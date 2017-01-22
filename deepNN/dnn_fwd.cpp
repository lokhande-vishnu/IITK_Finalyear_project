#include<iostream>
#include<fstream>
#include<vector>
#include <math.h>
#include "dnn_fwd.h"

using namespace std;

vector<double> matrixmultiply(const vector< vector<double> > &W, vector<double> v)
{
    double sum=0;
    vector<double> ans;

    for (int k = 0; k < W.size(); ++k)
    {
        for (int i = 0; i < v.size(); ++i)
           sum += W[k][i]*v[i];

        sum = 1/(1+exp(-sum));
        ans.push_back(sum);
        sum=0;
    }

    /*
    cout<<"printing the product"<<endl;
    for (int i = 0; i < ans.size(); ++i)
         cout<< ans[i] <<endl;
    */
    return ans;
}

void dnn_fwd(vector<OUTS> &v,const NET &NN, vector<double> &x )
{
    //cout<< "fwd is working" <<endl;
    int nlayers=NN.Nn.size();
    v.resize(nlayers);


    v[0].v=x;
    for(int i=1;i<NN.Nn.size();i++)
    {
        v[i].v=matrixmultiply(NN.W[i-1].w,v[i-1].v);
    }

}
