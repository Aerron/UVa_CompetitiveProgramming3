#include <bits/stdc++.h>
using namespace std;

int arr[160][160];


int main(int argc, char const *argv[])
{
    int TC, N, ans, sum, input;
    cin>>TC;
    while(TC--){
        cin>>N;
        for (int i = 0; i < N; ++i)for(int j=0; j<N; j++){
            cin>>input;
            arr[i][j]=arr[i][N+j]=arr[N+i][j]=arr[i+N][j+N]=input;
        }
        for(int i=0; i<2*N; ++i )for(int j=0; j<2*N; j++){
            if(i>0)arr[i][j]+=arr[i-1][j];
            if(j>0)arr[i][j]+=arr[i][j-1];
            if(i>0 && j>0) arr[i][j]-=arr[i-1][j-1];
        }
        
        ans = INT_MIN;
        
        for (int i = 0; i < N; ++i)for(int j=0; j<N; j++)for(int i1=i; i1<i+N; i1++)for(int j1=j; j1<j+N; j1++)
        {
            //            cout<< i<<"     ";
            sum = arr[i1][j1];
            if(i>0) sum-= arr[i-1][j1];
            if(j>0) sum-= arr[i1][j-1];
            if(i>0 && j>0) sum+= arr[i-1][j-1];
            ans = max(sum, ans);
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}
