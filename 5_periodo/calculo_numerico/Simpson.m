function [I] = Simpson(a,b,dx,y)
% esta fun��o calcula a integra��o usando M�todo de Simpson
% sa�da I= integra��o
% dados a=valor inicial de x (x0)
% dados b= valor final de x (xn)
% dados dx= incremento (intervalo)
% dados y= vetor contendo o valor da fun��o a ser integrado
[nf,nc]=size(y);
if(nf<=2)
   disp ('o n�mero de filas � menor que 3');
end
c=(nf-1)/2-floor((nf-1)/2);
if(c~=0) 
   disp ('o numero de intervalos � �mpar');
end
n=nf;
I=y(1);
for i=2:n-1
   resto=i/2 -floor(i/2);
   if (resto==0)
     I=I+4*y(i);
   end
   if(resto~=0)
     I=I+2*y(i);
   end
end
I=(I+y(n))*dx/3;
end
% Fim da fun��o simpson