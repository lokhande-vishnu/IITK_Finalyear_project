#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
#include "dnn_test.h"
#include "dnn_fwd.h"

using namespace std;

vector<double> dnn_test(const NET &NN, vector<DATA> &test)
{

    cout<<"I'm in test"<<endl;
    double err_cum=0,ratio_cum=0;
    vector<double> x,yd,err;
    vector<OUTS> v;
    for(int i=0;i<test.size();i++)
    {
        x = test[i].in;
        x.push_back(1); // Constanta Neuron
        yd = test[i].out;

        dnn_fwd(v,NN,x);

        double accum = 0.0;
        for(int ind=0;ind<yd.size();ind++)
        {
            accum+=(yd[ind]-v[NN.Nn.size()-1].v[ind])*(yd[ind]-v[NN.Nn.size()-1].v[ind]);
        }
        err.push_back(sqrt(accum));
        err_cum+=err[i];

        int n1= distance( yd.begin() , max_element(yd.begin(), yd.end()) );
        int n2= distance( v[NN.Nn.size()-1].v.begin() , max_element(v[NN.Nn.size()-1].v.begin(), v[NN.Nn.size()-1].v.end()) );
        ratio_cum+=(double) 100*(n1==n2)/test.size();


        x.clear();yd.clear();v.clear();

    }
    cout<<"err_cum"<<err_cum<<endl;
    cout<<"ratio_cum"<<ratio_cum<<endl;

    x.push_back(err_cum);
    x.push_back(ratio_cum);

    return x;

}
