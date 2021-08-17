// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
using namespace std;

vector<double> vec;

vector<double> merge(vector<double> left, vector<double> right)
{
    vector<double> result;
    while ((int)left.size() > 0 || (int)right.size() > 0)
    {
        if ((int)left.size() > 0 && (int)right.size() > 0)
        {
            if ((double)left.front() >= (double)right.front())
            {
                result.push_back((double)left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back((double)right.front());
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

vector<double> mergeSort(vector<double> n)
{
    if (n.size() <= 1)
        return n;
    vector<double> left, right, result;
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

int main()
{

    vector<double> result;
    int n;
    cin >> n;
    double num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }
    result = mergeSort(vec);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << endl;
    }
}