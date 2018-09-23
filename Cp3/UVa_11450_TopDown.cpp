#include <bits/stdc++.h>
using namespace std;

int M,C, price[25][25];
int memo[25][205];


int dp(int g, int money_remaining){
    if(money_remaining<0) return INT_MIN;
    if(g==C) return M-money_remaining;
    if(memo[g][money_remaining]!=-1) return memo[g][money_remaining];
    
    int ans = -1;
    for(int i=1; i<=price[g][0]; i++){
        ans = max(ans, dp(g+1, money_remaining-price[g][i]));
    }
    return memo[g][money_remaining]=ans;
    
}



int main(int argc, char const *argv[])
{
    int TC, money_spent;
    cin>>TC;
    while(TC--){
        cin>>M>>C;
        for(int i=0; i<C; i++){
            cin>>price[i][0];
            for(int j=1; j<=price[i][0]; j++) cin>>price[i][j];
        }
        memset(memo, -1, sizeof memo);
        money_spent= dp(0, M);
        if(money_spent<0)
            cout<< "no solution"<<endl;
        else
            cout<< money_spent<<endl;
        
    }
    return 0;
}
