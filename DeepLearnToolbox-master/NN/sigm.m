function X = sigm(P)%#codegens
    X = 1./(1+exp(-P));
end