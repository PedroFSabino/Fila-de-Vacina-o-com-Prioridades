#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Vacina{
      char marca[20];
      int lote;
}Vacina;

typedef struct {
    Vacina v[50];
    int topo; 
} Pilha;

Pilha *cria_pilha(); 

int vazia(Pilha *p); 

void push_pilha(Pilha *p, Vacina x) ;

Vacina pop_pilha(Pilha *p);

int tamanho_pilha(Pilha *p);

#endif