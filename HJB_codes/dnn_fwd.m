function v = dnn_fwd(NN,x)

v(1).v = x;
for i=2:length(NN.Nn)
    h = NN.W(i-1).w * v(i-1).v;
    v(i).v = 1./(1+exp(-h));
end

