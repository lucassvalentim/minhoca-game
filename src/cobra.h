typedef struct{
    int v_rank;
    int mcx;
    int mcy;
    int pontos;
    int tela;
    char nome[100];
    int pontos_rank[6];
    char nomes_rank[6][10];
}Parametros;

typedef struct{
    int** coordenadas;
    int tamanho_cobra;
    int vx;
    int vy;
    int fps;
    int velocidade;
    Parametros parametros;
}Cobra;

#define VELOCIDADE 10

int** criar_coordenada(int x, int y);
void troca_direcao(Cobra* snake);
int macax();
int macay();
void mover_cobra(Cobra* snake);
void crecer_cobra(Cobra* snake);
void desenha_cobra(Cobra* snake);
int colisao(Cobra* snake);
void desenhar_tela(Cobra* snake);
void pontos(char *pontos, int p);
void jogar(Cobra* snake);
void desalocar_coordenada(Cobra* snake);