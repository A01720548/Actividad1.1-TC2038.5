/**
 * @file main.cpp
 * @author Esteban de la Maza, Andres Guerra
 * @brief Actividad 4.4
 * @version 0.1
 * @date 2021-11-09
 *
 * @copyright Copyright (c) 2021
 *
 */

 // g++ main.cpp -o main.exe
 // main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Complexity: O(1)
int getRandom(int left, int right) {
    return left + rand() % (right - left + 1);
}

// Complexity: O(logN)
int iterativeRBS(vector<int> vec, int x) {
    cout << "Iterative Version:";
    int left = 0, right = vec.size() - 1;
    int middle;
    int i = 0;
    while (left <= right) {
        cout << "Iterative" << endl;
        i++;
        middle = getRandom(left, right);
        if (vec[middle] == x) return middle;
        else if (vec[middle] < x) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}
// Complexity: O(logN)
int recursiveRBS(vector<int> vec, int x, int left, int right) {
    cout << "Recursive" << endl;
    if (left > right) return -1;
    int middle = getRandom(left, right);
    if (vec[middle] == x) return middle;
    else if (x > vec[middle]) return recursiveRBS(vec, x, middle + 1, right);
    else return recursiveRBS(vec, x, left, middle - 1);
}

int main() {
    srand(time(NULL));
    int n, idx;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int x;
    cin >> x;
    idx = iterativeRBS(vec, x);
    if (idx != -1) cout << "Element found at position: " << idx + 1 << endl;
    else cout << "Element not found" << endl;

    idx = recursiveRBS(vec, x, 0, vec.size() - 1);
    if (idx != -1) cout << "Element found at position: " << idx + 1 << endl;
    else cout << "Element not found" << endl;
}