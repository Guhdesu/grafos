#include <stdio.h>

// Busca em Profundidade (DFS)
// Feita de forma recursiva

#define MAX 50

int visitado[MAX]; // marca quem ja foi visitado

void dfs(int grafo[MAX][MAX], int n, int v) {
    int i;

    // visita o vertice atual
    visitado[v] = 1;
    printf("%d ", v);

    // vai fundo em cada vizinho que ainda nao visitou
    for (i = 0; i < n; i++) {
        if (grafo[v][i] == 1 && visitado[i] == 0) {
            dfs(grafo, n, i);
        }
    }
}

int main() {
    int n = 6;

    // grafo de exemplo (matriz de adjacencia)
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

    printf("Busca em Profundidade a partir do vertice 0\n");
    printf("Ordem da visita: ");
    dfs(grafo, n, 0);
    printf("\n");

    return 0;
}
