#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v(3);
	int TC, i =0;
	cin >>TC;
	while(cin>>v[0]>>v[1]>>v[2],TC--){
		sort(v.begin(), v.end());
		cout<< "Case "<< ++i << ": " <<v[1]<< endl;
	}
	return 0;
}