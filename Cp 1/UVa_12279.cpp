#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int TC, sum, num, i=0;
	while(cin>>TC, TC){
		sum = 0;
		cout<< "Case "<< ++i <<": ";
		while(TC--){
			cin>>num;
			(num>0)?sum++: sum-- ;
		}
		cout<< sum<< endl;
	}
	return 0;
}


