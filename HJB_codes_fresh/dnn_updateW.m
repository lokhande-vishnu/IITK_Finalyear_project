function NN = dnn_updateW(NN,dW)

temp = 0;
for ilayer=1:length(NN.W)
    NN.W(ilayer).w = NN.W(ilayer).w + reshape(dW(temp+1:temp+NN.Nw(ilayer)),[NN.Nn(ilayer+1),NN.Nn(ilayer)]);
    temp = temp+NN.Nw(ilayer);
end
