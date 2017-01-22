function errcum = test(NN,data)

errcum = 0;
for i=1:size(data.in,1)
    x = [data.in(i,:),1]';
    yd = data.out(i,:)';
    v = dnn_fwd(NN,x);
    err = norm(yd-v(end).v);
     fprintf('yd = %2.1f  y = %2.1f  err = %2.1f \n',[yd,v(end).v,err]);
    errcum = errcum + err;
end