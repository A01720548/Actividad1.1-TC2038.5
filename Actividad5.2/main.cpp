/**
 * @file main.cpp
 * @author Esteban de la Maza, Andres Guerra
 * @brief Actividad 5.2
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright Copyright (c) 2021
 *
 */
 // g++ main.cpp -o main.exe
 // main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstvuwxyz";

// Complexity: O(n^2)
void initialPopulation(vector<string>& population, string objective) {
    int n = population.size(), m = objective.size();
    string individual;
    for (int i = 0; i < n; i++) {
        individual = "";
        for (int j = 0; j < m; j++) {
            individual += ABC[rand() % ABC.size()];
        }
        population[i] = individual;
    }


}

// Complexity: O(n^2)
vector<int> objectiveFunction(vector<string>& population, string objective) {
    int n = population.size(), m = objective.size();
    vector<int> fitness(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fitness[i] += abs(population[i][j] - objective[j]);
        }
    }
    return fitness;

}

// Complexity: O(n)
void printPopulation(vector<string>& population, vector<int> fitness) {
    int n = population.size();
    for (int i = 0; i < n; i++)
    {
        cout << population[i] << ' ' << fitness[i] << endl;
    }
    cout << endl;

}

// Complexity: O(n)
vector<string> crossover(vector<string>& population, vector<int> fitness) {
    int n = population.size(), m = population[0].size();
    vector<string> children(n);
    string father1, father2;
    int a, b, c, d, p;
    for (int i = 0; i < n; i += 2)
    {
        a = rand() % n;
        b = rand() % n;
        c = rand() % n;
        d = rand() % n;
        father1 = fitness[a] < fitness[b] ? population[a] : population[b];
        father2 = fitness[c] < fitness[d] ? population[c] : population[d];
        p = rand() % m;
        children[i] = father1.substr(0, p) + father2.substr(p);
        children[i + 1] = father2.substr(0, p) + father1.substr(p);
    }
    return children;

}

// Complexity: O(n^2)
void mutation(vector<string>& children, int nMutation) {
    int n = children.size(), m = children[0].size(), p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nMutation; j++)
        {
            p = rand() % m;
            children[i][p] = ABC[rand() % ABC.size()];
        }
    }

}

// Complexity: O(n)
void reinsertion(vector<string>& population, vector<int>& fitness, vector<string>& children, vector<int> fitnessChildren) {
    int n = population.size();
    for (int i = 0; i < n; i++)
    {
        if (fitness[i] > fitnessChildren[i]) {
            population[i] = children[i];
            fitness[i] = fitnessChildren[i];
        }
    }
}

// Complexity: O(n)
int findBest(vector<int>& fitness) {
    int n = fitness.size(), best = INF, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (best > fitness[i]) {
            best = fitness[i];
            idx = i;
        }
    }
    return idx;
}

// Complexity: O(n^3)
int main() {
    srand(time(NULL));
    string objective = "Tec de Monterrey", best;
    int iterations = 20000, sizePop = 10, nMutation = 3, globalBest = INF, idx;
    vector<string> population(sizePop), children;
    vector<int> fitness, fitnessChildren;
    initialPopulation(population, objective);
    fitness = objectiveFunction(population, objective);
    cout << "Initial Population: " << endl;
    printPopulation(population, fitness);
    int iter = 0;
    while (iter < iterations && globalBest > 0) {
        iter++;
        children = crossover(population, fitness);
        mutation(children, nMutation);
        fitnessChildren = objectiveFunction(children, objective);
        reinsertion(population, fitness, children, fitnessChildren);
        idx = findBest(fitness);
        if (globalBest > fitness[idx]) {
            globalBest = fitness[idx];
            best = population[idx];
            cout << iter << ' ' << best << ' ' << globalBest << endl;
        }
    }
    cout << "Final Population: " << endl;
    printPopulation(population, fitness);
}