#include <bits/stdc++.h>
using namespace std;

long N, K; 
long memo[1125][1125][16];
vector <long> vec_primes;

long dp(long index, long n, long k){

	if(k==0){
		if(n==0) return 1;
		return 0;
	}
	if(n==0 || index<0) return 0;
	if(memo[index][n][k]!=-1) return memo[index][n][k];

	long num=0;
	num += dp(index-1, n, k);
	if(n>=vec_primes[index]) num+=dp(index-1, n-vec_primes[index], k-1);

	return memo[index][n][k]=num;
}

void find_primes(){
	vec_primes.push_back(2);
	long count=0;
	for(long i=3; i<=1120; i++){
		count=0;
		for(auto a= vec_primes.begin(); a!=vec_primes.end() && *a<35; a++ ){
			if(i%*a==0){
				count++;
				break;
			}
		}
		if(count==0) vec_primes.push_back(i);
	}
}

long findindex(long value){
	return  upper_bound(vec_primes.begin(), vec_primes.end(), value)-vec_primes.begin();

}

int main(int argc, char const *argv[])
{
	find_primes();
	fill(&memo[0][0][0], &memo[1125][0][0], -1);
	while(cin>>N>>K, N&&K){
		long index = findindex(N);
		if(index==0) cout<<"0"<<endl;
		else{
			index-=1;
			cout<<dp(index, N, K)<<endl;
		}
	}
	return 0;
}

