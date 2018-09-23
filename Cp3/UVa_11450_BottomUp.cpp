#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int TC;
    int M,C, price[25][25], curr, index, last_index, last_index_1;
    bool memo[2][205];
    cin>>TC;
    while(TC--){
        cin>>M>>C;
        for(int i=0; i<C; i++){
            cin>>price[i][0];
            for(int j=1; j<=price[i][0]; j++) cin>>price[i][j];
        }
        
        memset(memo, false, sizeof memo );
        
        last_index=0;
        for(int i=1;i<=price[0][0]; i++ ){
            if( (M-price[0][i])>=0 ){
                memo[0][M-price[0][i]] = true;
                last_index=max(M-price[0][i], last_index);
            }
        }
        curr =1;

        for(int i=1; i<C; i++){
            memset(memo[curr], false, sizeof memo[curr]);
            for(int j=0; j<=last_index; j++) if(memo[!curr][j])
                for(int k=1; k<=price[i][0]; k++)if(j-price[i][k] >=0 ){
                    memo[curr][j-price[i][k]]=true;
                    last_index_1=max(j-price[i][k], last_index_1);
                }
            last_index=last_index_1;
            curr = !curr;
        }
        
        for(index=0; index<M && !memo[!curr][index] ; index++);
        
        if(index==M) cout<< "no solution";
        else
            cout<< M-index;
        cout<<endl;
        
    }
    return 0;
}


