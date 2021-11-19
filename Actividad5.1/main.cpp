/**
 * @file main.cpp
 * @author Esteban de la Maza, Andres Guerra
 * @brief Actividad 5.1
 * @version 0.1
 * @date 2021-11-12
 *
 * @copyright Copyright (c) 2021
 *
 */
 // g++ main.cpp -o main.exe
 // main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

typedef pair<double, pair<int, int>> Pair;

class Cell {
public:
    int row, col;
    double F, G, H;
    Cell() : row(-1), col(-1), F(INF), G(INF), H(INF) {}
    Cell(int r, int c) : row(r), col(c), F(INF), G(INF), H(INF) {}
    Cell(int r, int c, double f, double g, double h) : row(r), col(c), F(f), G(g), H(h) {}
    double distance(Cell c) {
        return sqrt((c.row - row) * (c.row - row) + (c.col - col) * (c.col - col));
    }
};

// Complexity: O(1)
bool isValid(vector<vector<int>> matrix, Cell c) {
    return c.row > -1 && c.col > -1 && c.row < matrix.size() && c.col < matrix[0].size();
}

// Complexity: O(1)
bool isBlocked(vector<vector<int>> matrix, Cell c) {
    return matrix[c.row][c.col] == 0;
}

// Complexity: O(1)
bool isDestination(Cell destination, Cell c) {
    return destination.row == c.row && destination.col == c.col;
}

// Complexity: O(1)
double calculateHValue(Cell destination, Cell c) {
    return destination.distance(c);
}

// Complexity: O(n)
void tracePath(vector<vector<Cell>>& cells, Cell destination) {
    stack<Cell> st;
    int row = destination.row;
    int col = destination.col;
    int temp;
    Cell c;
    while (!(cells[row][col].row == row && cells[row][col].col == col)) {
        st.push(Cell(row, col));
        temp = cells[row][col].row;
        col = cells[row][col].col;
        row = temp;

    }
    st.push(Cell(row, col));
    while (!st.empty()) {
        c = st.top();
        st.pop();
        if (!st.empty()) cout << '(' << c.row << " , " << c.col << ") -> ";
        else cout << '(' << c.row << " , " << c.col << ")";
    }
    cout << endl;
}

// Complexity: O(n)
bool visitCell(vector<vector<int>>& matrix, vector < vector<Cell>>& cells, vector<vector<bool>>& closed, set<Pair>& open, Cell destination, int row, int col, int parentRow, int parentCol) {
    bool success = false;
    double newF, newG, newH;
    Cell c(row, col);
    if (isValid(matrix, c)) {
        if (isDestination(destination, c)) {
            cells[row][col].row = parentRow;
            cells[row][col].col = parentCol;
            tracePath(cells, destination);
            success = true;
        }
        else if (!closed[row][col] && !isBlocked(matrix, c)) {
            newG = cells[row][col].G + c.distance(Cell(parentRow, parentCol));
            newH = calculateHValue(destination, c);
            newF = newG + newH;
            if (cells[row][col].F == INF || cells[row][col].F > newF) {
                open.insert(make_pair(newF, make_pair(row, col)));
                cells[row][col] = Cell(parentRow, parentCol, newF, newG, newH);
            }
        }
    }
    return success;
}


// Complexity: O(n)
void ASearch(vector<vector<int>>& matrix, Cell origin, Cell destination) {
    if (!isValid(matrix, origin) || !isValid(matrix, destination)) {
        cout << "Origin or Destination arent valid" << endl;
        return;
    }
    if (isBlocked(matrix, origin) || isBlocked(matrix, destination)) {
        cout << "Origin or Destination are blocked" << endl;
        return;
    }
    if (isDestination(destination, origin)) {
        cout << "Origin already at destination" << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> closed(n, vector<bool>(m, false));
    vector<vector<Cell>> cells(n, vector<Cell>(m));
    int row = origin.row;
    int col = origin.col;
    cells[row][col] = Cell(row, col, 0, 0, 0);
    set<Pair> open;
    Pair p;
    open.insert(make_pair(0, make_pair(row, col)));
    while (!open.empty()) {
        p = *open.begin();
        open.erase(open.begin());
        row = p.second.first;
        col = p.second.second;
        closed[row][col] = true;
        // Down
        if (visitCell(matrix, cells, closed, open, destination, row + 1, col, row, col)) {
            return;
        }
        // Up
        if (visitCell(matrix, cells, closed, open, destination, row - 1, col, row, col)) {
            return;
        }
        // Left
        if (visitCell(matrix, cells, closed, open, destination, row, col - 1, row, col)) {
            return;
        }
        // Right
        if (visitCell(matrix, cells, closed, open, destination, row, col + 1, row, col)) {
            return;
        }
        // Up-Left
        if (visitCell(matrix, cells, closed, open, destination, row - 1, col - 1, row, col)) {
            return;
        }
        // Up-Right
        if (visitCell(matrix, cells, closed, open, destination, row - 1, col + 1, row, col)) {
            return;
        }
        // Down-Left
        if (visitCell(matrix, cells, closed, open, destination, row + 1, col - 1, row, col)) {
            return;
        }
        // Down-Right
        if (visitCell(matrix, cells, closed, open, destination, row + 1, col + 1, row, col)) {
            return;
        }
    }
    cout << "Didnt reach destination" << endl;
}

// Complexity: O(n^2)
int main() {
    Cell origin, destination;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cin >> origin.row >> origin.col >> destination.row >> destination.col;
    ASearch(matrix, origin, destination);
}