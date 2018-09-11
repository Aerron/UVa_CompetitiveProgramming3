#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int TC, rel, input, mid, sum;
	vector <int> vec;
	cin>> TC;
	while(TC--){
		sum = 0;
		vec.clear();
		cin>>rel;
		while(rel--){
			cin>>input;
			vec.push_back(input);
		}

		sort(vec.begin(), vec.end());

		if(vec.size()&1) mid = vec[vec.size()/2];
		else
			mid = (vec[vec.size()/2]+vec[vec.size()/2 -1])/2;
		for(auto a: vec){
			sum+= abs(a - mid);
		}	
		cout<< sum<<endl;
	}
	return 0;
}