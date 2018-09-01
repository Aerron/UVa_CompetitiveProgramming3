#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int size,K;
    string input;
    
    while(scanf("%d", &K), K){
        
        cin>> input;
        size = input.length()/K;
        for(auto a= input.begin() ;a!= input.end();){
            reverse(a, a+size);
            a = a+size;
        }
        cout<< input<< endl;
    }
    return 0;
}
