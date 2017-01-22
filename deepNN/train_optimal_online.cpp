#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "train_optimal_online.h"
#include "dnn_fwd.h"
#include "dnn_findJ.h"
#include "dnn_updateW.h"
#include <Eigen/Eigenvalues>
#include <Eigen/Dense>
//#pragma warning( disable : 4800 )


using namespace Eigen;
using namespace std;
double denZero=0.0001;

// In reference parameter passing, left denote the inputs while right are the outputs
vector<double> train_optimal_online(NET &NN,vector<DATA> &data,PRM params,int r)
{
    cout << "I'm in train optimal" << data.size()<<endl;

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
            VectorXd e_eig = VectorXd::Map(e.data(), e.size());
            MatrixXd J_eig(J.size(), J[0].size());
            for (int k = 0; k < J.size(); k++)
                J_eig.row(k) = VectorXd::Map(J[k].data(), J[k].size());

            Eigen::EigenSolver<Eigen::MatrixXd> es;
            es.compute(J_eig*J_eig.transpose()/r);
            MatrixXd V = es.eigenvectors().real();
            VectorXd D = es.eigenvalues().real();
            VectorXd D2= (D+denZero*VectorXd::Ones(D.size())).array().pow(-0.5);
            MatrixXd C = V*(D2.asDiagonal())*(V.transpose());
            VectorXd u_eig =(J_eig.transpose())*(C)*(e_eig) / r;
            vector<double> u(u_eig.data(), u_eig.data() + u_eig.size());

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
                        cout<<J_eig.transpose()<<endl;
                       cout<<endl;
                       cout<<C<<endl;
                       cout<<endl;
                       cout<<e_eig<<endl;
                       cout<<endl;
                       cout<<C<<endl;
                       cout<<endl;
                      cout<<u_eig<<endl;
                      cout<<endl;
                      for(int k=0;k<u.size();k++)
                            cout<<u[k]<<" ";
                    cout<<endl;
    */


