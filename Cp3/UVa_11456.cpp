#include <bits/stdc++.h>
using namespace std;

int vec[2500], L[2500], D[2500];

int TC, N;

int main(){
    cin>>TC;
    while(TC--){
        cin>>N;
        for(int i=0; i<N; i++){cin>>vec[i];}
        
        for(int i=N-1; i>=0; i--){
            L[i]=1;
            for(int j=i+1; j<N; j++){
                if(vec[i]>vec[j])L[i]=max(L[i], L[j]+1);
            }
        }
        for(int i=N-1; i>=0; i--){
            D[i]=1;
            for(int j=i+1; j<N; j++){
                if(vec[i]<vec[j])D[i]=max(D[i], D[j]+1);
            }
        }
        int max_val=0;
        for(int i=0; i<N; i++){
            max_val=max(max_val, L[i]+D[i]-1);
        }
        cout<<max_val<<endl;
    }
}
