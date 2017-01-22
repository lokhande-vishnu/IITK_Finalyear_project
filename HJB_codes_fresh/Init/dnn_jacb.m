function [JNyxNw] = dnn_jacb(NN,v)

clear J;
%% J(iy,ilayer).j(ilayer+1,ilayer)
JNyxNw = zeros([NN.Nn(end),sum(NN.Nw)]);
for iy = 1:NN.Nn(end) % outputs of NN
    temp = 0;
    
    delta = v(end).v .* (1 - v(end).v);
    delta2=reshape(diag(delta),[],1);
    Jtemp = delta2 * v(end-1).v' ;
    Jp = reshape(Jtemp',[],10)';
    Jp=fliplr(Jp);
    JNyxNw(iy,temp+1:temp+NN.Nw(length(NN.Nn)-1))=fliplr(J(iy,length(NN.Nn)-1).j(:)');
    temp = temp+NN.Nw(length(NN.Nn)-1);
    for i = length(NN.Nn)-2:-1:1
        delta = ( NN.W(i+1).w'*delta ) .* v(i+1).v .* (1 - v(i+1).v); % NN.Nn(i+1) x 1
        J(iy,i).j = delta * v(i).v'; % NN.Nn(i+1) x NN.Nn(i)
        JNyxNw(iy,temp+1:temp+NN.Nw(i)) = fliplr(J(iy,i).j(:)');
        temp = temp+NN.Nw(i);
    end
end
JNyxNw=fliplr(JNyxNw);
end