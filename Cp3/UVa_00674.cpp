#include <bits/stdc++.h>
using namespace std;

int memo[6][8000],arr[5]= {1,5,10,25,50};

int dp(int index, int value){
    
    if(value==0) return 1;
    if( value<0 || index<0) return 0;
    if (memo[index][value]!=-1) return memo[index][value];
    
    return memo[index][value] = dp(index-1,value)+dp(index, value-arr[index]);
}

int main(int argc, char const *argv[])
{
    int value;
    memset(memo, -1, sizeof memo);
    while(scanf("%d", &value)!=EOF){
        cout<<dp(4,value)<<endl;
    }
    return 0;
}
