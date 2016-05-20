//
// Created by Amit Shekhar on 19/05/16.
//

#include <string>
#include <iostream>
#include <set>
#include "Trie.h"
#include "Utils.h"
#include "EditDistance.h"
#include "Suggestion.h"

using namespace std;

Trie* trie;
bool isDictionaryLoaded;

void Suggestion::init(string path){
    trie = new Trie();
    cout<<"Loading dictionary"<<endl;

    isDictionaryLoaded = Utils::loadDictionary(trie,path);

    cout<<"isDictionaryLoaded : "<< Utils::boolToString(isDictionaryLoaded)<<endl;

}

void Suggestion::getSuggestion(string input){
    if(!isDictionaryLoaded){
        return;
    }
    int count=0;
    set<string> suggestions;
    vector<string> edit_list;
    if(trie->searchWord(input)){
        cout<<input<<"  found in Dictionary"<<endl;
    }
    else
    {
        EditDistance::edits(input,edit_list);
        for(unsigned int i=0;i<edit_list.size();i++)
        {
            if(trie->searchWord(edit_list[i]))
            {
                suggestions.insert(edit_list[i]);
                count++;
                if(count>10)
                    break;
            }
        }
        if(count==0){
            cout<<"No suggestions"<<endl;
        }
        else
        {
            cout<<"Did you mean"<<endl;
            set<string>::iterator itr;
            for(itr=suggestions.begin();itr!=suggestions.end();itr++)
                cout<<*itr<<endl;
        }

    }
}

void Suggestion::destroy(){
    delete trie;
}
