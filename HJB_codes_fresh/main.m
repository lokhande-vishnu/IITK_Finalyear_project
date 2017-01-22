function main()

global denZero
denZero = 1e-4;
params.K = 20000; % max epochs
params.tolErr = 0.001;
params.maxErr = 0.2;
Nhidden = [500]; % No. of hidden layers in NN
Ntrial = 1; % No. of trials, each with different initialization of NN weights

%% DATA
data.in = [];
data.out = [];
for x1=0:2 % train for each x
    for x2=0:2
        yd = mod(x1+x2,2);
        data.in = [data.in; [x1+.1,x2+.1]];
        data.out = [data.out; yd];
    end
end
data.out(data.out==1) = 0.9;
data.out(data.out==0) = 0.1;

%% Algorithms Selection
FLAG_BP = 0;
FLAG_BP_online = 0;
FLAG_LF = 0;
FLAG_LF_online = 0;
FLAG_LM = 0;
FLAG_LM_online = 0;
FLAG_optimal = 0;
FLAG_optimalLM = 0;
FLAG_optimal_online = 1;

%% Parameter Setting
if FLAG_BP
    Niter_converge_BP = zeros(Ntrial,1); save_t_BP = zeros(Ntrial,1); ctr_BP = zeros(Ntrial,1);
    eta_BP = .5;
end
if FLAG_BP_online
    Niter_converge_BP_online = zeros(Ntrial,1); save_t_BP_online = zeros(Ntrial,1); ctr_BP_online = zeros(Ntrial,1);
    eta_BP_online = .5;
end
if FLAG_LF
    Niter_converge_LF = zeros(Ntrial,1); save_t_LF = zeros(Ntrial,1); ctr_LF = zeros(Ntrial,1);
    mu_LF = .05;
end
if FLAG_LF_online
    Niter_converge_LF_online = zeros(Ntrial,1); save_t_LF_online = zeros(Ntrial,1); ctr_LF_online = zeros(Ntrial,1);
    mu_LF_online = .2;
end
if FLAG_LM
    Niter_converge_LM = zeros(Ntrial,1); save_t_LM = zeros(Ntrial,1); ctr_LM = zeros(Ntrial,1);
    mu_LM = .001; beta_LM = 10;
end
if FLAG_LM_online
    Niter_converge_LM_online = zeros(Ntrial,1); save_t_LM_online = zeros(Ntrial,1); ctr_LM_online = zeros(Ntrial,1);
    mu_LM_online = .001; beta_LM_online = 10;
end
if FLAG_optimal
    Niter_converge_optimal = zeros(Ntrial,1); save_t_optimal = zeros(Ntrial,1); ctr_optimal = zeros(Ntrial,1);
    r_optimal=1;
end
if FLAG_optimalLM
    Niter_converge_optimalLM = zeros(Ntrial,1); save_t_optimalLM = zeros(Ntrial,1); ctr_optimalLM = zeros(Ntrial,1);
    mu_optimalLM = .001; beta_optimalLM = 10;
end
if FLAG_optimal_online
    Niter_converge_optimal_online = zeros(Ntrial,1); save_t_optimal_online = zeros(Ntrial,1); ctr_optimal_online = zeros(Ntrial,1);
    r_optimal_online=100;
end

%% Use same initial weights for NN
    for itrial=1:Ntrial
        NN_init(itrial) = dnn_init([size(data.in,2)+1,Nhidden,size(data.out,2)]);
    end

