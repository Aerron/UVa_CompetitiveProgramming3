#include <bits/stdc++.h>
using namespace std;


// Top Down DP

vector <int> vec;
int memo[100];

// int lis(int ind){
    
//     if(ind<0) return 0;
//     if(memo[ind]!=-1) return memo[ind];
    
//     int max_val = 1;
//     for (int i = 0; i < ind; ++i) 
//     	if(vec[i]<vec[ind]) max_val = max(max_val, 1+lis(i));
//     	else max_val = max(max_val, lis(i));
//     return memo[ind]=max_val;
// }

int main(int argc, char const *argv[])
{
    int TC, N, input;
    
    
    cin>>TC;
    while(TC--){
        vec.clear();
        memset(memo, -1, sizeof(memo));
        cin>>N;
        for (int i = 0; i < N; ++i){ cin>>input; vec.push_back(input); }
        cout<< lis(N-1)<<endl;
    }

    return 0;
}







