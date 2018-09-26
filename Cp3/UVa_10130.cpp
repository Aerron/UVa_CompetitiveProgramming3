#include <bits/stdc++.h>
using namespace std;

int P[1005], W[1005], memo[1005][40];


int dp(int ind, int max_weight){
    if(max_weight==0 || ind <0) return 0;
    if(memo[ind][max_weight]!=-1) return memo[ind][max_weight];
    if( max_weight < W[ind]) return dp(ind-1, max_weight);
    
    return memo[ind][max_weight] = max(P[ind]+dp(ind-1, max_weight-W[ind]), dp(ind-1, max_weight));
}


int main(int argc, char const *argv[])
{
    int TC, N, G, ans, MW;
    
    cin>>TC;
    while(TC--){
        memset(memo, -1, sizeof memo);
        
        cin>>N;
        for (int i = 0; i < N; ++i) cin>>P[i] >>W[i];
        cin>>G;
        
        ans =0;
        while(G--){
            cin>> MW;
            ans += dp(N-1, MW);
        }
        cout<< ans<<endl;
    }
    return 0;
}
