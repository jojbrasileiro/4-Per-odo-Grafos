//JOAO BRASILEIRO MOREIRA DA SILVA
//NUSP: 13672957

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

//funçao responsavel por verificar se o verticepossui uma saida antes de entrar
int tem_saida(int j,int  v, int matriz[][v]){
    int count = 0;
    for(int i = 0; i < v; i++){
        if(matriz[j][i] == 1){
            count++;
        }
        if(matriz[i][j] == 1){
            count++;
        }
    }
    if(count > 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    FILE *file;
    char file_name[50];
    char resposta[30];
    char temp[3];
    int v, a, count = 0;

//abre o arquivo
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    if(file != NULL){
//le os vertices e arestas e guarda eles em uma matriz
        fscanf(file, "%d %d", &v, &a);

        int matriz[v][v];
        memset( matriz, 0, v*v*sizeof(int) );

        int v1, v2;

        for(int i = 0; i < a; i ++){
            fscanf(file, "%d %d", &v1, &v2);
            matriz[v1][v2] = 1;
        }

//passa por cada vertice verificando o menor vertice adjacente com pelo menos uma saida
        v1 = 0;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < v; j++){
                if(tem_saida(j, v, matriz) == 1 || i == a - 1){
                    if(matriz[v1][j] == 1 || matriz[j][v1] == 1){
                        snprintf(temp, 10, "%d", j);
                        strcat(resposta,temp);
                        strcat(resposta," ");
                        count++;
                        matriz[v1][j] = 0;
                        matriz[j][v1] = 0;
                        v1 = j;
                        break;
                    }
                }
            }
        }

//verifica se o grafo é um circuito euleriano e printa a resposta
        if(count != a || resposta[strlen(resposta) - 2] != '0'){
                    printf("Não");
                }else{
                    printf("Sim\n");
                    printf("0 ");
                    for(int i = 0; i < strlen(resposta); i++){
                        printf("%c", resposta[i]);
                    }
                }
    }
    fclose(file);
}