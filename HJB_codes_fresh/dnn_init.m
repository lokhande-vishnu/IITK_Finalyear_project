function NN = dnn_init(Nn)
% NN.W(1,ilayer).w(i2,i1) : 1x(Nlayer-1) struct
% NN.Nn(ilayer) = no. of neurons in each layer
% NN.Nw(ilayer) : 1x(Nlayer-1) vector

NN = struct; % Neural network with input-hidden-output layers 
NN.Nn = Nn;
for i=1:length(Nn)-1
    NN.W(i).w = 2*rand(Nn(i+1),Nn(i))-1;%0.05*ones(Nn(i+1),Nn(i));
end
NN.Nw = Nn(1:end-1) .* Nn(2:end) ;
