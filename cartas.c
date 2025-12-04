#include <stdio.h>
#include <stdlib.h>
#include "cartas.h"

NodoCarta* criarCarta(int cor, int valor) {
    NodoCarta* nova = (NodoCarta*)malloc(sizeof(NodoCarta));
    nova->carta.cor = cor;
    nova->carta.valor = valor;
    nova->prox = NULL;
    return nova;
}

void adicionarCarta(NodoCarta** lista, Carta carta) {
    NodoCarta* nova = criarCarta(carta.cor, carta.valor);
    nova->prox = *lista;
    *lista = nova;
}

Carta removerCarta(NodoCarta** lista, int indice) {
    NodoCarta* atual = *lista;
    NodoCarta* anterior = NULL;

    for (int i = 0; i < indice && atual != NULL; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        Carta c = {-1, -1};
        return c;
    }

    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    Carta removida = atual->carta;
    free(atual);
    return removida;
}

void imprimirCarta(Carta carta) {
    char* cores[] = {"Vermelha", "Verde", "Azul", "Amarela", "Especial"};
    printf("[%s %d]", cores[carta.cor], carta.valor);
}

void liberarLista(NodoCarta** lista) {
    NodoCarta* atual = *lista;

    while (atual) {
        NodoCarta* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    *lista = NULL;
}
