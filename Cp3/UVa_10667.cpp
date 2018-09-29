#include <bits/stdc++.h>
using namespace std;

long long arr[110][110];

int main(int argc, char const *argv[])
{
    long TC, N, TCB, a1, a2, b1, b2, ans, sum;
    cin>>TC;
    while(TC--){
        cin>>N;
        cin>>TCB;
        //        memset(arr, 0, sizeof arr);
        
//         for(int i=1; i<=N; i++)for(int j=1; j<=N; j++)arr[i][j]=1;
        fill(&arr[0][0], &arr[0][0]+sizeof(arr), -1);
        //        cout<<endl;
        while(TCB--){
            cin>>a1>>b1>>a2>>b2;
            for (long i = a1; i <=a2; ++i)for(long j=b1; j<=b2; j++){
                arr[i][j]=INT_MIN;
                //                cout<< arr[i][j];
            }
            //            cout<<endl;
        }
        for(long i=1; i<=N; i++)for (long j = 1; j <=N ; ++j)
        {
            //            cout<< arr[i][j]<<",  ";
            if(i>1) arr[i][j] += arr[i-1][j];
            if(j>1) arr[i][j] += arr[i][j-1];
            if(i>1 && j>1) arr[i][j] -= arr[i-1][j-1];
            //            cout<<arr[i][j]<<"    ";
        }
        //        cout<<endl;
        ans = INT_MIN;
        
        for(long i=1; i<=N; i++)for (long j = 1; j <=N ; ++j)for(long i1=i; i1<=N; i1++)for (long j1 = j; j1 <=N ; ++j1){
            sum = arr[i1][j1];
            if(i>1) sum -= arr[i-1][j1];
            if(j>1) sum -= arr[i1][j-1];
            if(i>1 && j>1) sum += arr[i-1][j-1];
            ans = max(ans, sum);
        }
        if(ans>0)cout<<ans<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}
