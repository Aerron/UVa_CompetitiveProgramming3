#include <bits/stdc++.h>
using namespace std;

long memo[1010];


long dp(int value){
	if(value==0 || value==2) return 1L;
	if(memo[value]!=-1) return memo[value];

	long sum=0;
	for(int j=2; j<=value; j+=2 ){
		sum+=dp(j-2)*dp(value-j);
	}
	return memo[value] = sum;
}


int main(){
	long N;
	memset(memo, -1, sizeof memo);
	while(scanf("%ld",&N)!=EOF)
	    cout<<dp(N)<<endl;
}