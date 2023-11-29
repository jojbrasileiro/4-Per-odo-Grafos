//JOAO BRASILEIRO MOREIRA DA SILVA
//NUSP: 13672957

#include "pilha.h"

void cria_matriz(int v, int a, int matriz[v][v]){
        memset(matriz, 0, v*v*sizeof(int));

        int v1, v2;

        for(int i = 0; i < a; i ++){
            scanf("%d %d", &v1, &v2);
            matriz[v1][v2] = 1;
        }
}

void DFS(int atual, int v, int *vertices, int matriz[v][v], PILHA *pilha){
        vertices[atual] = VIZITADO;
        
        for(int i = 0; i < v; i++){
            if(matriz[atual][i] == 1 && vertices[i] == NAO_VIZITADO){
            DFS(i, v, vertices, matriz, pilha);
            }
        }
        empilhar(pilha, cria_No(atual));
    }

void DFS_ord(int atual, int v, int *vertices, int matriz[v][v], int resposta[v][v], int grupo, int index){
    vertices[atual] = VIZITADO;
    resposta[grupo][index] = atual;                                                            
        
        for(int i = 0; i < v; i++){
            if(matriz[atual][i] == 1 && vertices[i] == NAO_VIZITADO){
            index++;
            DFS_ord(i, v, vertices, matriz, resposta, grupo, index);
            }
        }
}

void ordenar_resposta(int v, int matriz[v][v]){

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                for (int k = 0; k < v - 1; k++) {
                    if (matriz[i][k] > matriz[i][k + 1] && matriz[i][k] != -1 && matriz[i][k + 1] != -1) {
                        int temp = matriz[i][k];
                        matriz[i][k] = matriz[i][k + 1];
                        matriz[i][k + 1] = temp;
                    }
                }
            }
    }


    // Ordenar as colunas
    for (int i = 0; i < v; i++) {

        for (int j = 0; j < v - 1; j++) {
            if (matriz[j][0] > matriz[j + 1][0]) {
                for (int k = 0; k < v; k++) {
                        int temp = matriz[j][k];
                        matriz[j][k] = matriz[j + 1][k];
                        matriz[j + 1][k] = temp;
                }
            }
        }
    }

}

void main(){
    int v, a;
    int atual = 0;

    // cria pilha
    PILHA *pilha;

    pilha = criar_Pilha();

    // cria matriz
    scanf("%d %d", &v, &a);
    int matriz[v][v];
    cria_matriz(v, a, matriz);

    int vertices[v];
    memset(vertices, NAO_VIZITADO, v*sizeof(int));

    // funçao que percorre o grafo e enche a pilha
    for(int i = 0; i < v; i++){
        if(vertices[i] == NAO_VIZITADO){
            DFS(i, v, vertices, matriz, pilha);
        }
    }

    memset(vertices, NAO_VIZITADO, v*sizeof(int));

    int matriz_transp[v][v];
    memset(matriz_transp, 0, v*v*sizeof(int));

    for(int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (matriz[i][j] == 1){
                matriz_transp[j][i] = 1;
            }
        }
    }

    int resposta[v][v];
    memset(resposta, -1, v*v*sizeof(int));
    int grupo = 0;

    while (pilha->topo != NULL){
        atual = desempilhar(pilha);
        if(vertices[atual] == NAO_VIZITADO){
            DFS_ord(atual, v, vertices, matriz_transp, resposta, grupo, 0);
            grupo++;
        }
    }

    printf("%d\n", grupo);

    ordenar_resposta(v, resposta);

    int printou = 0;

    for(int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if(resposta[i][j] != -1){
                printou = 1;
                printf("%d ", resposta[i][j]);
            }
        }
        if(printou == 1){
        printf("\n");
        printou = 0;
        }
    }

    liberar_Pilha(pilha);

}

