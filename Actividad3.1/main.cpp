// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;


// Search and insertion Time complexity: O(m)

int main() {
    int n;
    cin >> n;
    string word;
    Trie trie;
    for (int i = 0; i < n; i++) {
        cin >> word;
        trie.insert(word);

    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        cout << word << " ";
        trie.search(word) ? cout << "Found" << endl : cout << "Not Found" << endl;
    }
}