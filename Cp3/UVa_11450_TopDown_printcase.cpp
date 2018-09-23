#include <bits/stdc++.h>
using namespace std;

int M,C, price[25][25];
int memo[25][205];




int dp(int g, int money_remaining){

	if(money_remaining<0) return INT_MIN;
	if(g==C) return M-money_remaining;
	int &ans = memo[g][money_remaining];
	
	if(ans!=-1) return ans;
	for(int i=1; i<=price[g][0]; i++){
		ans = max(ans, dp(g+1, money_remaining-price[g][i]) );
	}
	return ans;
}


void print_dp(int g, int money){
	if(g==C || money<0) return;

	for(int i=1; i<=price[g][0]; i++){
		if(dp(g+1,money-price[g][i])==memo[g][money]){
			cout<< price[g][i] <<" ";
			print_dp(g+1, money- price[g][i]);
			break;
		}
	}

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
            cout<< "no solution";
        else
            print_dp(0,M);
        cout<<endl;
        
    }
    return 0;
}


