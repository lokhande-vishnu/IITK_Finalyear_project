function Niter_converge = fn_analyzeTrial(NN,data,err,maxErr)

% Epochs required for convergence
temp = find(err<maxErr,1);
if ~isempty(temp), 
    Niter_converge = temp; 
else
    Niter_converge = length(err)+1;
end

return;

err = test(NN,data);
if err<maxErr, 
    flag_converge=1; 
else
    flag_converge=0; 
end