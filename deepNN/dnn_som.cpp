#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include "dnn_som.h"

using namespace std;

int niter=5;
double eta=0.8;

template<class T>
void comp(vector<T> v1, vector<T> v2)
{
	if(v1.size() != v2.size())
    {
		cout << "vectors not the same size\n";
		exit(1);
	}
}

template<class T>
double euclidean(vector<T> v1, vector<T> v2)
{
	comp(v1, v2);
	T diff, sum;

	diff = v1[0] - v2[0];
	sum = diff * diff;

	for (unsigned int i=1; i < v1.size(); i++){
		diff = v1[i] - v2[i];
		sum += diff * diff;
	}
	return sqrt(double(sum));
}



void dnn_som(vector<DATA> &data, int n_units)
{
	/* Training */
	int cur_iter=1;
	srand(2);
	vector< vector<double> > W(n_units, vector<double>(data[0].in.size()));;
	for(int i=0;i<W.size();i++)
    for(int j=0;j<W[0].size();j++)
        W[i][j]=0 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(1-0)));

	do
	{
	    cout<<"cur_iter"<<cur_iter<<endl;
	    cur_iter++;
	    eta-=0.2;

	    for(int i=0;i<data.size();i++)
        {
            /*Winner computation*/
            double dmin=euclidean(data[i].in, W[0]);
            int winner=0;
            for(int j=1;j<n_units;j++)
            {
                double d = euclidean(data[i].in, W[j]);
                if(d<dmin){dmin=d;winner=j;}
            }

            /* Winner update */
            for(int k=0;k<W[winner].size();k++)
                 W[winner][k]+= eta*(data[i].in[k]-W[winner][k]);
        }
	}while(cur_iter<niter);

	/* Transformation */
	for(int i=0;i<data.size();i++)
    {
        vector<double> x(n_units);
        for(int j=0;j<n_units;j++)
            x[j]=euclidean(data[i].in,W[j]);

        data[i].in.clear();
        data[i].in=x;
    }
}
