#include <bits/stdc++.h>
using namespace std;

typedef pair<long, long> pp;


int main(int argc, char const *argv[])
{
	vector <long> vec_h;
	vector <long> vec_w;
	vector <long> L;
	vector <long> D;
	long TC, N, input_H, input_W, case_val=0;
	cin>>TC;
	while(TC--){
		vec_h.clear(); vec_w.clear(); L.clear(); D.clear();
		cin>>N;
		for(int i=0; i<N; i++){
			cin>>input_H;
			vec_h.push_back(input_H);
		}
		for(int i=0; i<N; i++){
			cin>>input_W;
			vec_w.push_back(input_W);
		}

		
		long lis=0, lds=0;
		for(int i=0; i<N; i++){
			L.push_back(vec_w[i]);
			for(int j=0; j<i; j++) if(vec_h[i]>vec_h[j])
				L.at(i)= max(L.at(i), vec_w[i]+L.at(j));
			lis=max(lis, L.at(i));
		}

		for(int i=0; i<N; i++){
			D.push_back(vec_w[i]);
			for(int j=0; j<i; j++) if(vec_h[i]<vec_h[j])
				D.at(i)= max(D.at(i), vec_w[i]+D.at(j));
			lds= max(lds, D.at(i));
		}

		if(lis>=lds)
			cout<< "Case "<<++case_val<<". Increasing ("<<lis<<"). Decreasing ("<<lds<<")."<<endl;
		else
			cout<< "Case "<<++case_val<<". Decreasing ("<<lds<<"). Increasing ("<<lis<<")."<<endl;

	}
	return 0;
}