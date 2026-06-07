#include <stdio.h>

// Algoritmo de Dijkstra
// Acha o menor caminho de um vertice de origem para todos os outros

#define MAX 50
#define INFINITO 99999 // representa "sem caminho"

int dist[MAX];     // menor distancia ate cada vertice
int visitado[MAX]; // marca quem ja foi fechado

// procura o vertice ainda nao visitado com a menor distancia
int menorDistancia(int n) {
    int i;
    int menor = INFINITO;
    int indice = -1;

    for (i = 0; i < n; i++) {
        if (visitado[i] == 0 && dist[i] < menor) {
            menor = dist[i];
            indice = i;
        }
    }
    return indice;
}

void dijkstra(int grafo[MAX][MAX], int n, int origem) {
    int i, count, u;

    // no inicio todas as distancias sao infinito
    for (i = 0; i < n; i++) {
        dist[i] = INFINITO;
        visitado[i] = 0;
    }

    // a distancia da origem para ela mesma eh 0
    dist[origem] = 0;

    // precisa fechar n vertices
    for (count = 0; count < n; count++) {
        u = menorDistancia(n);

        if (u == -1) {
            break; // nao tem mais como chegar em ninguem
        }

        visitado[u] = 1;

        // tenta melhorar a distancia dos vizinhos de u
        for (i = 0; i < n; i++) {
            if (grafo[u][i] != 0 && visitado[i] == 0) {
                if (dist[u] + grafo[u][i] < dist[i]) {
                    dist[i] = dist[u] + grafo[u][i];
                }
            }
        }
    }

    // mostra o resultado
    printf("Vertice\tDistancia da origem\n");
    for (i = 0; i < n; i++) {
        if (dist[i] == INFINITO) {
            printf("%d\tsem caminho\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
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

    printf("Dijkstra a partir do vertice 0\n");
    dijkstra(grafo, n, 0);

    return 0;
}
