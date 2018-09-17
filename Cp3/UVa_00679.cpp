#include <bits/stdc++.h>
using namespace std;

unsigned int pos(int depth, int number){
    unsigned int rev = 0;
    
    while(depth--){
        rev = (rev<<1) | (number&1);
        number>>=1;
    }
    return rev;
}

int main(int argc, char const *argv[])
{
    unsigned int TC, depth, n;
    cin>>TC;
    while(TC--){
        cin>> depth>> n;
        cout<< (1<<(depth-1))+(pos(depth-1, n-1))<<endl;
    }
    return 0;
}
