#include<iostream>
#include "extrenal/Suggestion.h"

#define WORD_LIST_FILE_PATH "Put your WORD_LIST_FILE_PATH here"

using namespace std;

int main()
{
    Suggestion *suggestion = new Suggestion();
    suggestion->init(WORD_LIST_FILE_PATH);

    while(1)
    {
        cout<<"Enter any word to get suggestion or 0 to exit "<<endl;
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if(s.compare("0")==0){
            suggestion->destroy();
            cout<<"successfully exited"<<endl;
            break;
        }
        suggestion->getSuggestion(s);
    }
}
