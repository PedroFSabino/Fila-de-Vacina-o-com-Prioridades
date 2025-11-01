#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
    char comorbidade[2];
}Pessoa;

typedef struct {
    Pessoa v[30];
    int inicio, fim;
} Fila;

Fila *cria_fila();

int Vazia(Fila *f);

void push_fila(Fila *f, Pessoa x);

Pessoa pop_fila(Fila *f);

int tamanho_fila(Fila *f);

#endif