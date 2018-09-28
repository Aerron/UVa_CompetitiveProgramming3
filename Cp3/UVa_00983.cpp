#include <bits/stdc++.h>
using namespace std;

long N, M, arr[1005][1005];

int main()
{
    long total_sum, sum, i1, j1, case_val=0;
    while(scanf("%ld %ld", &N, &M)!=EOF){
        if(case_val++){
            cout<<endl;
        }
        for(long i=0; i<N; i++)for(long j=0; j<N; j++){
            cin>>arr[i][j];
            if(i>0) arr[i][j]+=arr[i-1][j];
            if(j>0) arr[i][j]+=arr[i][j-1];
            if(i>0 && j>0)arr[i][j]-=arr[i-1][j-1];
        }
        total_sum =0;
        for(long i=0; i<N-M+1; i++) for(long j=0; j<N-M+1; j++){
            i1=i+M-1;
            j1=j+M-1;
            sum = arr[i1][j1];
            if(i>0) sum-= arr[i-1][j1];
            if(j>0) sum-= arr[i1][j-1];
            if(i>0 && j>0) sum += arr[i-1][j-1];
            // arr_s[i1][j1]=sum;
//            cout<< i<<"     "<<j<<"      "<<i1<<"        "<<j1<<"        "<<sum<<"      "<<arr[i1][j1]<<endl;
            cout<<sum<<endl;
            total_sum+=sum;
        }
        cout<<total_sum<<endl;
        
    }
    return 0;
}
