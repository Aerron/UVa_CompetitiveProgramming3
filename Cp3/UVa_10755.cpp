#include <bits/stdc++.h>
using namespace std;

long TC, A, B, C, arr[25][25][25], ans, sum;



int main(int argc, char const *argv[])
{
    long temp_sum;
    cin>>TC;
    while(TC--){
        cin>>A>>B>>C;
        for(long i=1; i<=A; i++)for(long j=1; j<=B; j++)for(long k=1; k<=C; k++){
            cin>>arr[i][j][k];
            if(j>1) arr[i][j][k]+= arr[i][j-1][k];
            if(k>1) arr[i][j][k]+= arr[i][j][k-1];
            if(j>1 && k>1) arr[i][j][k] -= arr[i][j-1][k-1];
        }
        ans = INT_MIN;
        for(long j1=1;  j1<=B; j1++)for(long k1=1; k1<=C; k1++)for(long j2=j1; j2<=B; j2++) for(long k2=k1; k2<=C; k2++){
            sum =0;
            for (long i = 1; i<=A; ++i)
            {
                temp_sum = arr[i][j2][k2];
                if(j1>1) temp_sum -= arr[i][j1-1][k2];
                if(k1>1) temp_sum -= arr[i][j2][k1-1];
                if(j1>1 && k1>1) temp_sum += arr[i][j1-1][k1-1];
                sum+= temp_sum;
                ans = max(ans, sum);
                if(sum<0) sum=0;
            }
        }
        cout<<ans<<endl;
        if(TC) cout<<endl;
    }
    
    return 0;
}
