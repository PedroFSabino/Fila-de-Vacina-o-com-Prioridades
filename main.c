#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FilaEstatica.h"
#include "PilhaEstatica.h"

int main(){
    
    //Criação das pilhas e das filas.
    Pilha *i = cria_pilha(); 
    Pilha *c = cria_pilha();
    Pilha *g = cria_pilha();
    Fila *I = cria_fila();
    Fila *C = cria_fila();
    Fila *G = cria_fila();
    //Variáveis auxiliares do programa.
    char x = 0, fila[20] = {0};
    int qtde = 0;
    //Criação das structs que serão armazenadas nas pilhas e filas.
    Vacina k, aplicada;
    Pessoa p, vacinada;
    
    //Laço de repetição para leitura da entrada do usuário.
    while(x != 'F'){
        //Primeira entrada do loop, que vai determinar o próximo passo do programa.
        scanf("%c", &x);
        //Condição de parada
        if(x == 'F') break;
        //Condição que adiciona vacinas nas pilhas.
        if(x == 'i' || x == 'c' || x == 'g'){
            //Para pilha de idosos.
            if(x == 'i'){
                scanf("%s", &k.marca);
                scanf("%d", &k.lote);
                scanf("%d", &qtde);
                while(qtde > 0){
                    push_pilha(i, k);
                    qtde--;
                }
            }
            //Para pilha de pessoas com comorbidade.
            else if(x == 'c'){
                scanf("%s", &k.marca);
                scanf("%d", &k.lote);
                scanf("%d", &qtde);
                while(qtde > 0){
                    push_pilha(c, k);
                    qtde--;
                }
            }
            //Para pilha do público geral.
            else{
                scanf("%s", &k.marca);
                scanf("%d", &k.lote);
                scanf("%d", &qtde);
                while(qtde > 0){
                    push_pilha(g, k);
                    qtde--;
                }
            }
        }
        //Condição de entrada e saída de pessoas nas filas.
        else{
            //Entrada na fila.
            if(x == '+'){
                scanf("%s", &p.nome);
                scanf("%d", &p.idade);
                scanf("%s", &p.comorbidade);
                //Para fila de idosos.
                if(p.idade >= 60){
                    push_fila(I, p);
                }
                else{
                    //Para fila de pessoas com comorbidade.
                    if (p.comorbidade[0] == 'S'){
                        push_fila(C, p);
                    }
                    //Para fila do público geral.                 
                    else{                
                        push_fila(G, p);
                    }    
                }    
            }
            //Saída da fila.
            if(x == '-'){
                scanf("%s", &fila);
                //Para fila de idosos.
                if(strcmp(fila, "idoso") == 0){
                    //Verificação para ver se a fila ou pilha estão vazias.
                    if(Vazia(I) == 1 || vazia(i) == 1){
                        if(Vazia(I) == 1) printf("Fila vazia.\n");
                        else printf("Sem doses disponiveis.\n");
                    }
                    //Vacinação e remoção de alguém da fila.
                    else{    
                        vacinada = pop_fila(I);
                        aplicada = pop_pilha(i);
                        //Verificação para saber se o idoso tem ou não comorbidade.
                        if(strcmp(vacinada.comorbidade, "S") == 0){
                            printf("%s (%d anos, com comorbidades), vacinado(a) com %s, lote n. %d\n", vacinada.nome, vacinada.idade, aplicada.marca, aplicada.lote);
                        }
                        else
                            printf("%s (%d anos, sem comorbidades), vacinado(a) com %s, lote n. %d\n", vacinada.nome, vacinada.idade, aplicada.marca, aplicada.lote);
                    }                
                }
                //Para fila de pessoas com comorbidade.
                else if(strcmp(fila, "comorbidade") == 0){
                    if(Vazia(C) == 1 || vazia(c) == 1){    
                        if(Vazia(C) == 1) printf("Fila vazia.");
                        else printf("Sem doses disponiveis.");
                    }    
                    else{
                        vacinada = pop_fila(C);
                        aplicada = pop_pilha(c);
                        printf("%s (%d anos, com comorbidades), vacinado(a) com %s, lote n. %d\n", vacinada.nome, vacinada.idade, aplicada.marca, aplicada.lote);
                    }
                }
                //Para fila do público geral.
                else{
                    if(Vazia(G) == 1 || vazia(g) == 1){
                        if(Vazia(G) == 1) printf("Fila vazia.");
                        else printf("Sem doses disponiveis.");
                    }
                    else{    
                        vacinada = pop_fila(G);
                        aplicada = pop_pilha(g);
                        printf("%s (%d anos, sem comorbidades), vacinado(a) com %s, lote n. %d\n", vacinada.nome, vacinada.idade, aplicada.marca, aplicada.lote);
                    }
                }
            }
        }
    }

    //Print das sobras de vacinas e pessoas.
    printf("--\n");
    printf("Restaram %d idoso(s).\n", tamanho_fila(I));
    printf("Restaram %d pessoa(s) com comorbidades.\n", tamanho_fila(C));
    printf("Restaram %d pessoa(s) no geral.\n", tamanho_fila(G));
    printf("--\n");
    printf("Sobraram %d dose(s) para idosos.\n", tamanho_pilha(i));
    printf("Sobraram %d dose(s) para pessoas com comorbidades.\n", tamanho_pilha(c));
    printf("Sobraram %d dose(s) para pessoas no geral.\n", tamanho_pilha(g));

    //Desalocação da memória usada em cada pilha e fila.
    int u = tamanho_fila(I);
    while(u != 0){
        pop_fila(I);
        u--;
    }
    u = tamanho_fila(C);
    while(u != 0){
        pop_fila(C);
        u--;
    }
    u = tamanho_fila(G);
    while(u != 0){
        pop_fila(G);
        u--;
    }  
    u = tamanho_pilha(i);
    while(u != 0){
        pop_pilha(i);
        u--;
    } 
    u = tamanho_pilha(c);
    while(u != 0){
        pop_pilha(c);
        u--;
    } 
    u = tamanho_pilha(g);
    while(u != 0){
        pop_pilha(g);
        u--;
    }
    
    return 0;
} 