#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, input, max_val, temp_sum;
	int arr[105][105];
	cin>>N;
	for(int i=0; i<N; i++)for(int j=0; j<N; j++){
		cin>>input;
		arr[i][j]=input;
		if(i>0) arr[i][j]+= arr[i-1][j];
		if(j>0) arr[i][j] += arr[i][j-1];
		if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
	}	
	max_val = INT_MIN;
	for(int i1=0; i1<N; i1++)for(int j1=0; j1< N; j1++) for(int i2=i1; i2<N; i2++) for(int j2=j1; j2< N; j2++){
		temp_sum = arr[i2][j2];
		if(i1>0) temp_sum -= arr[i1-1][j2];
		if(j1>0) temp_sum -= arr[i2][j1-1];
		if(i1>0 && j1>0) temp_sum += arr[i1-1][j1-1];
		max_val = max(temp_sum, max_val);
	}
	cout<< max_val<<endl;;

	return 0;
}
