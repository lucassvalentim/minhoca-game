#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "menu.h"
#include "cobra.h"
#include "rank.h"

int contador = 0;
int xt = 30;
int yt = 430;
void rodar_menu(Cobra *snake){
    //desenha fundo
    cor(255, 255, 255);
    desenha_retangulo(0, 0, 640, 480);
    desenha_imagem(320, 200, "assets/professorlinguica.jpg");
    //desenha o titulo e os menus
    cor(0,100,0);
    fonte("assets/04B_03__.TTF", 60); 
    desenha_texto(80, 80, "MINHOCA");
    fonte("assets/04B_03__.TTF", 30);
    desenha_texto(80, 430, "PLAY");
    desenha_texto(350, 430, "TO SEE RANKING");
    //desenha ponteiro de escolha
    if(contador > 10){
        fonte("assets/04B_03__.TTF", 35);
        desenha_texto(xt, yt, "->");
        if(contador == 20)contador=0;
    }
    contador++;
    //verifica opção de escolha
    if(tecla_acabou_de_ser_apertada(ESQUERDA)){
        if(xt != 300) xt=300;
        else xt = 30;
        contador = 0;
    }
    if(tecla_acabou_de_ser_apertada(DIREITA)){
        if(xt != 30) xt = 30;
        else xt = 300;
        contador = 0;
    };
    if(tecla_acabou_de_ser_apertada(ENTER)){
        if(xt == 30){
            snake->parametros.tela = 2;
            contador = 0;
        }
        if(xt == 300){
            snake->parametros.tela = 5;
            contador = 0;
        }
    }
}

int xt1 = 190;
int yt1 = 150;
void rodar_segundo_menu(Cobra *snake){
    //desenha fundo
    cor(255, 255, 255);
    desenha_retangulo(0, 0, 640, 480);
    //opcao voltar para o menu
    cor(0,0,0);
    fonte("assets/04B_03__.TTF", 20); 
    desenha_texto(80, 430, "S para voltar ao menu");
    if(tecla_acabou_de_ser_apertada('S')) snake->parametros.tela = 1;
    //desenha o titulo
    cor(0,100,0);
    fonte("assets/04B_03__.TTF", 30); 
    desenha_texto(90, 50, "Escolha a dificuldade do jogo:");
    //desenha as opções de dificuldade
    fonte("assets/04B_03__.TTF", 30);
    desenha_texto(250, 150, "FACIL");
    desenha_texto(250, 250, "MEDIO");
    desenha_texto(250, 350, "DIFICIL");
    //desenha ponteiro de escolha
    if(contador > 10){
        fonte("assets/04B_03__.TTF", 35);
        desenha_texto(xt1, yt1, "->");
        if(contador == 20)contador=0;
    }
    contador++;
    //verifica as opções escolhidas
    if(tecla_acabou_de_ser_apertada(BAIXO)){
        if(yt1 == 150) yt1 = 250;
        else if(yt1 == 250) yt1 = 350;
        else if(yt1 == 350) yt1 = 150;
        contador = 0;
    }
    if(tecla_acabou_de_ser_apertada(CIMA)){
        if(yt1 == 150) yt1 = 350;
        else if(yt1 == 250) yt1 = 150;
        else if(yt1 == 350) yt1 = 250;
        contador=0;
    };
    if(tecla_acabou_de_ser_apertada(ESPACO)){
        if(yt1 == 150) snake->velocidade = 7;
        else if(yt1 == 250) snake->velocidade = 5;
        else if(yt1 == 350) snake->velocidade = 3; 
        snake->parametros.tela = 3;
    }
}

void pedir_nome(Cobra *snake){
    int c = 3;
    system("cls");
    printf("Digite seu apelido: ");
    scanf("%s", snake->parametros.nome);
    printf("Comecando em:\n");
    //contagem regressiva para começar
    while(c > 0){
        printf("%d\n", c);
        c--;
        sleep(1);
    }
    if(c==0) printf("Bom jogo %s\n", snake->parametros.nome);
    snake->parametros.tela = 0;
}

void reseta_tudo(Cobra* snake){
    snake->coordenadas[0][0] = 330;
    snake->coordenadas[0][1] = 180;
    snake->tamanho_cobra = 1;
    snake->vx = 10;
    snake->vy = 0;
    snake->fps = 0;
    snake->parametros.mcx = macax();
    snake->parametros.mcy = macay();
    snake->parametros.pontos = 0;
    snake->parametros.v_rank = 1;
}

char points_mostrar_rank[5][100];
void mostrar_rank(Cobra* snake){
    //desenha fundo
    cor(255, 255, 255);
    desenha_retangulo(0, 0, 640, 480);
    //opção voltar para o menu
    cor(0,0,0);
    fonte("assets/04B_03__.TTF", 20); 
    desenha_texto(80, 400, "S para voltar ao menu");
    if(tecla_acabou_de_ser_apertada('S')) snake->parametros.tela = 1;
    //desenha titulo
    cor(0,100,0);
    fonte("assets/04B_03__.TTF", 30); 
    desenha_texto(150, 70, "RANKING DOS 5 MELHORES");
    //escrever o rank na tela
    int y_rank = 150;
    for(int i = 0; i < 5; i++){
        sprintf(points_mostrar_rank[i], "%d", snake->parametros.pontos_rank[i]);
        fonte("assets/04B_03__.TTF", 20);
        desenha_texto(100, y_rank, points_mostrar_rank[i]);
        desenha_texto(130, y_rank, "-");
        desenha_texto(150, y_rank, snake->parametros.nomes_rank[i]);
        y_rank += 30;
    }
}

void game_over(Cobra* snake){
    //rodar apenas uma vez o ordernar rank
    if(snake->parametros.v_rank == 1){
        toca_som("assets/gameover.mp3");
        ordenar_rank(snake);
        snake->parametros.v_rank = 0;
    }
    //desenha fundo
    cor(255, 255, 255);
    desenha_retangulo(0, 0, 640, 480);
    //desenha o titulo e os menus
    cor(0,100,0);
    fonte("assets/04B_03__.TTF", 50); 
    desenha_texto(180, 210, "GAME OVER!");
    fonte("assets/04B_03__.TTF", 25);
    cor(0,0,0);
    desenha_texto(62, 270, "ENTER para voltar ao menu");
    desenha_texto(62, 310, "SPACE para voltar ao jogo");
    desenha_texto(62, 350, "ESC para sair do jogo");
    //verifica as opções de escolha
    if(tecla_acabou_de_ser_apertada(ESPACO)){
        reseta_tudo(snake);
        snake->parametros.tela = 0;
    }
    if(tecla_acabou_de_ser_apertada(ENTER)){
        reseta_tudo(snake);
        snake->parametros.tela = 1;
    }
}