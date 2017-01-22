function [er, bad] = dnn_test(NN, x, y)
    
    for i=1:size(x,1)
        v = dnn_fwd(NN,[x(i,:),1]');
        [~, labels(i,1)] = max(v(end).v',[],2);       
    end
    [~, expected] = max(y,[],2);

    bad = find(labels ~= expected);    
    er = numel(bad)*100 / size(x, 1);
end