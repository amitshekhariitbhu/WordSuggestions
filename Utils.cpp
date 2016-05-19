//
// Created by Amit Shekhar on 19/05/16.
//

#include <fstream>
#include <iostream>
#include "Utils.h"

bool Utils::loadDictionary(Trie* trie,string path){
    ifstream words;

    words.open(path.c_str());

    if(!words.is_open())
    {
        cout<<"Dictionary file Not Open"<<endl;
        return false;
    }

    while(!words.eof())
    {
        string s,reqS="";
        words >> s;
        for(int i=0;s.at(i)!=',';i++){
            reqS = reqS+s.at(i);
        }
        reqS = reqS.substr(5,reqS.length()-4);
        trie->addWord(reqS);
    }
    return true;
}