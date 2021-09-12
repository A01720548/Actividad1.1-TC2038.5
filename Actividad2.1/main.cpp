// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "hashMapString.h"
using namespace std;

// O(n)
unsigned long djb2(unsigned char* str) {
    unsigned long hash = 5381;
    int c;
    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}


// O(n^2)
int main() {
    int collisions = 0;
    unsigned long n;
    fstream newfile;
    string word;
    vector<string> words;
    vector<hashMapString> output;
    map<unsigned long, vector<string>> mapDJB2;
    newfile.open("words.txt", ios::in); // Open a file to read
    if (newfile.is_open()) {
        while (getline(newfile, word)) { // Read a line from file
            words.push_back(word);
        }
        newfile.close();
    }
    // O(n)
    for (int i = 0; i < words.size(); i++) {
        n = djb2((unsigned char*)words[i].c_str());
        if (mapDJB2.find(n) != mapDJB2.end()) { // Collision
            collisions++;
            hashMapString hash(i, words[i], n);
            output.push_back(hash);

        }
        mapDJB2[n].push_back(words[i]);
    }
    cout << "Total palabras = " << words.size() << endl;
    cout << "Colisiones de DJB2 = " << collisions << endl;

    // O(n^2)
    for (int i = 0; i < output.size(); i++)
    {
        output[i].print();
        for (int j = 1; j < mapDJB2[output[i].hash].size(); j++)
        {
            cout << mapDJB2[output[i].hash][j];
        }
        cout << endl;

    }

}
