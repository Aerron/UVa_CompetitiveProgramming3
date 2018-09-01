#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int TC, min, max, num, inp;
	cin>>TC;
	while(TC--){
		cin>>num;
		max = INT_MIN;
		min = INT_MAX;
		while(num--){
			cin>>inp;
			if(max<inp)max = inp;
			if(min>inp)min = inp;
		}
		cout<< 2*(max - min)<< endl;
	}
	
	return 0;
}