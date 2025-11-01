#include <stdlib.h>
#include <stdio.h>
#include "PilhaDinamica.h"

Pilha *cria_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

int vazia(Pilha *p) {
    if (p->topo == NULL ) 
        return 1;
    return 0;
}

void push_pilha(Pilha *p, Vacina x){
    Nodo_pilha *novo = (Nodo_pilha *)malloc(sizeof(Nodo_pilha));
    novo->vacina = x;
    novo->prox = p->topo;

    p->topo = novo;
}

Vacina pop_pilha(Pilha *p){
    Vacina x = p->topo->vacina;
    Nodo_pilha *aux = (Nodo_pilha *)malloc(sizeof(Nodo_pilha));
    p->topo = p->topo->prox;
    free(aux);

    return x;
}

int tamanho_pilha(Pilha *p){
    if (p->topo == NULL) return 0;
    int tam = 0;
    while (p->topo != NULL){
        p->topo = p->topo->prox;
        tam++;
    }
    return tam;
}