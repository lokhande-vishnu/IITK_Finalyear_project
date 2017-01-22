#include<iostream>
#include<fstream>
#include<vector>
#include "dnn_som.h"
#include "dnn_filldata.h"
#include "dnn_init.h"
#include "train_BP_online.h"
#include "train_optimal_online.h"
#include "dnn_test.h"
#include "allstructs.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{

    /* Algorithms Selection */
    int FLAG_BP_online = 1;
    int FLAG_optimal_online = 1;

    /* Stopping parameters */
	PRM prm;
	prm.K = 15; // max epochs
	prm.tolErr = 0.001;
	prm.maxErr = 0.5;
	int Nhid[] = {15};
    vector<int> Nhidden (Nhid, Nhid + sizeof(Nhid) / sizeof(Nhid[0]) );
	int Ntrial = 1; // No. of trials, each with different initialization of NN weights


	/* Data generation */
	vector<DATA> data;
	bool train=1;
	dnn_filldata(data,train);


    /* SOM Encoder */
    int n_units=4*4;
    //dnn_som(data,n_units);


    /* Parameter Setting */
    int Niter_converge_BP_online[Ntrial]; int save_t_BP_online[Ntrial]; int ctr_BP_online[Ntrial];
    double eta_BP_online = 0.5;
    int Niter_converge_optimal_online[Ntrial]; int save_t_optimal_online[Ntrial]; int ctr_optimal_online[Ntrial];
    int r_optimal_online=100;

    /*Initial weights for NN*/
    NET NN_init[Ntrial];
    NET NN_bp,NN_optimal;
    for(int itrial=0;itrial<Ntrial;itrial++)
    {
        Nhidden.insert(Nhidden.begin(),1+data[0].in.size());
        Nhidden.push_back(data[0].out.size());
        NN_init[itrial]=dnn_init(Nhidden);

    }


    /*Optimization*/
    ofstream myfile;
    myfile.open ("results.txt");
    vector<double> x;
    for(int itrial=0;itrial<Ntrial;itrial++)
    {
        //cout<< "Trial no."<<itrial<<endl;
        NN_bp = NN_init[itrial];
        NN_optimal = NN_init[itrial];


        myfile << "Training using Back Propagation\n";
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        x=train_BP_online(NN_bp,data,prm,eta_BP_online);
        myfile << "No of epochs before convergence "<<x[2]<<"\n";
        x.clear(); x=dnn_test(NN_bp,data);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
        cout <<"Time for back prop "<<duration<<endl;
        myfile << "Duration "<<duration<<"seconds\n";
        myfile << "Training: RMS error "<<x[0]<<"\n";
        myfile << "Training: Percent accuracy "<<x[1]<<"%\n";


        myfile << "\nTraining using HJB\n";
        t1 = high_resolution_clock::now();
        x=train_optimal_online(NN_optimal,data,prm,r_optimal_online);
        myfile << "No of epochs before convergence "<<x[2]<<"\n";
        x.clear(); x=dnn_test(NN_optimal,data);
        t2 = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
        cout <<"Time for HJB "<<duration<<endl;
        myfile << "Duration "<<duration<<"seconds\n";
        myfile << "Training: RMS error "<<x[0]<<"\n";
        myfile << "Training: Percent accuracy "<<x[1]<<"%\n";
    }

    /*Testing*/
    /*Test data generation*/
    vector<DATA> test;double err_cum;
	dnn_filldata(test,!train);
	/* SOM Encoder */
	//dnn_som(test,n_units);

	myfile << "\nTesting using BP\n";
	x=dnn_test(NN_bp,test);
	myfile << "Testing: RMS error "<<x[0]<<"\n";
    myfile << "Testing: Percent Correct error "<<x[1]<<"%\n";

	myfile << "\nTesting using HJB\n";
	x=dnn_test(NN_optimal,test);
    myfile << "Testing: RMS error "<<x[0]<<"\n";
    myfile << "Testing: Percent Correct error "<<x[1]<<"%\n";

    myfile.close();
    return 0;
}



    //Testing
    /*
    cout<<"after update" << endl;
    int nlayers=NN.Nn.size();
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
/*
     cout<<"after update" << endl;
        for(int p=0;p<v.size();p++)
        {
            for(int i=0;i<v[p].v.size();i++)
            {
                cout<<v[p].v[i]<<" ";
            }
            cout<<endl;
            cout<<"layer complete"<<endl;
        }
*/



//if(i==data.size()-1)
//{
//
//
//cout<<endl;
// cout<<"After forward NN value" << endl;
//    int nlayers=NN.Nn.size();
//    for(int p=0;p<nlayers-1;p++)
//    {
//        int h=NN.Nn[p+1];int l=NN.Nn[p];
//        for(int i=0;i<h;i++)
//        {
//            for(int j=0;j<l;j++)
//            {
//                cout<<NN.W[p].w[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<"layer complete"<<endl;
//
//    }
//     cout<<"after forward v value" << endl;
//        for(int p=0;p<v.size();p++)
//        {
//            for(int i=0;i<v[p].v.size();i++)
//            {
//                cout<<v[p].v[i]<<" ";
//            }
//            cout<<endl;
//            cout<<"layer complete"<<endl;
//        }
//
//    cout<<"after forward x value"<<endl;
//    for(int p=0;p<x.size();p++)
//    {
//        cout<<x[p];
//    }
//    cout<<endl;
//}
//




