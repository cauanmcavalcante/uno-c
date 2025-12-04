#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogadores.h"

NodoJogador* criarJogador(const char* nome) {
    NodoJogador* novo = (NodoJogador*)malloc(sizeof(NodoJogador));
    strcpy(novo->jogador.nome, nome);
    novo->jogador.mao = NULL;
    novo->prox = novo; // fila circular
    return novo;
}

void adicionarJogador(NodoJogador** fila, const char* nome) {
    NodoJogador* novo = criarJogador(nome);

    if (*fila == NULL) {
        *fila = novo;
    } else {
        NodoJogador* temp = *fila;
        while (temp->prox != *fila) {
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->prox = *fila;
    }
}

Jogador* proximoJogador(NodoJogador** fila) {
    *fila = (*fila)->prox;
    return &(*fila)->jogador;
}

void imprimirMao(Jogador* jogador) {
    printf("Mão de %s:\n", jogador->nome);
    NodoCarta* atual = jogador->mao;
    int i = 0;

    while (atual) {
        printf("%d: ", i);
        imprimirCarta(atual->carta);
        printf("\n");
        atual = atual->prox;
        i++;
    }
}
