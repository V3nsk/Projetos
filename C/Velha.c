#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
}Celula;

Celula jogo [7][7];
int l, c, tam = 7;

void inicializarJogo(){
    for(l = 0; l < tam; l++){
        for (c = 0; c < tam; c++){
            jogo [l][c].eBomba = 0;
            jogo [l][c].estaAberta = 0;
            jogo [l][c].vizinhos = 0;
        }
    }
}

void sortearBombas(int n){
    int i;
    srand(time(NULL));
    for(i = 1; i <= n; i++){
         l = rand() % tam;
         c = rand() % tam;
         if(jogo [l][c].eBomba == 0)
            jogo[l][c].eBomba = 1;
        else
            i--;
    }
}

int coordenadaEhValida(int l, int c){
    if(l >= 0 && l < tam && c >= 0 && c < tam)
        return 1;
    else
        return 0;
}


int quantBombasVizinhas(int l, int c){
    int quantidade = 0;

    if(coordenadaEhValida( l - 1, c) && jogo[l-1][c].eBomba)
        quantidade++;
    if(coordenadaEhValida( l + 1, c) && jogo[l+1][c].eBomba)
        quantidade++;
    if(coordenadaEhValida( l, c - 1) && jogo[l][c-1].eBomba)
        quantidade++;
    if(coordenadaEhValida( l, c + 1) && jogo[l][c+1].eBomba)
        quantidade++;
    if(coordenadaEhValida( l - 1, c + 1) && jogo[l-1][c+1].eBomba)
        quantidade++;
    if(coordenadaEhValida( l - 1, c - 1) && jogo[l-1][c+1].eBomba)
        quantidade++;
    if(coordenadaEhValida( l + 1, c + 1) && jogo[l+1][c+1].eBomba)
        quantidade++;
    if(coordenadaEhValida( l + 1, c - 1) && jogo[l+1][c-1].eBomba)
        quantidade++;


    return quantidade;

}

void contarBombas(){
    for(l = 0; l < tam; l++){
        for (c = 0; c < tam; c++)
            jogo[l][c].vizinhos = quantBombasVizinhas(l, c);

    }
}

void imprimir(){
    printf("\n\n\t    ");
    for (l = 0; l < tam; l++)
        printf(" %d  ", l); //indices das colunas
    printf("\n\t   -----------------------------\n");
    for(l = 0; l < tam; l++){
        printf("\t%d  |", l);//indices das linhas
        for (c = 0; c < tam; c++){
            if(jogo[l][c].estaAberta){
                if(jogo[l][c].eBomba)
                    printf(" * ");
                else
                    printf(" %d ", jogo[l][c].vizinhos);
            }
            else
                printf("   ");
            printf("|");
        }
        printf("\n\t   -----------------------------\n");
    }
}
void abrirCelula(int l, int c){
    if(coordenadaEhValida(l, c) == 1 && jogo[l][c].estaAberta == 0){
        jogo[l][c].estaAberta = 1;
        if (jogo[l][c].vizinhos == 0){
   
            abrirCelula(l-1, c);
            abrirCelula(l+1, c);
            abrirCelula(l, c+1);
            abrirCelula(l, c-1);
            abrirCelula(l-1, c+1);
            abrirCelula(l-1, c-1);
            abrirCelula(l+1, c+1);
            abrirCelula(l+1, c-1);
        }
    }
}
int ganhou(){
    int quantidade = 0;
    for(l = 0; l < tam; l++){
        for (c = 0; c < tam; c++){
           if(jogo[l][c].estaAberta == 0 && jogo[l][c].eBomba == 0)
                quantidade++;
        }
    }
    return quantidade;
}


void jogar(){
    int linha, coluna, acertos = 0;
    do{
        imprimir();
        do{
            printf("Digite as coordenadas de linha e coluna:\n ");
            scanf("%d %d",&linha, &coluna);

            if(coordenadaEhValida(linha, coluna)== 0 || jogo[linha][coluna].estaAberta == 1)
                printf("\nCoordenada Invalida ou ja aberta!");
        }while(coordenadaEhValida(linha, coluna)== 0 || jogo[linha][coluna].estaAberta == 1);

        abrirCelula(linha, coluna);
        pontuacao(&acertos, linha, coluna);
    }while(ganhou() != 0 && jogo[linha][coluna].eBomba == 0);

    if(jogo[linha][coluna].eBomba == 1)
        printf("\n\t Foi quase pateta!!!\n");
    else
        printf("\n\t PARABENS VOCE NAO EH PATETA!!!\n");
    imprimir();
}

void pontuacao(int * acertos, int linha, int coluna){
    if(jogo[linha][coluna].eBomba != 1){
        (*acertos)++;
    }
    printf("\tPontos:  %d\n", (*acertos) * 5);
}

int main(){
    int opcao;
    do{
        inicializarJogo();
        sortearBombas(10);
        contarBombas();
        printf("\n\n\t\t   CAMPO MINADO\n");
        jogar();
   
        printf("\t\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;
}