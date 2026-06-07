#include <stdio.h>

// Algoritmo de Dijkstra
// Le um grafo ponderado (pesos nao negativos) do usuario e acha o caminho minimo
// de um vertice de origem ate todos os outros

#define MAX 50
#define INFINITO 99999 // representa "sem caminho"

int grafo[MAX][MAX]; // matriz de adjacencia com os pesos (0 = sem aresta)
int dist[MAX];       // menor distancia ate cada vertice
int visitado[MAX];   // marca quem ja foi fechado
int anterior[MAX];   // de qual vertice eu vim (serve para montar o caminho)
int n;               // numero de vertices

// procura o vertice ainda nao visitado com a menor distancia
int menorDistancia() {
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

// imprime o caminho da origem ate v
// vai de tras pra frente usando o vetor anterior[], por isso eh recursivo
void imprimeCaminho(int v) {
    if (anterior[v] == -1) {
        printf("%d", v); // chegou na origem, nao tem mais de onde veio
        return;
    }
    imprimeCaminho(anterior[v]);
    printf(" -> %d", v);
}

void dijkstra(int origem) {
    int i, count, u;

    // no inicio todas as distancias sao infinito e ninguem tem "anterior"
    for (i = 0; i < n; i++) {
        dist[i] = INFINITO;
        visitado[i] = 0;
        anterior[i] = -1;
    }

    // a distancia da origem para ela mesma eh 0
    dist[origem] = 0;

    // precisa fechar n vertices
    for (count = 0; count < n; count++) {
        u = menorDistancia();

        if (u == -1) {
            break; // nao tem mais como chegar em ninguem
        }

        visitado[u] = 1;

        // tenta melhorar a distancia dos vizinhos de u
        for (i = 0; i < n; i++) {
            if (grafo[u][i] != 0 && visitado[i] == 0) {
                if (dist[u] + grafo[u][i] < dist[i]) {
                    dist[i] = dist[u] + grafo[u][i];
                    anterior[i] = u; // o melhor jeito de chegar em i eh passando por u
                }
            }
        }
    }

    // mostra o resultado: distancia e o caminho percorrido
    printf("\nResultado a partir do vertice %d:\n", origem);
    for (i = 0; i < n; i++) {
        if (i == origem) {
            continue; // nao precisa mostrar a origem para ela mesma
        }
        if (dist[i] == INFINITO) {
            printf("Vertice %d: sem caminho\n", i);
        } else {
            printf("Vertice %d: distancia = %d, caminho: ", i, dist[i]);
            imprimeCaminho(i);
            printf("\n");
        }
    }
}

int main() {
    int i, j;
    int origem;

    printf("Digite o numero de vertices: ");
    scanf("%d", &n);

    printf("Digite a matriz de adjacencia com os pesos (%d x %d, 0 = sem aresta):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grafo[i][j]);
        }
    }

    printf("Digite o vertice de origem: ");
    scanf("%d", &origem);

    dijkstra(origem);

    return 0;
}
