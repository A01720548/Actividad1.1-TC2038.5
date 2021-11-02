// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    double x, y, minDist;
    int cluster;
    Point() : x(0), y(0), minDist(INT_MAX), cluster(-1) {}
    // Complexity: O(1)
    double dist(Point p) {
        return sqrt(pow((p.x - x), 2) + pow((p.y - y), 2));
    }
};

// Complexity: O(n*m*k)
void kMeans(vector<Point>& points, int iter, int k) {
    vector<Point> centroids;
    int n = points.size();
    double d;
    srand(time(NULL));
    for (int i = 0; i < k; i++) {
        centroids.push_back(points.at(rand() % n));
    }
    for (int i = 0; i < iter; i++) {
        for (int c = 0; c < k; c++) {
            for (int p = 0; p < n; p++) {
                d = centroids[c].dist(points[p]);
                if (d < points[p].minDist) {
                    points[p].minDist = d;
                    points[p].cluster = c;
                }
            }
        }
        vector<int> nPoints(k);
        vector<double> sumX(k), sumY(k);
        for (int p = 0; p < n; p++) {
            nPoints[points[p].cluster]++;
            sumX[points[p].cluster] += points[p].x;
            sumY[points[p].cluster] += points[p].y;
            points[p].minDist = INT_MAX;
        }
        for (int c = 0; c < k; c++) {
            centroids[c].x = sumX[c] / nPoints[c];
            centroids[c].y = sumY[c] / nPoints[c];
        }
    }
    for (int c = 0; c < k; c++) {
        cout << centroids[c].x << ' ' << centroids[c].y << endl;
    }
}

// Complexity: O(n*m*k)
int main() {
    int n, k;
    cin >> n >> k;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    kMeans(points, 100, k);
}