#include <stdio.h>

// Busca em Profundidade (DFS)
// Le um grafo do usuario (matriz de adjacencia) e faz a busca de forma recursiva

#define MAX 50

int grafo[MAX][MAX]; // matriz de adjacencia
int visitado[MAX];   // marca quem ja foi visitado
int n;               // numero de vertices

void dfs(int v) {
    int i;

    // visita o vertice atual
    visitado[v] = 1;
    printf("%d ", v);

    // vai fundo em cada vizinho que ainda nao visitou
    for (i = 0; i < n; i++) {
        if (grafo[v][i] == 1 && visitado[i] == 0) {
            dfs(i);
        }
    }
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

    printf("Ordem da visita: ");
    dfs(origem);
    printf("\n");

    return 0;
}
