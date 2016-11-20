
%Carrega os arquivo
load resultado.txt;

t = resultado(:,1);
%Ordena os resultados para ficar mais explicito
y =  sort(resultado(:,4));
y1 =  sort(resultado(:,5));
y2 =  sort(resultado(:,6));
y3 = sort (resultado(:,7));
%Plota as funções do tempo no gráfico com as devidas cores
plot(t,y,'k', t,y1,'r', t,y2,'g', t,y3,'m');grid
%mdcEuclidesIterativo
%mdcEuclidesRecursivo
%mdcIterativo
%mdcRecursivo
%Indicação dos eixos 
xlabel('entradas', 'Color', 'b')
ylabel('Tempos', 'Color', 'b')

%Seta o titulo do gráfico
title('Gráficos de tempo dos algoritmos')

text(5,0.00000065,'Euclides Iterativo','Color','k')
text(5,0.0000006,'Euclides Recursivo','Color','r')
text(5,0.00000055,'Stain Iterativo','Color','g')
text(5,0.0000005,'Stain Recursivo','Color','m')
