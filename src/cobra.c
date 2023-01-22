#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "cobra.h"
#include "menu.h"

//variaveis globais
char points[100];
void jogar(Cobra* snake){

    desenhar_tela(snake);
    desenha_cobra(snake);

    //funcoes sobre a cobra
    troca_direcao(snake);
    crecer_cobra(snake);
    colisao(snake);

    //conta e mostra os pontos na tela
    sprintf(points, "%d", snake->parametros.pontos);
    cor(BRANCO);
    fonte("assets/04B_03__.TTF", 60);
    if(snake->parametros.pontos > 20) desenha_texto(290, 450, points);
    else desenha_texto(300, 450, points);

    //fps
    if(snake->fps == snake->velocidade){
        mover_cobra(snake);
        snake->fps = 0;
    }
    snake->fps++;
}

void desenhar_tela(Cobra* snake){
    int x = 20;
    int y = 30;
    int largura = 600;
    int altura = 2;
    //fundo do jogo
    cor(85,107,60);
    desenha_retangulo(0, 0, 640, 480);
    cor(85,107,47);
    desenha_retangulo(x, y, largura, altura+350);

    //desenha a maca
    desenha_imagem(snake->parametros.mcx+5, snake->parametros.mcy+5, "assets/macagif.gif");

    //borda limitada para a cobra
    cor(0, 0, 0);      
    desenha_retangulo(x, y, largura, altura);
    desenha_retangulo(x, y+350, largura, altura);
    desenha_retangulo(x, y, largura-598, altura+350);
    desenha_retangulo(x+600, y, largura-598, altura+350);
   
    //desenhando as bordas das bordas da area limitada
    desenha_retangulo(x+2, y-2, largura, altura);
    desenha_retangulo(x, y+352, largura, altura);
    desenha_retangulo(x-2, y, largura-598, altura+350);
    desenha_retangulo(x+602, y, largura-598, altura+350);
}
 
int macax(){
    srand( (unsigned)time(NULL) );
    int p = rand() % 610;
    while ( p % 10 != 0 || p < 25)
    {
        p = rand() % 610;
    }
    return p;
}
 
int macay(){
    srand( (unsigned)time(NULL) );
    int q = rand() % 330;;
    while ( q % 10 != 0 || q < 32)
    {
        q = rand() % 330;
    }
    return q;
}
 
int** criar_coordenada(int x, int y){
    int** coord = (int**)malloc(3100*sizeof(int*));
    for(int i = 0; i < 3100; i++){
        coord[i] = (int*)malloc(sizeof(int));
    } 
    coord[0][0] = x;
    coord[0][1] = y;
    return coord;
}

void desalocar_coordenada(Cobra* snake){
    for(int i = 0; i < 3100; i++){
        free(snake->coordenadas[i]);
    }
    free(snake->coordenadas);
}

void troca_direcao(Cobra* snake){
    if( tecla_acabou_de_ser_apertada(CIMA) ){
        if(snake->tamanho_cobra>1){
            if(snake->vy == 0 && snake->coordenadas[0][1] == snake->coordenadas[1][1]){
                snake->vx=0;
                snake->vy=-VELOCIDADE;
            }
        }else{
            if(snake->vx != 0){
                snake->vx=0;
                snake->vy=-VELOCIDADE;
            }
        }
    }
    if( tecla_acabou_de_ser_apertada(ESQUERDA)){
        if(snake->tamanho_cobra>1){
            if(snake->vx == 0 && snake->coordenadas[0][0] == snake->coordenadas[1][0]){
                snake->vx=-VELOCIDADE;
                snake->vy=0;
            }
        }else{
            if(snake->vy != 0){
                snake->vx=-VELOCIDADE;
                snake->vy=0;
            }
        }
    }
    if( tecla_acabou_de_ser_apertada(BAIXO)){
        if(snake->tamanho_cobra>1){
            if(snake->vy == 0 && snake->coordenadas[0][1] == snake->coordenadas[1][1]){
                snake->vx=0;
                snake->vy=VELOCIDADE;
            }
        }else{
            if(snake->vx != 0){
                snake->vx=0;
                snake->vy=VELOCIDADE;
            }
        }
    }
    if( tecla_acabou_de_ser_apertada(DIREITA)){
        if(snake->tamanho_cobra>1){
            if(snake->vx == 0 && snake->coordenadas[0][0] == snake->coordenadas[1][0]){
                snake->vx=VELOCIDADE;
                snake->vy=0;
            }
        }else{
            if(snake->vy != 0){
                snake->vx=VELOCIDADE;
                snake->vy=0;
            }
        }
    }
}

void desenha_cobra(Cobra* snake){
    preenchimento(true);
    cor(0,100,0);
    for(int i = 0; i < snake->tamanho_cobra; i++){
        desenha_imagem(snake->coordenadas[i][0]+5, snake->coordenadas[i][1]+5, "assets/cobra2.png");
    }
}

void mover_cobra(Cobra* snake){
    int c = snake->tamanho_cobra-2;

    for (int i = snake->tamanho_cobra-1; i > 0; i--){
        snake->coordenadas[i][0] = snake->coordenadas[c][0];
        snake->coordenadas[i][1] = snake->coordenadas[c][1];
        c--;
    }
    snake->coordenadas[0][0]+=snake->vx;
    snake->coordenadas[0][1]+=snake->vy;  
}
 
void crecer_cobra(Cobra* snake){
    if(snake->coordenadas[0][0]==snake->parametros.mcx && snake->coordenadas[0][1]==snake->parametros.mcy){
            snake->parametros.mcx = macax();
            snake->parametros.mcy = macay();
            snake->coordenadas[snake->tamanho_cobra][0] = snake->coordenadas[snake->tamanho_cobra-1][0];
            snake->coordenadas[snake->tamanho_cobra][1] = snake->coordenadas[snake->tamanho_cobra-1][1];
            (snake->tamanho_cobra)++;
            (snake->parametros.pontos)++;
            recomeca_som("assets/coleta.wav");
    }
}

int colisao(Cobra* snake){
    int verificador = 0;
    if(snake->tamanho_cobra != 2){
        for (int i = 1; i < snake->tamanho_cobra; i++){
            if ((snake->coordenadas[0][0] == snake->coordenadas[i][0]) && (snake->coordenadas[0][1] == snake->coordenadas[i][1])){
                    snake->parametros.tela = 4;
            }
        }
    }
    if(snake->coordenadas[0][0] == 620 || snake->coordenadas[0][0] == 10 || snake->coordenadas[0][1] == 380 || snake->coordenadas[0][1] == 20 || verificador){
            snake->parametros.tela = 4;
    }
    return 0;
}