#ifndef TRAIN_BP_ONLINE_H_INCLUDED
#define TRAIN_BP_ONLINE_H_INCLUDED
#include "allstructs.h"

std::vector<double> train_BP_online(NET &NN,std::vector<DATA> &data,PRM params,double eta);

#endif // TRAIN_BP_ONLINE_H_INCLUDED
