// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Complexity: O(n)
bool isValid(vector<vector<int>>& graph, vector<int>& color, int c, int v) {
    for (int u = 0; u < graph[v].size(); u++) {
        if (graph[v][u] == 1) { // Theres a connection
            if (color[u] == c) {
                return false;
            }
        }
    }
    return true;
}

// Complexity: O(n^2)
void graphColoringOptimization(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    vector<bool> assigned(n);
    color[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fill(assigned.begin(), assigned.end(), false);
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1) {
                if (color[j] != -1) {
                    assigned[color[j]] = true;
                }
            }
        }
        for (int c = 1; c <= n; c++)
        {
            if (!assigned[c]) {
                color[i] = c;
                break;
            }
        }

    }
    int maximum = -1;
    for (int i = 0; i < n; i++)
    {
        cout << "Node: " << i + 1 << " <-> Assigned Color: " << color[i] << endl;
        if (maximum < color[i]) maximum = color[i];
    }
    cout << "Max Colors: " << maximum << endl;
}

// Complexity: O(n^3)
bool graphColoringDecision(vector<vector<int>>& graph, vector<int>& color, int m, int v) {
    int n = graph.size();
    if (v == n) {
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isValid(graph, color, c, v)) {
            color[v] = c;
            if (graphColoringDecision(graph, color, m, v + 1)) return true;
            color[v] = 0;
        }
    }
    return false;
}

// Complexity: O(n^3)
void graphColoringPermutation(vector<vector<int>>& graph, vector<int>& color, int m, int v) {
    int n = graph.size();
    if (v == n) {
        for (auto x : color) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isValid(graph, color, c, v)) {
            color[v] = c;
            graphColoringPermutation(graph, color, m, v + 1);
            color[v] = 0;
        }
    }
}

// O(n^3)
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }

    }
    cout << "Graph Optimization Problem: " << endl;
    graphColoringOptimization(graph);

    cout << "Graph Decision Problem: " << endl;
    for (int m = 1; m <= 5; m++)
    {
        cout << "The graph can be colored with " << m << " colors? ";
        graphColoringDecision(graph, color, m, 0) ? cout << "True " : cout << "False";
        cout << endl;
    }
    cout << endl;


    cout << "Graph Permutation Problem: " << endl;
    for (int m = 1; m <= 3; m++)
    {
        cout << "With  " << m << " colors: " << endl;
        graphColoringPermutation(graph, color, m, 0);
    }
    cout << endl;
}