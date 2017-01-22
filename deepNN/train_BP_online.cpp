#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "train_BP_online.h"
#include "dnn_fwd.h"
#include "dnn_findJ.h"
#include "dnn_updateW.h"

using namespace std;

void eta_tranJ_e_mult(vector<double> &u,double eta,const vector< vector<double> >  &J,vector<double> e)
{
    double sum=0;
    for(int c=0;c<J[0].size();c++)
    {
        for(int r=0;r<J.size();r++)
        {
            sum+=J[r][c]*e[r];
        }

        u.push_back(eta*sum);
        sum=0;
    }
}

// In reference parameter passing, left denote the inputs while right are the outputs
vector<double> train_BP_online(NET &NN,vector<DATA> &data,PRM params,double eta)
{
    cout << "I'm in BP" << data.size()<<endl;

    int ctr=0;int ctr_err=0;
    vector<double> x,yd,err,e,u,save_err,save_ratio;
    vector< vector<double> > J;
    vector<OUTS> v;

    while(ctr<params.K && ctr_err<data.size())
    {

        save_err.push_back(0.0);save_ratio.push_back(0.0);ctr_err=0;
        for(int i=0;i<data.size();i++)
        {

            cout<<i<<endl;
            x = data[i].in;
            x.push_back(1); // Constanta Neuron
            yd = data[i].out;


            dnn_fwd(v,NN,x);

            dnn_findJ(J,NN,v,ctr);

            /* e = yd - v(end).v */
            for(int dif=0;dif<yd.size();dif++)
                e.push_back(yd[dif]-v[NN.Nn.size()-1].v[dif]);

            /* Update the weights */
            eta_tranJ_e_mult(u,eta,J,e);

            dnn_updateW(NN,u);

            /* error calculation */
            dnn_fwd(v,NN,x);

            double accum = 0.0;
            for(int ind=0;ind<yd.size();ind++)
            {
                accum+=(yd[ind]-v[NN.Nn.size()-1].v[ind])*(yd[ind]-v[NN.Nn.size()-1].v[ind]);
            }
            err.push_back(sqrt(accum));
            save_err[ctr]+=err[i];

            int n1= distance( yd.begin() , max_element(yd.begin(), yd.end()) );
            int n2= distance( v[NN.Nn.size()-1].v.begin() , max_element(v[NN.Nn.size()-1].v.begin(), v[NN.Nn.size()-1].v.end()) );
            save_ratio[ctr]+=(double) 100*(n1==n2)/data.size();

            if(err[i]<params.maxErr)   ++ctr_err;

            x.clear();yd.clear();u.clear();v.clear();e.clear();J.clear();
        }
        cout << "save_err" << save_err[ctr]<<" "<<save_err.size()<<endl;
        cout << "save_ratio" << save_ratio[ctr]<<" "<<save_ratio.size()<<endl;
        ctr=ctr+1;
        err.clear();
    }

    x.push_back(save_err[ctr-1]);
    x.push_back(save_ratio[ctr-1]);
    x.push_back(ctr);
    return x;

}

  /*
    cout<<"Order of u"<<endl;
    for(int fu=0;fu<u.size();fu++)
    {
        cout<<u[fu]<<" ";
    }
    cout<<endl;
    */

