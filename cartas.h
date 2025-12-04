#define CARTAS_H

// Códigos para representar as cores das cartas
#define COR_VERMELHA 0
#define COR_VERDE    1
#define COR_AZUL     2
#define COR_AMARELA  3
#define COR_ESPECIAL 4  // Cor usada para cartas coringa

// Códigos para representar valores especiais
#define VALOR_INVERTE       10
#define VALOR_MAIS_DOIS     11
#define VALOR_BLOQUEIA      12
#define VALOR_CORINGA       13
#define VALOR_COMPRA_QUATRO 14

// Estrutura de uma carta
typedef struct Carta {
    int cor;
    int valor;
} Carta;

// Nodo de lista encadeada
typedef struct NodoCarta {
    Carta carta;
    struct NodoCarta* prox;
} NodoCarta;

// Funções
NodoCarta* criarCarta(int cor, int valor);
void adicionarCarta(NodoCarta** lista, Carta carta);
Carta removerCarta(NodoCarta** lista, int indice);
void imprimirCarta(Carta carta);
void liberarLista(NodoCarta** lista);
