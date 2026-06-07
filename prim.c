#include <stdio.h>

// Algoritmo de Prim
// Acha a Arvore Geradora Minima (AGM)

#define MAX 50
#define INFINITO 99999

int naAGM[MAX];  // marca se o vertice ja entrou na arvore
int custo[MAX];  // menor peso para ligar o vertice na arvore
int pai[MAX];    // de quem o vertice veio (para mostrar a aresta)

// pega o vertice de menor custo que ainda nao esta na arvore
int menorCusto(int n) {
    int i;
    int menor = INFINITO;
    int indice = -1;

    for (i = 0; i < n; i++) {
        if (naAGM[i] == 0 && custo[i] < menor) {
            menor = custo[i];
            indice = i;
        }
    }
    return indice;
}

void prim(int grafo[MAX][MAX], int n) {
    int i, count, u;
    int total = 0; // peso total da arvore

    // comeca tudo como infinito
    for (i = 0; i < n; i++) {
        custo[i] = INFINITO;
        naAGM[i] = 0;
        pai[i] = -1;
    }

    // comeca pelo vertice 0
    custo[0] = 0;

    for (count = 0; count < n; count++) {
        u = menorCusto(n);

        if (u == -1) {
            break;
        }

        naAGM[u] = 1;
        total = total + custo[u];

        // atualiza o custo dos vizinhos de u
        for (i = 0; i < n; i++) {
            if (grafo[u][i] != 0 && naAGM[i] == 0) {
                if (grafo[u][i] < custo[i]) {
                    custo[i] = grafo[u][i];
                    pai[i] = u;
                }
            }
        }
    }

    // mostra as arestas escolhidas
    printf("Arestas da Arvore Geradora Minima:\n");
    for (i = 0; i < n; i++) {
        if (pai[i] != -1) {
            printf("%d - %d  (peso %d)\n", pai[i], i, grafo[i][pai[i]]);
        }
    }
    printf("Peso total da arvore: %d\n", total);
}

int main() {
    int n = 6;

    // grafo de exemplo com pesos (0 = sem aresta)
    int grafo[MAX][MAX] = {
        {0, 7, 9, 0, 0, 14}, // 0
        {7, 0, 10, 15, 0, 0}, // 1
        {9, 10, 0, 11, 0, 2}, // 2
        {0, 15, 11, 0, 6, 0}, // 3
        {0, 0, 0, 6, 0, 9},   // 4
        {14, 0, 2, 0, 9, 0}   // 5
    };

    printf("Algoritmo de Prim\n");
    prim(grafo, n);

    return 0;
}
