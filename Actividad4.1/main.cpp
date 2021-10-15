// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

// Complexity: O(1)
int orientation(Point a, Point b, Point c) {
	int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	if (res > 0) res = 1;
	else if (res < 0) res = -1;
	return res;
}

// Complexity: O(1)
bool onSegment(Point a, Point b, Point c) {
	return c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) && c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y);
}

// Complexity: O(1)
bool doIntersect(Point a, Point b, Point c, Point d) {
	int or1 = orientation(a, b, c);
	int or2 = orientation(a, b, d);
	int or3 = orientation(c, d, a);
	int or4 = orientation(c, d, b);
	if (or1 != or2 && or3 != or4) return true;
	if (or1 == 0 && onSegment(a, b, c)) return true;
	if (or2 == 0 && onSegment(a, b, d)) return true;
	if (or3 == 0 && onSegment(c, d, a)) return true;
	if (or4 == 0 && onSegment(c, d, b)) return true;


}

// Complexity: O(n)
int main() {
	Point a, b, c, d;
	int n;
	cin >> n;
	while (n--) {
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;
		cin >> d.x >> d.y;
		doIntersect(a, b, c, d) ? cout << "True" << endl : cout << "False" << endl;
	}
}