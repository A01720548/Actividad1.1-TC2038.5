// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<double> vec;

int maxPUtil(vector<double>& profits, vector<bool>& visited) {
    int index;
    double max = -1;
    for (int i = 0; i < profits.size(); i++)
    {
        if (!visited[i] && max < profits[i]) {
            max = profits[i];
            index = i;
        }
    }
    return index;


}

void maxP(vector<int>& weights, vector<double>& profits, vector<int>& knapsack, int maxWeight) {
    int n = weights.size(), index;
    vector<bool> visited(n, false);
    while (maxWeight && n--) {
        index = maxPUtil(profits, visited);
        visited[index] = true;
        if (maxWeight >= weights[index]) {
            knapsack.push_back(index);
            maxWeight -= weights[index];
        }
    }

}

map<string, double> m;

double dp(vector<int>& weights, vector<double>& profits, int n, int weight) {
    double include, notInclude;

    if (weight < 0) {
        return -99999;
    }
    if (weight == 0 || n <= 0) {
        return 0;
    }
    string key = to_string(n + 'A' + weight);
    if (m.find(key) == m.end()) {
        include = profits[n - 1] + dp(weights, profits, n - 1, weight - weights[n - 1]);
        notInclude = dp(weights, profits, n - 1, weight);
        m[key] = include > notInclude ? include : notInclude;
    }
    return m[key];

}


int main() {
    int items, maxWeight;
    cin >> items >> maxWeight;
    vector<int> weights(items);
    vector<double> profits(items);
    vector<int> knapsack;
    for (int i = 0; i < items; i++)
    {
        int w;
        double x;
        cin >> w >> x;
        weights.push_back(w);
        profits.push_back(x);
    }

    double c = dp(weights, profits, items, maxWeight);

    cout << c << endl;

}