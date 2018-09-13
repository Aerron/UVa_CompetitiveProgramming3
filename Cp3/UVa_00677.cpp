#include <bits/stdc++.h>
using namespace std;


int N, walk_n;
vector <vector <int>> adj_mat;

void Rec(vec <int> taken, int path_len){
	if(){
		return;
	}
	
}


int main(int argc, char const *argv[])
{
	int input;
	vector <int> taken;
	while(cin>>N, N!= -9999){
		cin>>walk_n;
		adj_mat.assign(N, vecto<int> (N,0) );
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin>>input;
				if(input)
					adj_mat[i][j]=1;
			}
		}
		taken.assign(N,0);

		Rec(taken,0);

	}
	return 0;
}