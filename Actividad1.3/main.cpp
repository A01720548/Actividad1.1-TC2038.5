// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> maze, solBack, solBB;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> vec(m);
    cout << "n= " << n << " m= " << m << endl;
    for (int i = 0; i < n; i++)
    {
        maze.push_back(vec);
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];
    }
}

void backTracking()
{
}

void branchAndBound()
{
}

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
