// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;

vector<string> vec;
// O(nlogn)
int main() {
    string word;
    cin >> word;
    int count = 0;

    // O(n)
    for (int i = 0; i < word.length(); i++) {
        vec.push_back(word.substr(count, word.length()));
        count++;
    }
    // O(nLogN)
    sort(vec.begin(), vec.end());

    // O(n)
    for (int i = 0; i < word.length(); i++)
    {
        cout << vec[i] << endl;
    }

}