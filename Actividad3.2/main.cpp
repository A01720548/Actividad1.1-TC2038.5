// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF 999999

// Complexity O(n^2)
void print(vector<vector<int>>& a) {
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;

    }

}

// Complexity O(n^3)
void floyd(vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            for (int k = 0; k < graph.size(); k++) {
                if (graph[j][k] > graph[j][i] + graph[i][k]) {
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }
}

// Complexity O(n)
int minDist(vector<int>& dist, vector<bool>& visited) {
    int min = INF, index;
    for (int i = 0; i < dist.size(); i++)
    {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;

}

// Complexity O(n^2)
void dijkstra(vector<vector<int>>& graph, int initial, vector<int>& dist) {
    vector<bool> visited(dist.size());
    int u;
    for (int i = 0; i < visited.size(); i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[initial] = 0;
    for (int i = 0; i < dist.size() - 1; i++)
    {
        u = minDist(dist, visited);
        visited[u] = true;
        for (int v = 0; v < dist.size(); v++)
        {
            if (!visited[v] && graph[u][v] != -1 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }


}


int main() {
    int n, num;
    cin >> n;
    vector<vector<int>> graph;
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        graph.push_back(dist);
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Dijkstra
    cout << "Dijkstra: " << endl;
    for (int i = 0; i < n; i++)
    {
        dijkstra(graph, i, dist);
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                cout << "Node: " << i + 1 << " to node: " << j + 1 << ": " << dist[j] << endl;
        }
        cout << endl;

    }



    // Floyd
    cout << "Floyd: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == -1)
                graph[i][j] = INF;
        }
    }
    floyd(graph);
    print(graph);
}