#include<iostream>
#include<fstream>
#include <vector>
#include "dnn_findJ.h"

using namespace std;


vector<double> delta_v_mult(const vector<double> &delta,const vector<double> &v)
{
    vector<double> ans;
    //cout << "I'm in delta multiplication " << delta.size()<< " " <<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<delta.size();j++)
        {
            ans.push_back(delta[j]*v[i]);
        }
    }
    return ans;

}

vector<double> tran_w_delta_v_mult(const vector< vector<double> > &w,const vector<double> &delta,const vector<double> &v)
{
    double sum=0;
    vector<double> res1;
    vector<double> ans;
    //cout<< "w values check "<< w[0].size()<<" " <<w.size() <<endl;
    for(int c=0;c<w[0].size();c++)
    {
        for(int r=0;r<w.size();r++)
        {
            sum+=w[r][c]*delta[r];
        }

        res1.push_back(sum);
        sum=0;
    }

    for(int i=0;i<v.size();i++)
    {
        sum=0;
        sum=res1[i]*v[i]*(1-v[i]);
        ans.push_back(sum);
    }

    return ans;
}

void  dnn_findJ(vector< vector<double> > &J,const NET &NN,const vector<OUTS> &v,int ctr)
{
    //cout << "I'm in findj" << endl;
    int end= NN.Nn.size()-1; //Actual end considering array starts from 0

    J.resize(NN.Nn[end]);
    vector<double> temp1,temp2;

    for(int iy=0;iy<NN.Nn[end];iy++)
    {
        vector<double> delta(NN.Nn[end],0.0);  //delta.resize(NN.Nn[end]);
        delta[iy]= v[end].v[iy]*(1-v[end].v[iy]);
        J[iy]=delta_v_mult(delta,v[end-1].v);

        for(int i=NN.Nn.size()-3;i>=0;i--) //-1 for #layers,-1 for last layer,-1 for zero index start
        {
            temp1.resize(v[i+1].v.size());
            temp1=tran_w_delta_v_mult(NN.W[i+1].w,delta,v[i+1].v);

            temp2.resize((temp1.size())*(v[i].v.size()));
            temp2=delta_v_mult(temp1,v[i].v);

            J[iy].insert(J[iy].begin(),temp2.begin(), temp2.end());

            delta.clear();
            delta.resize(temp1.size());
            delta=temp1;
            temp1.clear();
            temp2.clear();

        }

    }

}
