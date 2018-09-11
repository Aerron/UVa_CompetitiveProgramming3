#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int TC, cases, sum, input;
	vector <int> vec;
	scanf("%d", &TC);
	
	while(TC--){
		sum = 0;
		vec.clear();
		cin>> cases;

		while(cases--){
			cin>>input;
			
			for(auto a: vec){
				if(a<=input)sum+=1;
			}
			vec.push_back(input);
		}
		cout<<sum<<endl;
	}
	return 0;
}