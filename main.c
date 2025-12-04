#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartas.h"
#include "jogadores.h"

void distribuirCartas(Jogador* jogador) {
    for (int i = 0; i < 5; i++) {
        Carta c = {rand() % 4, rand() % 10};
        adicionarCarta(&jogador->mao, c);
    }
}

int main() {
    srand(time(NULL));

    NodoJogador* fila = NULL;

    adicionarJogador(&fila, "Alice");
    adicionarJogador(&fila, "Bob");

    NodoJogador* atual = fila;
    do {
        distribuirCartas(&atual->jogador);
        atual = atual->prox;
    } while (atual != fila);

    for (int turno = 0; turno < 2; turno++) {
        Jogador* jogador = proximoJogador(&fila);

        printf("\nÉ a vez de %s\n", jogador->nome);
        imprimirMao(jogador);

        printf("Jogue uma carta (índice): ");
        int indice;
        scanf("%d", &indice);

        Carta jogada = removerCarta(&jogador->mao, indice);
        printf("%s jogou ", jogador->nome);
        imprimirCarta(jogada);
        printf("\n");
    }

    return 0;
}
