#include <bits/stdc++.h>
using namespace std;

int rank_map[25], lis[2][25], N, arr[25], max_val;


// int dp(int ind){
//     if(ind<0) return 0;
//     if(lis[ind-1]==-1) int prev = dp(ind-1);
//     if(lis[ind]!=-1) return lis[ind];
//     max_val = max(max_val, prev);
//     int ans =1;
//     for(int i=ind; i>0; i--){
//         if(arr[i]<arr[ind]) ans = max(ans, 1+dp(i));
//     }
//     max_val = max(max_val, ans);
//     return lis[ind] = ans;
// }

int main(int argc, char const *argv[])
{
    int input, curr, count;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        cin>>input;
        rank_map[input] = i;
    }
    
//    cout<<"test1"<<endl;
    while(scanf("%d", &input)==1){
        memset(lis, -1, sizeof lis);
        arr[1] = rank_map[input];
        for (int i = 2; i <=N ; ++i)
        {
            cin>>input;
            arr[i]=rank_map[input];
        }
        max_val = 1;
        // dp(N);
        for(int i=1; i<=N; i++){
            lis[0][i]=1;
        }
        curr=1;
        count=N;
//        cout<<"test2"<<endl;
        for(int j=2; j<=N && count>0; j++){
            memset(lis[curr], 0, sizeof lis[curr]);
            count=0;

            for(int i=1; i<=N; i++) if(lis[!curr][i])
                    for(int k=i+1; k<=N; k++) if(arr[i]<arr[k]){
                            lis[curr][k]=1;
                            // max_val=j;
                            count++;
                        }
            
            curr=!curr;
            if(count>0) max_val++;
//            cout<<"test3"<<endl;
        }
        cout<<max_val<<endl;
        
    }
    
    
    return 0;
}
