#include <stdio.h>
#include <stdbool.h>

#define MAX_V 5

// --- TOPIC 12: GRAPHS (BFS & DFS) ---
// Connecting the dots!
// Graph represented by Adjacency Matrix
int graph[MAX_V][MAX_V];
int visited[MAX_V];

void init_graph() {
    for (int i = 0; i < MAX_V; i++) {
        visited[i] = 0;
        for (int j = 0; j < MAX_V; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1; // Undirected
}

// DFS: Depth First Search (The adventurous explorer)
void dfs(int start) {
    printf("%d ", start); 
    visited[start] = 1;
    
    for (int i = 0; i < MAX_V; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// BFS: Breadth First Search (The cautious ripple)
void bfs(int start) {
    int queue[MAX_V], front = 0, rear = 0;
    int bfs_visited[MAX_V] = {0};
    
    printf("%d ", start);
    bfs_visited[start] = 1;
    queue[rear++] = start;
    
    while (front < rear) {
        int curr = queue[front++];
        
        for (int i = 0; i < MAX_V; i++) {
            if (graph[curr][i] == 1 && !bfs_visited[i]) {
                printf("%d ", i);
                bfs_visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    printf("\n=== GRAPH BFS & DFS PLAYGROUND ===\n");
    init_graph();
    
    // 0 -- 1
    // |    |
    // 2 -- 3 -- 4
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(3, 4);

    printf("DFS (starting at 0): ");
    // Reset visited for DFS
    for(int i=0; i<MAX_V; i++) visited[i] = 0;
    dfs(0);
    printf("\n");

    printf("BFS (starting at 0): ");
    bfs(0);
    printf("\n");

    return 0;
}
