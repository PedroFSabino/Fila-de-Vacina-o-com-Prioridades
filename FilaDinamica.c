#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

Fila *cria_fila(){
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

int Vazia(Fila *f){
    if(f->inicio == NULL)
        return 1;

    return 0;
}

void push_fila(Fila *f, Pessoa x){
    Nodo_fila *novo = (Nodo_fila *)malloc(sizeof(Nodo_fila));
    novo->pessoa = x;
    novo->prox = NULL;
    if(f->fim == NULL){
        f->fim = novo;
        f->inicio = novo;
    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Pessoa pop_fila(Fila *f){
    Nodo_fila *aux = (Nodo_fila *)malloc(sizeof(Nodo_fila));
    Pessoa x = f->inicio->pessoa;
    if(f->fim == f->inicio)
        f->fim = NULL;
    aux = f->inicio;
    f->inicio = f->inicio->prox;

    free(aux);

    return x;
}

int tamanho_fila(Fila *f){
    if (f->inicio == NULL) return 0;
    int tam = 1;
    while (f->inicio != f->fim){
        f->inicio = f->inicio->prox;
        tam++;
    }
    return tam;
}