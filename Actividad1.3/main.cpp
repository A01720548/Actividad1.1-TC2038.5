// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> maze, solBack, solBB;
int n, m;
// Complexity: O(n^2)
void print(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

bool exists(int x, int y)
{

    if (x < n && x >= 0 && y < m && y >= 0 && maze[x][y] == 1)
        return true;
    else
        return false;
}
// Complexity: O(n^2)
bool backTrackingRecursive(vector<vector<int>>& sol, int x, int y)
{
    // Check if is solution
    if (x == n - 1 && y == m - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (exists(x, y))
    {
        // Is already part of solution
        if (sol[x][y] == 1)
        {
            return false;
        }

        sol[x][y] = 1;

        // Try to Move right
        if (backTrackingRecursive(sol, x + 1, y) == true)
            return true;

        // Try to Move downwards
        if (backTrackingRecursive(sol, x, y + 1) == true)
            return true;

        // Try to Move up
        if (backTrackingRecursive(sol, x, y - 1) == true)
            return true;

        // Try to Move left
        if (backTrackingRecursive(sol, x - 1, y) == true)
            return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

void backTracking()
{
    // cout << backTrackingRecursive(solBack, 0, 0);
    if (backTrackingRecursive(solBack, 0, 0) == true)
    {
        cout << "Backtracking Solution: " << endl;
        print(solBack);
    }
    else
        cout << "No solution found";
}

bool BBChecker(int x, int y)
{
    if (x >= 0 && x < m && y >= 0 && y < n && maze[y][x] == 1 && solBB[y][x] == 0)
        return true;
    else
        return false;
}
// Complexity: O(n^2)
void branchAndBound()
{
    queue<int> x, y;
    int i = 0;
    int j = 0;

    x.push(i);
    y.push(j);

    int i2, j2;
    while (!(i == m) && !(j == n) && !x.empty() && !y.empty())
    {
        i = x.front();
        x.pop();
        j = y.front();
        y.pop();
        solBB[j][i] = 1;

        if (BBChecker(i + 1, j))
        {
            i2 = i + 1;
            x.push(i2);
            y.push(j);
        }
        if (BBChecker(i, j + 1))
        {
            j2 = j + 1;
            x.push(i);
            y.push(j2);
        }
        if (BBChecker(i - 1, j))
        {
            i2 = i - 1;
            x.push(i2);
            y.push(j);
        }
        if (BBChecker(i, j - 1))
        {
            j2 = j - 1;
            x.push(i);
            y.push(j2);
        }
    }
    cout << "Solucion Branch and Bound: " << endl;
    print(solBB);
}

int main()
{
    cin >> n;
    cin >> m;
    vector<int> vec(m);

    cout << "n= " << n << " m= " << m << endl;
    for (int i = 0; i < n; i++)
    {
        maze.push_back(vec);
        solBack.push_back(vec);
        solBB.push_back(vec);
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            solBack[i][j] = 0;
            solBB[i][j] = 0;
        }
    }

    print(maze);
    backTracking();
    branchAndBound();
}
