//
// Created by Amit Shekhar on 15/05/16.
//
#include<vector>
using namespace std;

#ifndef WORDSUGGESTIONS_NODE_H
#define WORDSUGGESTIONS_NODE_H


class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c);
    void appendChild(Node* child) { mChildren.push_back(child); }
    vector<Node*> children() { return mChildren; }

private:
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

#endif //WORDSUGGESTIONS_NODE_H
