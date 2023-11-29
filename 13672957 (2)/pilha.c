#include "pilha.h"

void liberar_No(NO *no) {
    if(no->prox != NULL){
        liberar_No(no->prox);
    }
    free(no);
}

void liberar_Pilha(PILHA *pilha) {
    if(pilha->topo != NULL){
        liberar_No(pilha->topo);
    }
    free(pilha);
}

PILHA *criar_Pilha() {
    PILHA *pilha = malloc(sizeof(PILHA));
    pilha->tamanho = 0;
    pilha->topo = NULL;
    return pilha;
}

void empilhar(PILHA *pilha, NO *no){
    if(pilha->topo != NULL){
        NO *aux = pilha->topo;
	    pilha->topo = no;
        pilha->topo->prox = aux;
    }else{
        pilha->topo = no;
    }
}

int desempilhar(PILHA *pilha){
        NO *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        return aux->chave;
}

NO *cria_No(int atual){
    NO *no = malloc(sizeof(NO));
    no->chave = atual;
    no->prox = NULL;
    return no;
}

void print_No(NO *no){
    printf("%d, ", no->chave);
    if(no->prox != NULL){
        print_No(no->prox);
    }
}

void print_pilha(PILHA *pilha){
    if(pilha->topo != NULL){
        print_No(pilha->topo);
    }
}