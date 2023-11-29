/*
Trabalho feito pelos alunos
Mateus Bernal Leffeck - 13673318 - Turma B (Segunda)
Marina Figueiredo - - Turma A (Terça)
João Brasileiro - 13672957 - Turma A (Terça)
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INT_MAX 9999999

//funçao para gerar a matriz de adjacências
void cria_matriz(int v, int a, int matriz[v][v]){
        memset(matriz, 0, v*v*sizeof(int));

        int v1, v2, p;

        for(int i = 0; i < a; i ++){
            scanf("%d %d %d", &v1, &v2, &p);
            matriz[v1][v2] = p;
        }
}

//funçao que checa se todos os nos ja foram vizitados
int todos_vizitados(int *vizitados, int v){
    for(int i = 0; i < v; i++){
        if(vizitados[i] == 0){
            return 0;
        }
    }
    return 1;
}

//Funçao que executa o Algoritmo_de_Dijkstra
void Algoritmo_de_Dijkstra(int v, int a, int matriz[v][v], int *distancias, int *predecessor){

    //vetor que armazena os vertices ja vizitados
    int vizitados[v];
    memset(vizitados, 0, v*sizeof(int));

    //define todas as distancias como infinitas e zera adistancia da origem
    memset(distancias, INT_MAX, v*sizeof(int));
    distancias[0] = 0;

    //enquanto todos os vertices nao forem vizitados faz:
    while(1){

        int vertice;
        int menor_distancia = INT_MAX;

        //acha o vertice com a menor distancia que ainda nao foi vizitado
        for(int i = 0; i < v; i++){
            if(vizitados[i] == 0 && distancias[i] < menor_distancia){
                vertice = i;
                menor_distancia = distancias[i];
            }
        }

        //marca como vizitado
        vizitados[vertice] = 1;

        //atualiza a distancia e predecessores de todos os vertices
        for(int i = 0; i < v; i++){
            //caso a distancia do vertice atual mais o peso da aresta seja menor que a distancia conhecida:
            if ((distancias[vertice] + matriz[vertice][i]) <= distancias[i] && matriz[vertice][i] != 0){
                //atualiza a distancia conhecida
                distancias[i] = distancias[vertice] + matriz[vertice][i];
                //caso ja tenha sido encontado outro predecessor possivel:
                if(predecessor[i] != -1){
                    //se adistancia entre o novo for menor que a do antigo troca
                    if(matriz[vertice][i] < matriz[predecessor[i]][i]){
                        predecessor[i] = vertice;
                    }
                //se nao apenas verifica se é a origem e define o predecessor
                }else if(i != 0){
                    predecessor[i] = vertice;
                }
            }
        }

        //condiçao de parada
        if(todos_vizitados(vizitados, v) == 1){
            break;
        }
    }
}

//calcula a entrega padrao
int soma_padrao(int v, int *predecessor, int matriz[v][v]){
    int soma = 0;

    for(int i = 0; i < v; i++){
        soma += matriz[predecessor[i]][i];
    }

    return soma;
}

//calcula a entrega vip
int soma_vip(int v, int destino, int *distancias, int *predecessor){
    int i = destino;
    int count = 1;

    while(predecessor[i] != 0){
        count ++;
        i = predecessor[i];
    }
    count++;

    return (v - count) * distancias[destino];
}


int main(){

    //recebe os valores e cria a matriz
    int v, a;

    scanf("%d %d", &v, &a);

    int matriz[v][v];
    cria_matriz(v, a, matriz);

    int destino;
    scanf("%d", &destino); 

    int distancias[v];

    int predecessor[v];
    memset(predecessor, -1, v*sizeof(int));
    predecessor[0] = 0;

    //roda o algoritmo e calcula as entregas
    Algoritmo_de_Dijkstra(v, a, matriz, distancias, predecessor);

    int entrega_padrao = soma_padrao(v, predecessor, matriz);

    int entrega_vip = soma_vip(v, destino, distancias, predecessor);

    //printa a resposta
    if(entrega_padrao < entrega_vip){
        printf("PADRAO \n%d", entrega_padrao);
    }else if(entrega_padrao > entrega_vip){
        printf("VIP \n%d", entrega_vip);
    }else{
        printf("NDA \n%d", entrega_padrao);
    }
}
