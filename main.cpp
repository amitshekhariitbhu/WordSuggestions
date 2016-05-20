#include<iostream>
#include "Suggestion.h"

using namespace std;

int main()
{
    Suggestion *suggestion = new Suggestion();
    suggestion->init("/Users/amitshekhar/Documents/Development/C++/WordSuggestions/en_wordlist.txt");

    while(1)
    {
        cout<<"Enter any word to get suggestion or 0 to exit "<<endl;
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if(s.compare("0")==0){
            cout<<"successfully exited"<<endl;
            suggestion->destroy();
            break;
        }
        suggestion->getSuggestion(s);
    }
}