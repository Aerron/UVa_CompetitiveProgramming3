#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, total_space, min_val, lines, spaces;
    string input;
    while(scanf("%d\n", & N), N){
        min_val = 25;
        total_space = 0;
        lines = N;
        while(N--){
            getline(cin, input);
            spaces = 25 - count(input.begin(), input.end(), 'X');

            if(min_val > spaces) min_val = spaces;

            total_space += spaces;
            // cout << input << " "<<spaces<< " " << min_val<< " "<< total_space<< " "<< N << " " << endl;
        }
        cout<< total_space - (lines* min_val) << endl;
    }
    return 0;
}
