#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int K, input, avg, sum, T=1;
	vector <int> bricks;
	while(scanf("%d", &K), K){
		bricks.clear();
		while(K--){
			cin >> input;
			bricks.push_back(input);
		}
		avg = (accumulate(bricks.begin(),bricks.end(),0))/bricks.size();
		sum = 0;
		for(auto a: bricks){
			sum += abs(a-avg);
		}
		sum /=2;

		cout<< "Set #"<< T<< "\nThe minimum number of moves is "<< sum<< ".\n\n";
		T++;
	}
	return 0;
}
