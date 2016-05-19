#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include"Trie.h"
#include "Utils.h"

using namespace std;

inline const char * const BoolToString(bool b)
{
    return b ? "true" : "false";
}

void edits(std::string word, std::vector<string> &result)
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


int main()
{
    Trie* trie = new Trie();

    cout<<"Loading dictionary"<<endl;

    bool isDictionaryLoaded = Utils::loadDictionary(trie,"/Users/amitshekhar/Documents/Development/C++/WordSuggestions/en_wordlist.txt");

    cout<<"isDictionaryLoaded : "<<BoolToString(isDictionaryLoaded)<<endl;

    while(1)
    {
        cout<<"Enter any word to get suggestion or 0 to exit "<<endl;
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if(s.compare("0")==0){
            cout<<"successfully exited"<<endl;
            break;
        }

        int count=0;
        set<string> suggestions;
        vector<string> edit_list;
        if(trie->searchWord(s)){
            cout<<s<<"  found in Dictionary"<<endl;
        }
        else
        {
            edits(s,edit_list);
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
}