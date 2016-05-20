//
// Created by Amit Shekhar on 20/05/16.
//

#include<iostream>
#include <vector>
#include "EditDistance.h"

using namespace std;

void EditDistance::edits(std::string word, std::vector<string> &result)
{
    for (string::size_type i = 0;i < word.length(); i++) {
        result.push_back(word.substr(0, i) + word.substr(i + 1)); //deletions
        cout<<word.substr(0, i) + word.substr(i + 1)<<endl;
    }
    for (string::size_type i = 0;i < word.size() - 1;i++){
        result.push_back(word.substr(0, i) + word[i+1] + word.substr(i + 2)); //transposition
        cout<<word.substr(0, i) + word[i+1] + word.substr(i + 2)<<endl;
    }

    for (char j = 'a';j <= 'z';++j) {
        for (string::size_type i = 0; i < word.size(); i++) {
            result.push_back(word.substr(0, i) + j + word.substr(i + 1)); //alterations
        }
        for (string::size_type i = 0; i < word.size() + 1; i++) {
            result.push_back(word.substr(0, i) + j + word.substr(i)); //insertion
        }
    }
}