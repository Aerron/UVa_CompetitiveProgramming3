#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string K;
	while(getline(cin, K), K!="#"){
		if(next_permutation(K.begin(), K.end())){
			cout<< K<< endl;
		}
		else
			cout<< "No Successor"<<endl;
	}
	return 0;
}