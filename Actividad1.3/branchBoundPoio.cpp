bool check(vector<vector<int>> tabla, vector<vector<int>> solucion, int x, int y)
{
    int N = tabla[0].size();
    int M = tabla.size();
    if (x >= 0 && x < N && y >= 0 && y < M && tabla[y][x] == 1 && solucion[y][x] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkSize(vector<vector<int>> tabla, int x, int y)
{
    int N = tabla[0].size() - 1;
    int M = tabla.size() - 1;
    if ((x == N) && (y == M))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool branchBound(vector<vector<int>> tabla, vector<vector<int>> &solucion)
{
    int x = 0;
    int y = 0;
    queue<int> queueX;
    queue<int> queueY;
    int N = tabla[0].size() - 1;
    int M = tabla.size() - 1;
    cout << N << M << endl;
    queueX.push(x);
    queueY.push(y);
    int x2, y2;
    while (!checkSize(tabla, x, y))
    {

        x = queueX.front();
        queueX.pop();
        y = queueY.front();
        queueY.pop();
        cout << x << " " << y << endl;

        solucion[y][x] = 1;
        if (check(tabla, solucion, x + 1, y))
        {
            x2 = x + 1;
            queueX.push(x2);
            cout << "x+1: x: " << x << " y: " << y << endl;
            queueY.push(y);
        }

        if (check(tabla, solucion, x, y + 1))
        {
            y2 = y + 1;
            cout << "Y2: " << y2 << endl;
            queueX.push(x);
            cout << "y+1: x: " << x << " y: " << y << endl;
            queueY.push(y2);
        }

        if (check(tabla, solucion, x - 1, y))
        {
            x2 = x - 1;
            queueX.push(x2);
            cout << "x-1: x: " << x << " y: " << y << endl;
            queueY.push(y);
        }

        if (check(tabla, solucion, x, y - 1))
        {
            y2 = y - 1;
            queueX.push(x);
            cout << "y-1: x: " << x << " y: " << y << endl;
            queueY.push(y2);
        }
    }
}