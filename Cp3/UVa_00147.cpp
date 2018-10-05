#include <bits/stdc++.h>
using namespace std;

long coinValue[11]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long memo[12][30010];
long N=11;

long dp(long type, long value){
  if (value == 0)              return 1;
  if (value < 0 || type == N)  return 0;
  if (memo[type][value] != -1) return memo[type][value];
  return memo[type][value] = dp(type + 1, value) + dp(type, value - coinValue[type]);
}



int main(int argc, char const *argv[]){
	double value;
	long long_value;
	
	memset(memo, -1, sizeof memo);
	while(scanf("%lf", &value), value){
		// cout<<value<<", "<<(value+0.001)*100.00<<endl;
		long_value =(long)( (value+0.001)*100.00);
		// cout<<long_value<<endl;
		long ways = dp(0,long_value);

		cout.fill(' ');
		cout<< setw(6)<< setprecision(2)<< fixed<< value<< setw(17)<< ways<< endl;
	}
	return 0;
}