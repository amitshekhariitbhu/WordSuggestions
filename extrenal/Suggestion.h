//
// Created by Amit Shekhar on 19/05/16.
//
#include <string>
using namespace std;

#ifndef WORDSUGGESTIONS_SUGGESTION_H
#define WORDSUGGESTIONS_SUGGESTION_H


class Suggestion {
public:
    void init(string path);
    void destroy();
    void getSuggestion(string input);
};


#endif //WORDSUGGESTIONS_SUGGESTION_H
