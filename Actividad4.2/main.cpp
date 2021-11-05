/**
 * @file main.cpp
 * @author Esteban de la Maza, Andres Guerra
 * @brief Actividad 4.2
 * @version 0.1
 * @date 2021-11-04
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int u, v;
struct Point {
    int x, y;
};

vector<Point> arr;
vector<Point> temp;

// Complexity: O(1)
float dist(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
// Complexity: O(n^2)
float bruteForce(vector<Point> points) {
    float minValue = INT_MAX;
    float temp;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = minValue;
            minValue = min(minValue, dist(points[i], points[j]));
            if (temp != minValue) {
                u = i;
                v = j;
            }
        }
    }
    return minValue;
}
// Complexity: O(logn)
void Merge(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (arr[i].x <= arr[j].x) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}
// Complexity: O(n)
void MergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(l, m);
        MergeSort(m + 1, r);
        Merge(l, m, r);
    }
}

// Complexity: O(1)
float closestR(vector<Point>& points) { //O(3)
    int n = points.size(), mitad;
    if (n <= 3) {
        return bruteForce(points);
    }
    mitad = n / 2;
    vector<Point> XL(points.begin(), points.begin() + mitad);
    vector<Point> XR(points.begin() + mitad, points.end());
    return min(closestR(XL), closestR(XR));
}

// Complexity: O(n)
float closest(vector<Point>& points) {
    int n = points.size();
    arr = points;
    temp = arr;
    MergeSort(0, n - 1);
    return closestR(arr);
}

// Complexity: O(n^2)
int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;

    }
    cout << "Brute Force: " << bruteForce(points) << endl;
    cout << "The closest points are: " << u + 1 << " and " << v + 1 << endl;
    cout << "The smallest distance is: " << closest(points) << endl;
}