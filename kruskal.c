#include <stdio.h>

// Algoritmo de Kruskal
// Le um grafo nao direcionado e ponderado do usuario (lista de arestas)
// e acha a Arvore Geradora Minima ordenando as arestas pelo peso

#define MAX 50

// cada aresta tem origem, destino e peso
struct Aresta {
    int origem;
    int destino;
    int peso;
};

struct Aresta arestas[MAX]; // lista de arestas do grafo
int pai[MAX];               // vetor para o union-find (saber a "raiz" de cada vertice)

// acha a raiz do conjunto do vertice x
int encontrar(int x) {
    while (pai[x] != x) {
        x = pai[x];
    }
    return x;
}

// junta os dois conjuntos
void unir(int a, int b) {
    int raizA = encontrar(a);
    int raizB = encontrar(b);
    pai[raizA] = raizB;
}

int main() {
    int n; // numero de vertices
    int m; // numero de arestas
    int i, j;

    printf("Digite o numero de vertices: ");
    scanf("%d", &n);

    printf("Digite o numero de arestas: ");
    scanf("%d", &m);

    printf("Digite cada aresta (origem destino peso):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
    }

    // ordena as arestas pelo peso (bubble sort mesmo)
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - 1 - i; j++) {
            if (arestas[j].peso > arestas[j + 1].peso) {
                struct Aresta temp = arestas[j];
                arestas[j] = arestas[j + 1];
                arestas[j + 1] = temp;
            }
        }
    }

    // no inicio cada vertice eh raiz de si mesmo
    for (i = 0; i < n; i++) {
        pai[i] = i;
    }

    int total = 0; // peso total da arvore

    printf("\nArestas da Arvore Geradora Minima:\n");

    // vai pegando as arestas em ordem, desde que nao forme ciclo
    for (i = 0; i < m; i++) {
        int u = arestas[i].origem;
        int v = arestas[i].destino;

        // so adiciona se estiverem em conjuntos diferentes (senao formaria ciclo)
        if (encontrar(u) != encontrar(v)) {
            printf("%d - %d  (peso %d)\n", u, v, arestas[i].peso);
            total = total + arestas[i].peso;
            unir(u, v);
        }
    }

    printf("Peso total da arvore: %d\n", total);

    return 0;
}
