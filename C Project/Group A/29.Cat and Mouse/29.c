#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROOMS 1000

void dfs(int att, int adj[MAX_ROOMS][MAX_ROOMS], bool visited[MAX_ROOMS]) {
    visited[att] = true;
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (adj[att][i] && !visited[i]) {
            dfs(i, adj, visited);
        }
    }
}

void caminhoSemGato(int Graph[MAX_ROOMS][MAX_ROOMS], bool bad_rooms[MAX_ROOMS], bool visited[MAX_ROOMS], int start) {
    for (int a = 0; a < MAX_ROOMS; a++) {
        if (Graph[start][a] && !visited[a] && !bad_rooms[a]) {
            visited[a] = true;
            caminhoSemGato(Graph, bad_rooms, visited, a);
        }
    }
}

int main() {
    int numTest;
    scanf("%d", &numTest);
    bool first = true;
    while (numTest--) {
        if (!first) printf("\n");
        first = false;
        int numRoom, inicioGato, inicioRato;
        scanf("%d%d%d", &numRoom, &inicioGato, &inicioRato);
        inicioGato--;
        inicioRato--;

        int adjgato[MAX_ROOMS][MAX_ROOMS] = {0};
        int adjrato[MAX_ROOMS][MAX_ROOMS] = {0};
        int a, b;
        while (scanf("%d%d", &a, &b) == 2) {
            if (a == -1 && b == -1) break;
            a--;
            b--;
            adjgato[a][b] = 1;
        }

        getchar();
        char line[1000];
        while (fgets(line, sizeof(line), stdin)) {
            if (line[0] == '\n') break;
            sscanf(line, "%d%d", &a, &b);
            a--;
            b--;
            adjrato[a][b] = 1;
        }

        bool visitedgato[MAX_ROOMS] = {false};
        bool visitedrato[MAX_ROOMS] = {false};
        dfs(inicioGato, adjgato, visitedgato);
        dfs(inicioRato, adjrato, visitedrato);

        bool r1 = false, r2 = false;
        for (int i = 0; i < numRoom; i++) {
            if (visitedgato[i] && visitedrato[i]) {
                r1 = true;
                break;
            }
        }

        bool visitedrato2[MAX_ROOMS] = {false};
        caminhoSemGato(adjrato, visitedgato, visitedrato2, inicioRato);
        r2 = visitedrato2[inicioRato];

        if (r1) printf("Y");
        else printf("N");

        printf(" ");

        if (r2) printf("Y");
        else printf("N");

        printf("\n");
    }
    return 0;
}
