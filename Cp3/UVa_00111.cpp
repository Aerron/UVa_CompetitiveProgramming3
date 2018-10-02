#include <bits/stdc++.h>
using namespace std;

long rank_map[25], L[25], N, arr[25], max_val;



int main(int argc, char const *argv[])
{
    memset(L, -1, sizeof L);
    long input, lis, lis_end;
    scanf("%ld", &N);
    for (long i = 1; i <= N; ++i)
    {
        cin>>input;
        rank_map[input] = i;
    }
    
    while(scanf("%ld", &input)==1){
        
        arr[1] = rank_map[input];
        for (long i = 2; i <=N ; ++i)
        {
            cin>>input;
            arr[i]=rank_map[input];
        }
        
        lis=lis_end=0;
        for(long i=1; i<=N; i++){
            long pos = lower_bound(L, L+lis, arr[i])-L;
            L[pos]=arr[i];
            if(pos+1>lis){
                lis=pos+1;
            }
        }
        cout<<lis<<endl;
        
        
        
    }
    
    
    return 0;
}
