// Esteban de la Maza A01720548
// Andres Guerra A00828452

// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Complexity O(n)
double totalProfit(vector<double> profits, vector<int> knapsack) {
    double total = 0;
    for (int x : knapsack) {
        total += profits[x];
    }
    return total;
}

// Complexity O(n)
int maxProfitWeightUtil(vector<int> weights, vector<double> profits, vector<bool>& visited) {
    double max = -1;
    int index;
    float division;
    for (int i = 0; i < weights.size(); i++) {
        division = profits[i] / weights[i];
        if (!visited[i] && max <= division) {
            max = weights[i];
            index = i;
        }
    }
    visited[index] = true;
    return index;
}

// Complexity O(n)
double maxProfitWeight(vector<int> weights, vector<double> profits, int maxWeight) {
    int n = weights.size();
    vector<int> knapsack;
    int index;
    int weight = maxWeight;
    vector<bool> visited(n);

    while (n-- && weight > 0) {
        index = maxProfitWeightUtil(weights, profits, visited);
        if (weight >= weights[index]) {
            knapsack.push_back(index);
            weight -= weights[index];
        }
    }
    cout << "Greedy Max Profit/Weight: " << endl;
    for (int x : knapsack) {
        cout << "i=" << x << " : w=" << weights[x] << " : p=" << profits[x] << endl;
    }
    cout << "Total Items in Knapsack = " << knapsack.size() << endl;
    cout << "Total Weight = " << maxWeight - weight << "/" << maxWeight << endl;
    double totalP = totalProfit(profits, knapsack);
    cout << "Total Profit = " << totalP << endl;
    return totalP;
}

// Complexity O(n)
int minWeightUtil(vector<int> weights, vector<bool>& visited) {
    double min = 999999;
    int index;
    for (int i = 0; i < weights.size(); i++) {
        if (!visited[i] && min >= weights[i]) {
            min = weights[i];
            index = i;
        }
    }
    visited[index] = true;
    return index;
}

// Complexity O(n)
double minWeight(vector<int> weights, vector<double> profits, int maxWeight) {
    int n = weights.size();
    vector<int> knapsack;
    int index;
    int weight = maxWeight;
    vector<bool> visited(n);

    while (n-- && weight > 0) {
        index = minWeightUtil(weights, visited);
        if (weight >= weights[index]) {
            knapsack.push_back(index);
            weight -= weights[index];
        }
    }
    cout << "Greedy Min Weight: " << endl;
    for (int x : knapsack) {
        cout << "i=" << x << " : w=" << weights[x] << " : p=" << profits[x] << endl;
    }
    cout << "Total Items in Knapsack = " << knapsack.size() << endl;
    cout << "Total Weight = " << maxWeight - weight << "/" << maxWeight << endl;
    double totalP = totalProfit(profits, knapsack);
    cout << "Total Profit = " << totalP << endl;
    return totalP;
}

// Complexity O(n)
double takeFirst(vector<int> weights, vector<double> profits, int maxWeight) {
    int n = weights.size();
    vector<int> knapsack;
    int index;
    int weight = maxWeight;
    vector<bool> visited(n);

    for (int i = 0; i < n; i++) {
        if (weight >= weights[i]) {
            knapsack.push_back(i);
            weight -= weights[i];
        }
    }

    cout << "Greedy Take First Item: " << endl;
    for (int x : knapsack) {
        cout << "i=" << x << " : w=" << weights[x] << " : p=" << profits[x] << endl;
    }
    cout << "Total Items in Knapsack = " << knapsack.size() << endl;
    cout << "Total Weight = " << maxWeight - weight << "/" << maxWeight << endl;
    double totalP = totalProfit(profits, knapsack);
    cout << "Total Profit = " << totalP << endl;
    return totalP;
}

// Complexity O(n)
int maxProfitUtil(vector<double> profits, vector<bool>& visited) {
    double max = -1;
    int index;
    for (int i = 0; i < profits.size(); i++) {
        if (!visited[i] && max <= profits[i]) {
            max = profits[i];
            index = i;
        }
    }
    visited[index] = true;
    return index;
}
// Complexity O(n)
double maxProfit(vector<int> weights, vector<double> profits, int maxWeight) {
    int n = weights.size();
    vector<int> knapsack;
    int index;
    int weight = maxWeight;
    vector<bool> visited(n);

    while (n-- && weight > 0) {
        index = maxProfitUtil(profits, visited);
        if (weight >= weights[index]) {
            knapsack.push_back(index);
            weight -= weights[index];
        }
    }
    cout << "Greedy Max Profit: " << endl;
    for (int x : knapsack) {
        cout << "i=" << x << " : w=" << weights[x] << " : p=" << profits[x] << endl;
    }
    cout << "Total Items in Knapsack = " << knapsack.size() << endl;
    cout << "Total Weight = " << maxWeight - weight << "/" << maxWeight << endl;
    double totalP = totalProfit(profits, knapsack);
    cout << "Total Profit = " << totalP << endl;
    return totalP;
}


// Complexity O(2^n)
double dp(vector<int> weights, vector<double> profits, map<string, double> map, int maxWeight, int n) {
    double include, notInclude;
    if (maxWeight < 0) {
        return -99999;
    }
    if (maxWeight == 0 || n <= 0) {
        return 0;
    }
    string key = to_string(n + 'A' + maxWeight);
    if (map.find(key) == map.end()) {
        include = profits[n - 1] + dp(weights, profits, map, maxWeight - weights[n - 1], n - 1);
        notInclude = dp(weights, profits, map, maxWeight, n - 1);
        map[key] = include > notInclude ? include : notInclude;
    }
    return map[key];
}


int main() {
    int items, maxWeight;
    cin >> items >> maxWeight;

    vector<int> weights;
    vector<double> profits;
    int w;
    double x;
    while (items--) {
        cin >> w >> x;
        weights.push_back(w);
        profits.push_back(x);
    }
    // Greedy Take First Item
    double first = takeFirst(weights, profits, maxWeight);
    cout << endl;

    // Greedy Min Weight
    double minW = minWeight(weights, profits, maxWeight);
    cout << endl;

    // Greedy Max Profit
    double maxP = maxProfit(weights, profits, maxWeight);
    cout << endl;

    // Greedy Max Profit / Weight
    double profitWeight = maxProfitWeight(weights, profits, maxWeight);
    cout << endl;

    // Dynamic Programming
    map<string, double> map;
    double dpAns = dp(weights, profits, map, maxWeight, weights.size());

    vector<double> greedyAnswers = { first, minW, maxP, profitWeight };
    vector<bool> visited(greedyAnswers.size());
    switch (maxProfitUtil(greedyAnswers, visited)) {
    case 0:
        cout << "Best Strategy was Greedy FirstItem with " << first << " of profit." << endl;
        break;
    case 1:
        cout << "Best Strategy was Greedy MinWeight with " << minW << " of profit." << endl;
        break;
    case 2:
        cout << "Best Strategy was Greedy MaxPrice with " << maxP << " of profit." << endl;
        break;
    case 3:
        cout << "Best Strategy was Greedy MaxProfit/Weight with " << profitWeight << " of profit." << endl;
        break;
    }
    cout << "With Dynamic Programming the profit is = " << dpAns << endl;
}