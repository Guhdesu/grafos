#include <stdio.h>

// Busca em Largura (BFS)
// Faz a busca usando uma fila (vetor com inicio e fim)

#define MAX 50

int visitado[MAX]; // marca quem ja foi visitado

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

void bfs(int grafo[MAX][MAX], int n, int origem) {
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
    int n = 6;

    // grafo de exemplo (matriz de adjacencia)
    //      0  1  2  3  4  5
    int grafo[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0}, // 0
        {1, 0, 0, 1, 1, 0}, // 1
        {1, 0, 0, 0, 1, 0}, // 2
        {0, 1, 0, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1}, // 4
        {0, 0, 0, 1, 1, 0}  // 5
    };

    int i;
    for (i = 0; i < n; i++) {
        visitado[i] = 0;
    }

    printf("Busca em Largura a partir do vertice 0\n");
    bfs(grafo, n, 0);

    return 0;
}
