#include <bits/stdc++.h>
using namespace std;


long TC, N, T;
long arr[110], memo[110][50100];

long dp(int index, int value_rem){

	if(index<0 || value_rem==0) return 0;
	if(memo[index][value_rem]!=-1) return memo[index][value_rem];
	if(value_rem<arr[index]) return memo[index][value_rem]=dp(index-1, value_rem); 
	return memo[index][value_rem]=max(dp(index-1, value_rem), dp(index-1, value_rem-arr[index])+arr[index]);

}


int main(int argc, char const *argv[])
{
	int case_val=0;
	cin>>TC;
	while(TC--){
		// if(case_val++) cout<<endl;
		memset(memo, -1, sizeof memo);
		cin>>N;
		int sum=0;
		for(long i=0; i<N; i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		T=sum/2;
		int diff = dp(N-1, T);
		cout<<sum-2*diff<<endl;

	}
	return 0;
}