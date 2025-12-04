#ifndef JOGADORES_H
#define JOGADORES_H

#include "cartas.h"

#define MAX_JOGADORES 10

typedef struct Jogador {
    char nome[50];
    NodoCarta* mao;
} Jogador;

typedef struct NodoJogador {
    Jogador jogador;
    struct NodoJogador* prox;
} NodoJogador;

NodoJogador* criarJogador(const char* nome);
void adicionarJogador(NodoJogador** fila, const char* nome);
Jogador* proximoJogador(NodoJogador** fila);
void imprimirMao(Jogador* jogador);
