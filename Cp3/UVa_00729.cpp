#include <bits/stdc++.h>
using namespace std;

int N, H;


void Rec(vector<int> taken, int pos){
    if(pos==N){
        if(accumulate(taken.begin(), taken.end(),0, plus<int>())==H ){
            for(auto a: taken){
                cout<<a;
            }
            cout<<endl;
        }
        return;
    }
    Rec(taken, pos+1);
    taken[pos]=1;
    Rec(taken, pos+1);
    return;
}
int main(int argc, char const *argv[])
{
    int TC,s=1;
    cin>>TC;
    vector <int> taken;
    while(scanf("%d %d",&N,&H)!=EOF){
        if(s!=1){
            cout<<endl;
        }
        s++;
        taken.assign(N,0);
        Rec(taken, 0);
    }
    return 0;
}
