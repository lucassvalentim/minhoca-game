#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "cobra.h"
#include "menu.h"
#include "rank.h"


int main() {

    abre_janela(640, 480);
    //variaveis da cobra
    Cobra* snake = (Cobra*)malloc(sizeof(Cobra));
    snake->coordenadas = criar_coordenada(330, 180);
    snake->parametros.tela = 1;
    reseta_tudo(snake);
    ler_rank(snake);

    toca_som_em_loop("assets/teladejogo.mp3");
    
    while ( janela_esta_aberta ()){
        if(tecla_pressionada(ESC)){
            escrever_rank(snake);
            break;
        }
        if(snake->parametros.tela == 0)jogar(snake); // tela da gameplay
        if(snake->parametros.tela == 1)rodar_menu(snake); // menu inicial
        if(snake->parametros.tela == 2)rodar_segundo_menu(snake); //escolhe a dificuldade do jogo     
        if(snake->parametros.tela == 3)pedir_nome(snake); // tela onde será pedido o nome do jogador
        if(snake->parametros.tela == 4)game_over(snake); //tela de fim de jogo
        if(snake->parametros.tela == 5)mostrar_rank(snake); // tela do rank
    }

    desalocar_coordenada(snake);
    free(snake);
    fecha_janela();
}