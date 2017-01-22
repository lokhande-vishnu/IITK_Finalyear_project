function [NN,save_err,ctr] = train_BP_online(NN,data,params,eta)
% Back propagation in Batch mode
global denZero 

% eta = 1;

% TRAINING
Np = size(data.in,1); % No. of patterns
ctr = 0;
save_err = zeros(params.K,1);
err = zeros(Np,1);
% save_u = zeros(Nw,params.K);
while true
    for i=1:Np
        x = [data.in(i,:),1]';
        yd = data.out(i,:)';
        % Finding Jacobian
        [J,v] = dnn_findJ(NN,x);
        
%        J2=dnn_Jac(NN,v);
        %J3=dnn_jacb(NN,v);
        
        e = yd - v(end).v;
        
        % Update weights
        u = eta * J' * e ; % u is Nw x 1
        NN = dnn_updateW(NN,u);

        % Error
        v = dnn_fwd(NN,x);
        err(i) = norm(yd-v(end).v);
    end
    % Terminate
    ctr = ctr+1;
    save_err(ctr) = sum(err);
    if all(err < params.maxErr) || ctr>params.K
        break;
    end
    
end


