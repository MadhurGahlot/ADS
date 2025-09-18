#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // No of vertice
    vector<vector<int>> adj; // Adjacency list

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        // Recur for all adjacent vertices
        for (int u : adj[v]) {   //Range Based loop
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Directed graph
        // For undirected graph, also add: adj[w].push_back(v);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "Depth First Search starting from node 0:\n";
    g.DFS(0);

    return 0;
}
