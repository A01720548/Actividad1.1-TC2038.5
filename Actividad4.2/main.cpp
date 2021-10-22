// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int u, v;
struct Point {
    int x, y;
};

vector<Point> arr;
vector<Point> temp;

float dist(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

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

float closestR(vector<Point>& points) {
    int n = points.size();
    if (n <= 3) {
        return bruteForce(points);
    }
    int middle = n / 2;
    vector<Point> XL(points.begin(), points.begin() + middle);
    vector<Point> XR(points.begin() + middle, points.end());
    return min(closestR(XL), closestR(XR));
}

float closest(vector<Point>& points) {
    arr = points;
    temp = arr;
    vector<int> n;
    for (auto x : points) {
        n.push_back(x.x);
    }
    mergeSort(n);
    return closestR(points);
}





// Complejidad: O(n)
vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    while ((int)left.size() > 0 || (int)right.size() > 0)
    {
        if ((int)left.size() > 0 && (int)right.size() > 0)
        {
            if ((int)left.front() >= (int)right.front())
            {
                result.push_back((int)left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back((int)right.front());
                right.erase(right.begin());
            }
        }
        else if ((int)left.size() > 0)
        {
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
        }
        else if ((int)right.size() > 0)
        {
            for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
            break;
        }
    }
    return result;
}

// Complejidad : O(logn)
vector<int> mergeSort(vector<int> n)
{

    if (n.size() <= 1)
        return n;
    vector<int> left, right, result;
    int middle = ((int)n.size() + 1) / 2;

    for (int i = 0; i < middle; i++)
    {
        left.push_back(n[i]);
    }

    for (int i = middle; i < (int)n.size(); i++)
    {
        right.push_back(n[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;

    }

    cout << "Brute Force: " << bruteForce(points) << endl;
    cout << "The closest points are: " << u + 1 << " and " << v + 1 << endl;
}