#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int TC, inp;
	cin >> TC;
	while(cin >> inp,TC--){
		cout << ( (abs((((((inp*567)/9)+7492)*235)/47) - 498)/10)%10) << endl;
	}
	return 0;
}