#include <bits/stdc++.h>
using namespace std;


int x[12], y[12],memo[12][1<<12], dist[12][12], n;



int tsp(int pos, int mask){
    if(mask== (1<<(n+1))-1) return dist[pos][0];
    if(memo[pos][mask]!=-1) return memo[pos][mask];
    
    int ans = INT_MAX;
    for(int i=0; i<=n; i++) if( !( (1<<i) & mask))
        ans = min(ans, tsp(i, mask | (1<<i) )+dist[pos][i]);
    return memo[pos][mask]=ans;
    
}

int main(int argc, char const *argv[])
{
	int TC, xsize, ysize;
    cin>>TC;
    
    while(TC--){
        cin>>xsize>>ysize>>x[0]>>y[0]>>n;
        for(int i=1; i<=n; i++) cin>>x[i]>>y[i];
        
        for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dist[i][j]= abs(x[i]-x[j])+abs(y[i]-y[j]);
        memset(memo, -1, sizeof memo);
        cout<<"The shortest path has length "<<tsp(0,1)<<endl;
        
    }
    
    return 0;
}
