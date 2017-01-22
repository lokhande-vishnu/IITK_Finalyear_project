function [NN,save_err,ctr] = train_LF_online(NN,data,params,mu)
global denZero;

% mu=.2;
dt=1;

% TRAINING
Np = size(data.in,1); % No. of patterns
ctr = 0;
save_err = zeros(params.K,1);
err = zeros(Np,1);
% save_u = zeros(Nw,params.K);
while true
    errcum = 0;
    for i=1:Np
        x = [data.in(i,:),1]';
        yd = data.out(i,:)';
        % Finding Jacobian
        [J,v] = dnn_findJ(NN,x);
        e = yd - v(end).v;
        
        % Update weights
        temp = J'*e;
        u = mu * (e'*e)/(temp'*temp+denZero) * temp; % u is Nw x 1
        NN = dnn_updateW(NN,dt*u);

        % Error
        v = dnn_fwd(NN,x);
        err(i) = norm(yd-v(end).v);        
    end

    % Terminate
    ctr = ctr+1;
    save_err(ctr) = errcum;
    if all(err < params.maxErr) || ctr>params.K
        break;
    end
    
end

