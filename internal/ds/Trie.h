//
// Created by Amit Shekhar on 15/05/16.
//
#include <string>
#include "Node.h"

#ifndef WORDSUGGESTIONS_TRIE_H
#define WORDSUGGESTIONS_TRIE_H


class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    void parseTree(Node *current,char * s,vector<string>&,bool &loop);
private:
    Node* root;
};


#endif //WORDSUGGESTIONS_TRIE_H
