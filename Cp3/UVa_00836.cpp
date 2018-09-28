#include <bits/stdc++.h>
using namespace std;

long arr[30][30], N;

void read_string(string input, long row){
    
    for(long i=0; i<N; i++){
        ( (input[i]-'0')==1 )? arr[row][i]=1:arr[row][i]=INT_MIN ;
        if(row>0) arr[row][i] += arr[row-1][i];
        if(i>0) arr[row][i] += arr[row][i-1];
        if(i>0 && row>0) arr[row][i] -= arr[row-1][i-1];
    }
}


int main(int argc, char const *argv[])
{
    long TC, ans, temp;
    string input;
    cin>>TC;
    while(TC--){
        cin>>input;
        N = long(input.size());
        read_string(input, 0);
        for(long i=1; i< N; i++){
            cin>>input;
            read_string(input, i);
        }
        
        ans =INT_MIN;
        
        for(long i1=0; i1<N; i1++) for(long j1=0; j1<N; j1++) for(long i2=i1; i2<N; i2++) for(long j2=j1; j2<N; j2++){
            temp=arr[i2][j2];
            
            if(i1>0) temp-= arr[i1-1][j2];
            if(j1>0) temp-= arr[i2][j1-1];
            if(i1>0 && j1>0) temp+=arr[i1-1][j1-1];
            
            ans = max(temp, ans);
            
        }
        
        if(ans>0)cout<<ans<<endl;
        else cout<<'0'<<endl;
        if(TC) cout<<endl;
        
    }
    return 0;
}
