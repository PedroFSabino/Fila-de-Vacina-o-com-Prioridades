#include <stdlib.h>
#include <stdio.h>
#include "FilaEstatica.h"

Fila *cria_fila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
}

int Vazia(Fila *f) {
    if (f->inicio == f->fim) return 1;

    return 0;
}

void push_fila(Fila *f, Pessoa x) {
    f->v[ f->fim ] = x; 
    f->fim = (f->fim+1)%100;
}

Pessoa pop_fila(Fila *f) {
    Pessoa x = f->v[ f->inicio ]; 
    f->inicio = (f->inicio + 1)%100;

    return x;
}

int tamanho_fila(Fila *f){
    if (f->inicio == f->fim) return 0;
    int tam = 0;
    while (f->inicio != f->fim){
        f->inicio++;
        tam++;
    }
    return tam;
}