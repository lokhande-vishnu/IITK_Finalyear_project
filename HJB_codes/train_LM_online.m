function [NN,save_err,ctr] = train_LM_online(NN,data,params,mu,beta)
global denZero;

% r=5;

% TRAINING
Np = size(data.in,1); % No. of patterns
ctr = 0;
save_err = zeros(params.K,1);
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
        while true
            u = inv(J'*J + mu*eye(sum(NN.Nw))) * J' * e ; % u is Nw x 1
            NN1 = dnn_updateW(NN,u);
            v = dnn_fwd(NN1,x);
            err = (yd - v(end).v)'*(yd - v(end).v);
            if err < e'*e
                mu = mu/beta;
                NN = NN1;
                break;
            else
                mu = mu*beta;
            end
        end

        % Error
        errcum = errcum + err;
    end
    % Terminate
    ctr = ctr+1;
    save_err(ctr) = errcum;
    if errcum < params.maxErr || ctr>params.K
        break;
    end
    
end

