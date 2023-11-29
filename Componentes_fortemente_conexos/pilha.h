#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VIZITADO 1
#define NAO_VIZITADO 0

typedef struct no NO;

typedef struct no{
        int chave;
        NO *prox;
    }NO;

typedef struct pilha{
    NO *topo;
    int tamanho;
    }PILHA;

void liberar_No(NO *no);

void liberar_Pilha(PILHA *pilha);

PILHA *criar_Pilha();

void empilhar(PILHA *pilha, NO *no);

int desempilhar(PILHA *pilha);

NO *cria_No(int atual);

void print_No(NO *no);

void print_pilha(PILHA *pilha);