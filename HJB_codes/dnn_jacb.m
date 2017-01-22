function [Jp] = dnn_jacb(NN,v)

clear J;
delta = v(end).v .* (1 - v(end).v);
delta2=reshape(diag(delta),[],1);
Jtemp = delta2 * v(end-1).v' ;
Jp = reshape(Jtemp',[],10)';
Jp=fliplr(Jp);
for i = length(NN.Nn)-2:-1:1
    nrep= NN.Nn(end);
    t1= kron(eye(nrep),NN.W(i+1).w');
    t2= repmat(v(i+1).v,nrep,1);t3= repmat((1 - v(i+1).v),nrep,1);
    delta2=(t1*delta2).*t2.*t3;
    Jtemp = delta2 * v(i).v'; % NN.Nn(i+1) x NN.Nn(i)
    Jtemp = fliplr(reshape(Jtemp',[],10)');
    Jp=[Jp,Jtemp];
end

Jp=fliplr(Jp);

end