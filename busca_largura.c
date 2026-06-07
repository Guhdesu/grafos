#include <stdio.h>

// Busca em Largura (BFS)
// Le um grafo do usuario (matriz de adjacencia) e faz a busca usando uma fila

#define MAX 50

int grafo[MAX][MAX]; // matriz de adjacencia
int visitado[MAX];   // marca quem ja foi visitado
int n;               // numero de vertices

int fila[MAX];
int inicio = 0, fim = 0;

void enfileira(int v) {
    fila[fim] = v;
    fim++;
}

int desenfileira() {
    int v = fila[inicio];
    inicio++;
    return v;
}

int filaVazia() {
    if (inicio == fim) {
        return 1;
    } else {
        return 0;
    }
}

void bfs(int origem) {
    int i, atual;

    // marca a origem como visitada e coloca na fila
    visitado[origem] = 1;
    enfileira(origem);

    printf("Ordem da visita: ");

    while (filaVazia() == 0) {
        atual = desenfileira();
        printf("%d ", atual);

        // olha todos os vizinhos do vertice atual
        for (i = 0; i < n; i++) {
            if (grafo[atual][i] == 1 && visitado[i] == 0) {
                visitado[i] = 1;
                enfileira(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j;
    int origem;

    printf("Digite o numero de vertices: ");
    scanf("%d", &n);

    // zera tudo antes de comecar
    for (i = 0; i < n; i++) {
        visitado[i] = 0;
        for (j = 0; j < n; j++) {
            grafo[i][j] = 0;
        }
    }

    printf("Digite a matriz de adjacencia (%d x %d, use 0 ou 1):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grafo[i][j]);
        }
    }

    printf("Digite o vertice de origem: ");
    scanf("%d", &origem);

    bfs(origem);

    return 0;
}
