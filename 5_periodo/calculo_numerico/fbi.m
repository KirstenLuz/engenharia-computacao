function valor = fbi(x)
    e0 = 8.9e-12;
    q = 2e-5;
    Q = 2e-5;
    a = 1.05;
    F = 1.0783;
    
    valor = (1 / (4 * pi * e0)) * ((q * Q * x) ./ ((x.^2 + a^2).^(3/2))) - F;
end