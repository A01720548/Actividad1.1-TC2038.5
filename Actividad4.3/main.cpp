/**
 * @file main.cpp
 * @author Esteban de la Maza, Andres Guerra
 * @brief Actividad 4.3
 * @version 0.1
 * @date 2021-11-05
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y;
    Point() : x(0), y(0) {}
    double dist(Point p) {
        return sqrt(pow((p.x - x), 2) + pow((p.y - y), 2));
    }
};

// Complexity: O(1)
int orientation(Point a, Point b, Point c) {
    int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    if (res > 0) {
        res = 1;
    }
    else if (res < 0) {
        res = -1;
    }
    return res;
}

// Complexity: O(1)
int compare(Point& p, Point& q, Point& r) {
    int ori = orientation(p, q, r);
    if (ori == 0) {
        return p.dist(r) >= p.dist(q) ? -1 : 1;
    }
    return ori;
}

// Complexity: O(n^2)
void sortPoints(vector<Point>& points) {
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare(points[0], points[i], points[j]) == 1) {
                swap(points[i], points[j]);
            }
        }

    }

}

// Complexity: O(1)
Point secondToTop(stack<Point>& st) {
    Point first = st.top();
    st.pop();
    Point second = st.top();
    st.push(first);
    return second;
}

// Complexity: O(1)
void swap(Point& p, Point& q) {
    Point temp = p;
    p = q;
    q = temp;
}

// Complexity: O(n^2)
void grahamScan(vector<Point> points) {
    int n = points.size();
    int yMin = points[0].y, idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < yMin || (points[i].y == yMin && points[i].x < points[idx].x)) {
            yMin = points[i].y;
            idx = i;
        }
    }
    swap(points[0], points[idx]);
    sortPoints(points);
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(points[0], points[i], points[i + 1]) == 0) {
            i++;
        }
        points[m] = points[i];
        m++;
    }
    if (m < 3) return;
    stack<Point> st;
    for (int i = 0; i < 3; i++) st.push(points[i]);
    for (int i = 3; i < m; i++)
    {
        while (st.size() > 1 && orientation(secondToTop(st), st.top(), points[i]) != -1) {
            st.pop();
        }
        st.push(points[i]);
    }
    while (!st.empty()) {
        Point p = st.top();
        st.pop();
        cout << '(' << p.x << ", " << p.y << ')' << endl;
    }

}

// Complexity: O(n^2)
int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    grahamScan(points);
}