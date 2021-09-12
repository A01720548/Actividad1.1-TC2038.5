#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class hashMapString
{
private:
    /* data */
public:
    hashMapString(int index, string word, long hash);
    void print();
    int index;
    string word;
    long hash;
};


// O(1)
hashMapString::hashMapString(int index, string word, long hash)
{
    this->index = index;
    this->word = word;
    this->hash = hash;
}

// O(1)
void hashMapString::print()
{
    cout << this->index << " " << this->word << " " << this->hash << " ";
}


