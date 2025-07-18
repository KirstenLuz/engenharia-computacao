function [I] = Trapezios (a,b,dx,y)
% esta fun��o calcula a integra��o usando M�todo dos Trap�zios
% sa�da I= integra��o
% dados a=valor inicial de x (x0)
% dados b= valor final de x (xn)
% dados dx= incremento (intervalo)
% dados y= vetor coluna contendo o valor da fun��o a ser integrado
[nf,nc]=size(y);
if (nf<2)
   disp ('o n�mero de pontos � menor que 2');
   abort;
end
n=nf;
I=y(1);
for i=2:n-1
   I=I+2*y(i);
end
I=I+y(n);
I=I*(dx/2);
end %Fim da fun��o trapezios

