function dnn_plot(data,NNtemp)
global denZero

figure(4); hold on
for i=1:size(data.in,1)
    if data.out(i,:) == data.out(1,:), plot(data.in(i,1),data.in(i,2),'ro');
    else plot(data.in(i,1),data.in(i,2),'k*'); end
end
x1 = linspace(-1,3,5);
for h=1:size(NNtemp.W(1).w,1)
    plot(x1,(-NNtemp.W(1).w(h,1)*x1-NNtemp.W(1).w(h,3))/(NNtemp.W(1).w(h,2)+denZero));
end
axis([-1 3 -1 3]); grid on