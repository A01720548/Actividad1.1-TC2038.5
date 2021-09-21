#ifndef __TRIE_H__
#define __TRIE_H__
#include <bits/stdc++.h>
#include "TrieNode.h"
using namespace std;

class Trie
{
private:
    /* data */
public:
    TrieNode* root;
    Trie();
    TrieNode* newNode();
    void insert(string);
    bool search(string);
};

Trie::Trie()
{
    root = newNode();
}

TrieNode* Trie::newNode()
{
    TrieNode* n = new TrieNode();
    n->isEnd = false;
    for (int i = 0; i < 26; i++)
    {
        n->children[i] = NULL;
    }
    return n;
}

void Trie::insert(string word)
{
    int index;
    TrieNode* current = root;
    for (auto letter : word) {
        index = letter - 'a';
        if (!current->children[index]) {
            current->children[index] = newNode();
        }
        current = current->children[index];
    }
    current->isEnd = true;

}

bool Trie::search(string word)
{
    int index;
    TrieNode* current = root;
    for (auto letter : word) {
        index = letter - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current->isEnd;

}


#endif // __TRIE_H__