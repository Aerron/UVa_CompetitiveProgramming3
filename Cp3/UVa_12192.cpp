#include <bits/stdc++.h>
using namespace std;


typedef vector <int> vi;

int main(int argc, char const *argv[])
{
    vector <vi> vec(500);
    int N, M, TC, L, U, input, index, bestsize;
    
    while(scanf("%d %d",&N,&M), N||M){
        vec.assign(500, vector<int>());
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>input;
                vec[i].push_back(input);
            }
        }
        
        cin>>TC;
        while(TC--){
            cin>>L>>U;
            bestsize=-1;
            
            for(int i=0; i<N; i++){
                auto lower = lower_bound(vec[i].begin(), vec[i].end(), L);
                if(lower!=vec[i].end()){
                    index = int(lower-vec[i].begin());
                    for(int j=bestsize+1; j<N; j++){
                        if( (i+j)>(N-1) || (index+j)>(M-1) ||  vec[i+j][index+j]>U )
                            break;
                        else
                            bestsize= j;
                    }
                }
                
            }
            cout<<bestsize+1<<endl;
        }
        
        cout<<"-"<<endl;
    }
    
    return 0;
}
