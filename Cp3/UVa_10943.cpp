#include <bits/stdc++.h>
using namespace std;

int memo[110][110];

int dp(int N, int K){
    if(N<0) return 0;
    if(K==1) return 1;
    if(memo[N][K]!=-1) return memo[N][K];
    
    int ways=0;
    for(int i=0; i<=N; i++) ways = (ways + dp(N-i, K-1))% 1000000;
    return memo[N][K]=ways;
}


int main(int argc, char const *argv[])
{
    int N, K;
    memset(memo, -1, sizeof memo);
    while(cin>>N>>K, N||K){
        
        cout<<dp(N,K)<<endl;
    }
    return 0;
}
