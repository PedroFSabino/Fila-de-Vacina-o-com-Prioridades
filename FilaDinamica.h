#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[100];
    int idade;
    char comorbidade[2];
}Pessoa;

typedef struct Nodo_fila {
    Pessoa pessoa;
    struct Nodo_fila *prox;
}Nodo_fila;

typedef struct {
    Nodo_fila *inicio;
    Nodo_fila *fim;
}Fila;

Fila *cria_fila();

int Vazia(Fila *f);

void push_fila(Fila *f, Pessoa x);

Pessoa pop_fila(Fila *f);

int tamanho_fila(Fila *f);

#endif