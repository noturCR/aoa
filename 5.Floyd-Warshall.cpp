#include <iostream>
#include <vector>
using namespace std;

#define INF 99999

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << (dist[i][j] == INF ? "INF" : to_string(dist[i][j])) << "\t";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    int V = 4;
    floydWarshall(graph, V);
    return 0;
}
