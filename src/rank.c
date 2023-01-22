#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include "cobra.h"

void ler_rank(Cobra* snake){
    FILE* rank = fopen("assets/rank.txt", "r");
    int contador = 0;
    while(1){
        if(feof(rank)){
            break;
        }
        fscanf(rank, "%d - %s", &snake->parametros.pontos_rank[contador], snake->parametros.nomes_rank[contador]);
        contador++;
    }
    fclose(rank);
}

void ordenar_rank(Cobra* snake){
    int contador = 5;
    for(int i = 0; i < 5; i++){
        if(snake->parametros.pontos >= snake->parametros.pontos_rank[i]){
            for(int j = 4; j >= i; j--){
                strcpy(snake->parametros.nomes_rank[contador], snake->parametros.nomes_rank[j]);
                snake->parametros.pontos_rank[contador] = snake->parametros.pontos_rank[j];
                contador--;
            }
            snake->parametros.pontos_rank[i] = snake->parametros.pontos;
            strcpy(snake->parametros.nomes_rank[i], snake->parametros.nome);
            break;
        }
    }
}

void escrever_rank(Cobra* snake){
    int contador = 0;
    FILE* rank_escrita = fopen("assets/rank.txt", "w");
    while(contador < 5){
        fprintf(rank_escrita, "%d - %s\n", snake->parametros.pontos_rank[contador], snake->parametros.nomes_rank[contador]);
        contador++;
    }
    fclose(rank_escrita);
}