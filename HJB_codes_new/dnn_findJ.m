function [JNyxNw,v] = dnn_findJ(NN,x)

clear J;
%% J(iy,ilayer).j(ilayer+1,ilayer)
v = dnn_fwd(NN,x);
for iy = 1:NN.Nn(end) % outputs of NN
    delta = zeros(NN.Nn(end),1); % No x 1
    delta(iy) = v(end).v(iy) * (1 - v(end).v(iy)); 
    J(iy,length(NN.Nn)-1).j = delta * v(end-1).v' ;
    for i = length(NN.Nn)-2:-1:1
        delta = ( NN.W(i+1).w'*delta ) .* v(i+1).v .* (1 - v(i+1).v); % NN.Nn(i+1) x 1
        J(iy,i).j = delta * v(i).v'; % NN.Nn(i+1) x NN.Nn(i)
    end
end

%% J: Ny x Nw
JNyxNw = zeros([NN.Nn(end),sum(NN.Nw)]);
for iy = 1:size(J,1)
    temp = 0;
    for ilayer=1:size(J,2)
        JNyxNw(iy,temp+1:temp+NN.Nw(ilayer)) = J(iy,ilayer).j(:)';
        temp = temp+NN.Nw(ilayer);
    end
end


% [y,h,v] = dnn_sigy_fwd(NN,x);
% J_Woh = zeros(1,NN.Nh);
% for hh=1:NN.Nh
%     J_Woh(1,hh) = y*(1-y)*v(hh);
% end
% J_Whi = zeros(NN.Nh,NN.Ni);
% for ii=1:NN.Ni
%     for hh=1:NN.Nh
%         J_Whi(hh,ii) = y*(1-y)* NN.Woh(1,hh) * v(hh)*(1-v(hh)) * x(ii);
%     end
% end