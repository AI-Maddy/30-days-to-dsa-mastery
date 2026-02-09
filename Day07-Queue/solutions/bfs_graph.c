/*
Overview:
- Performs BFS on an unweighted graph using a queue.
Approach:
- Use adjacency lists and a visited array.
Complexity:
- Time: O(V + E)
- Space: O(V + E)
*/

#include <stdio.h>
#include <stdbool.h>

#define V 5
#define MAX_EDGES 10

int adj[V][MAX_EDGES];
int deg[V];

void add_edge(int u, int v) {
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}

void bfs(int start) {
    int queue[100];
    int front = 0;
    int rear = 0;
    bool visited[V] = {false};

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < deg[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
        }
    }
    printf("\n");
}

int main(void) {
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(2, 4);

    bfs(0);
    return 0;
}
