#include <stdlib.h>
#include <stdio.h>
#include "PilhaEstatica.h"

Pilha *cria_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int vazia(Pilha *p) {
    if (p->topo == -1) return 1;

    return 0;
}

void push_pilha(Pilha *p, Vacina x) {
    p->topo++;
    p->v[p->topo] = x; 
}

Vacina pop_pilha(Pilha *p) {
    Vacina t = p->v[p->topo]; 
    p->topo--;
    return t;
}

int tamanho_pilha(Pilha *p){
    if (p->topo == -1) return 0;
    int tam = 0;
    while (p->topo != -1){
        p->topo--;
        tam++;
    }
    return tam;
}