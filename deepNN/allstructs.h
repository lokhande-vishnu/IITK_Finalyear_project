#ifndef ALLSTRUCTS_H_INCLUDED
#define ALLSTRUCTS_H_INCLUDED

struct PRM
{
	int K;
	double tolErr;
	double maxErr;
};

/*struct DATA
{
	double in[2];
	double out[1];
};*/

struct DATA
{
    std::vector<double> in;
	std::vector<double> out;
};
struct MAT
{
    std::vector< std::vector<double> > w;
};


struct NET
{
    std::vector<int> Nn;
    std::vector <MAT> W;
    std::vector<int> Nw;
};

struct OUTS
{
    std::vector <double> v;
};

#endif // ALLSTRUCTS_H_INCLUDED
