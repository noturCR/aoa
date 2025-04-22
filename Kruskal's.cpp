#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int find(int a, vector<int>& parent) {
    return parent[a] == a ? a : parent[a] = find(parent[a], parent);
}

void kruskal(int V, vector<Edge>& edges) {
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            parent[find(e.u, parent)] = find(e.v, parent);
        }
    }
}

int main() {
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    int V = 4;
    kruskal(V, edges);
    return 0;
}
