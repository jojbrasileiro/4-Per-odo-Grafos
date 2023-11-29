
1. Entrada
A entrada para seu programa é um grafo bidirecional com pesos, cujos
vértices representam um conjunto de cidades em que a empresa deve fazer
entregas, as arestas indicam as rodovias que ligam as cidades, cuja distância é
dada pelos pesos das arestas.
Seu programa deverá ler:
	● m e n, que representam, respectivamente, a quantidade de vértices e de
arestas do grafo.
	● As próximas n linhas contém três inteiros a,b,w cada uma, representando a
ligação da cidade a para a cidade b, com peso w.
	● c, a cidade na qual Pedro reside.
Observação: A empresa sempre está localizada na cidade 0

2. Saída
A saída esperada do seu programa é:
	● “PADRAO”, caso a entrega padrão seja a de menor custo, ou
“VIP”, caso a entrega vip seja a de menor custo, ou
“NDA”, caso ambas as entregas tenham o mesmo custo
	● O custo da entrega mais vantajosa para Pedro