#include <bits/stdc++.h>
using namespace std;

int memo[55][55], arr[55], N, l;


int dp(int left, int right){
    if(right==left+1) return 0;
    if(memo[left][right]!=-1) return memo[left][right];
    
    int ans = INT_MAX;
    for(int i=left+1; i<right; i++)
        ans = min(ans, (dp(left,i)+dp(i,right))+arr[right]-arr[left] );
    
    return memo[left][right] = ans;
}

int main(int argc, char const *argv[])
{
    while(cin>>l, l){
        cin>>N;
        arr[0]=0;
        for (int i = 1; i <= N; ++i) cin>>arr[i];
        arr[N+1]= l;
        memset(memo, -1, sizeof memo);
        cout<< "The minimum cutting is "<<dp(0,N+1)<<"."<<endl;
    }
    
    return 0;
}
