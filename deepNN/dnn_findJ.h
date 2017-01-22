#ifndef DNN_FINDJ_H_INCLUDED
#define DNN_FINDJ_H_INCLUDED
#include "allstructs.h"

void  dnn_findJ(std::vector< std::vector<double> > &J,const NET &NN,const std::vector<OUTS> &v,int ctr);

#endif // DNN_FINDJ_H_INCLUDED
