#include <bits/stdc++.h>
using namespace std;

long arr[102][102], N, M;


int main(int argc, char const *argv[])
{
    long input, sum, ans;
    while(cin>>M>>N, N&&M){
        for (long i = 0; i < M; ++i)for(int j=0; j<N; j++){
            cin>>input;
            (input==0)?input=1:input=INT_MIN;
            if(i>0) input += arr[i-1][j];
            if(j>0) input += arr[i][j-1];
            if(i>0 && j>0) input-= arr[i-1][j-1];
            arr[i][j]=input;
        }
        sum =0;
        ans =0;
        for (long i = 0; i < M; ++i)for(long j=0; j<N; j++)for(long i1=i; i1<M; i1++)for(long j1=j; j1<N; j1++){
            sum = arr[i1][j1];
            if(i>0) sum-= arr[i-1][j1];
            if(j>0) sum-= arr[i1][j-1];
            if(i>0 && j>0) sum+= arr[i-1][j-1];
            ans = max(ans, sum);
        }
        if(ans<=0) cout<<"0"<<endl;
        else cout<<ans<<endl;
    }
    
    return 0;
}
