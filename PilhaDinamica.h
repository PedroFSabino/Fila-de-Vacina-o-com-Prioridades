#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

#include <stdio.h>

typedef struct Vacina{
    char marca[20];
    int lote;
}Vacina;

typedef struct Nodo_pilha {
    Vacina vacina;
    struct Nodo_pilha *prox; 
} Nodo_pilha;

typedef struct {
    Nodo_pilha *topo;
}Pilha;

Pilha *cria_pilha();

int vazia(Pilha *p) ;

void push_pilha(Pilha *p, Vacina x);

Vacina pop_pilha(Pilha *p);

int tamanho_pilha(Pilha *p);

#endif