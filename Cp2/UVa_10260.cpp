#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    char alp[27] = "01230120022455012623010202";
    while(getline(cin, input)){
        // input = toupper(input);
        for(auto a= input.begin(); a!=input.end(); a++){
            *a = alp[*a-'A'];
        }
        auto last = unique(input.begin(), input.end() );
        input.erase(last, input.end());
        input.erase( remove(input.begin(), input.end(), '0') , input.end());
        cout<< input<<endl;
    }
    return 0;
}