%% Optimization
fprintf('Trial no.: ');
for itrial=1:Ntrial
    NN = NN_init(itrial);
    fprintf('%d ',itrial);
    
    % BP
    if FLAG_BP
        [NN_BP,err_BP,ctr_BP(itrial)] = train_BP(NN,data,params,eta_BP);
        
        Niter_converge_BP(itrial) = fn_analyzeTrial(NN_BP,data,err_BP,params.maxErr);
    end
    
    % BP online
    if FLAG_BP_online
        
        [NN_BP_online,err_BP_online,ctr_BP_online(itrial)] = train_BP_online(NN,data,params,eta_BP_online);
        
        Niter_converge_BP_online(itrial) = fn_analyzeTrial(NN_BP_online,data,err_BP_online,params.maxErr);
    end
    
    % LF
    if FLAG_LF
        
        [NN_LF,err_LF,ctr_LF(itrial)] = train_LF(NN,data,params,mu_LF);
        
        Niter_converge_LF(itrial) = fn_analyzeTrial(NN_LF,data,err_LF,params.maxErr);
    end
    
    % LF online
    if FLAG_LF_online
        
        [NN_LF_online,err_LF_online,ctr_LF_online(itrial)] = train_LF_online(NN,data,params,mu_LF_online);
        
        Niter_converge_LF_online(itrial) = fn_analyzeTrial(NN_LF_online,data,err_LF_online,params.maxErr);
    end
    
    % LM
    if FLAG_LM
        
        [NN_LM,err_LM,ctr_LM(itrial)] = train_LM(NN,data,params,mu_LM,beta_LM);
        
        Niter_converge_LM(itrial) = fn_analyzeTrial(NN_LM,data,err_LM,params.maxErr);
    end
    
    % LM Online
    if FLAG_LM_online    
        
        [NN_LM_online,err_LM_online,ctr_LM_online(itrial)] = train_LM_online(NN,data,params,mu_LM_online,beta_LM_online);
        
        Niter_converge_LM_online(itrial) = fn_analyzeTrial(NN_LM_online,data,err_LM_online,params.maxErr);
    end
    
    % Optimal
    if FLAG_optimal
        
        [NN_optimal,err_optimal,ctr_optimal(itrial)] = train_optimal(NN,data,params,r_optimal);
        
        Niter_converge_optimal(itrial) = fn_analyzeTrial(NN_optimal,data,err_optimal,params.maxErr);
    end
    
    % OptimalLM
    if FLAG_optimalLM
        
        [NN_optimalLM,err_optimalLM,ctr_optimalLM(itrial)] = train_optimalLMR(NN,data,params,mu_optimalLM,beta_optimalLM);
        
        Niter_converge_optimalLM(itrial) = fn_analyzeTrial(NN_optimalLM,data,err_optimalLM,params.maxErr);
    end
    
    % Optimal Online
    if FLAG_optimal_online
        
        [NN_optimal_online,err_optimal_online,ctr_optimal_online(itrial)] = train_optimal_online(NN,data,params,r_optimal_online);
        
        Niter_converge_optimal_online(itrial) = fn_analyzeTrial(NN_optimal_online,data,err_optimal_online,params.maxErr);
    end
    
    if mod(itrial,20)==0, fprintf('\n'); end;
end

%% Results
fprintf('\n NN architecture:');
disp(NN.Nn);
if FLAG_BP
    fprintf('For BP algorithm:------------------ eta = %2.2f \n',eta_BP);
    ind_convg = find(ctr_BP<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_BP(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_BP(ind_convg)))
end
if FLAG_BP_online
    fprintf('For BP Online algorithm:------------------ eta = %2.2f \n',eta_BP_online);
    ind_convg = find(ctr_BP_online<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_BP_online(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_BP_online(ind_convg)))
end
if FLAG_LF
    fprintf('For LF algorithm:------------------ mu = %2.2f \n',mu_LF);
    ind_convg = find(ctr_LF<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_LF(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_LF(ind_convg)))
end
if FLAG_LF_online
    fprintf('For LF Online algorithm:------------------ mu = %2.2f \n',mu_LF_online);
    ind_convg = find(ctr_LF_online<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_LF_online(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_LF_online(ind_convg)))
end
if FLAG_LM
    fprintf('For LM algorithm:------------------ mu = %2.3f, beta = %2.2f \n',mu_LM,beta_LM);
    ind_convg = find(ctr_LM<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_LM(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.4f s \n',mean(save_t_LM(ind_convg)))
end
if FLAG_LM_online
    fprintf('For LM Online algorithm:------------------ mu = %2.3f, beta = %2.2f \n',mu_LM_online,beta_LM_online);
    ind_convg = find(ctr_LM_online<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_LM_online(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_LM_online(ind_convg)))
end
if FLAG_optimal
    fprintf('For OPTIMAL algorithm:--------------- r = %2.2f \n',r_optimal);
    ind_convg = find(ctr_optimal<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_optimal(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_optimal(ind_convg)))
end
if FLAG_optimalLM
    fprintf('For OPTIMAL-LM algorithm:--------------- mu = %2.3f, beta = %2.2f \n',mu_optimalLM,beta_optimalLM);
    ind_convg = find(ctr_optimalLM<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_optimalLM(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.4f s \n',mean(save_t_optimalLM(ind_convg)))
end
if FLAG_optimal_online
    fprintf('For OPTIMAL Online algorithm:--------------- r = %2.2f \n',r_optimal_online);
    ind_convg = find(ctr_optimal_online<params.K);
    fprintf('No. of converging trials = %d \n',sum(ind_convg>0));
    temp = ctr_optimal_online(ind_convg);
    fprintf('No. of iterations: mean = %2.2f \t std = %2.2f \t min = %d \t max = %d \n', ...
        mean(temp),std(temp),min(temp),max(temp));
    fprintf('Mean CPU time per converging trial = %2.2f s \n',mean(save_t_optimal_online(ind_convg)))
end



end