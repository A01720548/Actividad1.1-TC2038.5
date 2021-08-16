// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
using namespace std;

vector<double> vec;

vector<int> mergeSort(vector<int> n)
{
}

int main()
{
    int n;
    cin >> n;
    double num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
        cout << vec[i] << endl;
    }
}