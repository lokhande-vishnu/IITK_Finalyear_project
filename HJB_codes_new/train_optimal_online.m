function [NN,save_err,ctr] = train_optimal_online(NN,data,params,r)
global denZero;

% r=5;
dt=1;

% TRAINING
Np = size(data.in,1); % No. of patterns
ctr = 0;
save_err = zeros(params.K,1);
err = zeros(Np,1);
% save_u = zeros(Nw,params.K);
while true
    for i=1:Np
        
        disp('HJB');disp(i);
        x = [data.in(i,:),1]';
        yd = data.out(i,:)';
        % Finding Jacobian
        %         [J,v] = dnn_findJ(NN,x);
        v = dnn_fwd(NN,x);
        [J] = dnn_Jac(NN,v);
        e = yd - v(end).v;
        
        % Update weights
        [V,D] = eig(J*J'/r);
        C = V*(D+denZero*eye(size(D,1)))^(-0.5) * V';
        u = J' * C * e / r; % u is Nw x 1
        NN = dnn_updateW(NN,dt*u);

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

