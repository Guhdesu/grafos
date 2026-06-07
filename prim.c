#include <stdio.h>

// Algoritmo de Prim
// Le um grafo nao direcionado e ponderado do usuario e acha a Arvore Geradora Minima

#define MAX 50
#define INFINITO 99999

int grafo[MAX][MAX]; // matriz de adjacencia com os pesos (0 = sem aresta)
int naAGM[MAX];      // marca se o vertice ja entrou na arvore
int custo[MAX];      // menor peso para ligar o vertice na arvore
int pai[MAX];        // de quem o vertice veio (para mostrar a aresta)
int n;               // numero de vertices

// pega o vertice de menor custo que ainda nao esta na arvore
int menorCusto() {
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

void prim() {
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
        u = menorCusto();

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
    printf("\nArestas da Arvore Geradora Minima:\n");
    for (i = 0; i < n; i++) {
        if (pai[i] != -1) {
            printf("%d - %d  (peso %d)\n", pai[i], i, grafo[i][pai[i]]);
        }
    }
    printf("Peso total da arvore: %d\n", total);
}

int main() {
    int i, j;

    printf("Digite o numero de vertices: ");
    scanf("%d", &n);

    printf("Digite a matriz de adjacencia com os pesos (%d x %d, 0 = sem aresta):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grafo[i][j]);
        }
    }

    prim();

    return 0;
}
