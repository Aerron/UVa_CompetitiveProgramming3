#include <bits/stdc++.h>
using namespace std;


long depth[31], tim[31], gold[31];
long arr[31], memo[31][1001], picked[31][1001];
long t, weight, N, recovered_items;
vector <pair<long, long>> vec;

long dp(long index, long tim_left){
    if(index<0) return 0;
    if( tim_left==0) {picked[index][tim_left]=-1;return 0;}
    if(memo[index][tim_left]!=-1) return memo[index][tim_left];
    if(tim_left<tim[index]) {picked[index][tim_left]=-1;return dp(index-1, tim_left);}

    if(dp(index-1, tim_left) < dp(index-1, tim_left-tim[index])+gold[index] ){
        picked[index][tim_left]=1;
        memo[index][tim_left]=dp(index-1, tim_left-tim[index])+gold[index];
    }
    else{
        picked[index][tim_left]=-1;
        memo[index][tim_left]=dp(index-1, tim_left);
    }
    return memo[index][tim_left];
}


void print_f(long index, long tim_left){
    if(index<0 || tim_left<=0) return;
    if(picked[index][tim_left]==1){
        vec.push_back(make_pair(depth[index],gold[index]));
        recovered_items++;
        print_f(index-1, tim_left-tim[index] );
        return;
    }
    else
        print_f(index-1, tim_left);


}

void print_all(){
    reverse(vec.begin(), vec.end());
    for(auto a: vec){
        cout<<a.first<<" "<<a.second<<endl;
    }
}

int main(int argc, char const *argv[])
{
	int case_val=0;
    while(scanf("%ld %ld", &t, &weight)!=EOF){

    	if(case_val++) cout<<endl;
        scanf("%ld",&N);
        memset(memo, -1, sizeof memo);
        memset(picked, 0, sizeof picked);
        for(long i=0; i<N; i++){
            // cin>>depth[i]>>gold[i];
            scanf("%ld %ld",&depth[i], &gold[i] );
            tim[i]=3*weight*depth[i];
        }

        int coll=dp(N-1, t);
        vec.clear(); recovered_items=0;
        cout<<coll<<endl;
        print_f(N-1, t);
        cout<<recovered_items<<endl;
        print_all();
        
    }
    
    return 0;
}