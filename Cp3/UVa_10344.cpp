#include <bits/stdc++.h>
using namespace std;

int arr[5];
bool poss;

void rec(vector<int> taken, int num_taken, int val){
    if(num_taken==5){
        if(val ==23)
            poss = true;
        return;
    }
    if(num_taken==0){
        
        for(int i=0; i<5; i++){
            taken[i]=1;
            rec(taken, 1, arr[i]);
            taken[i]=0;
        }
        return;
    }
    
    for(int i=0; i<5; i++){
        if(taken[i]==0){
            taken[i]=1;
            rec(taken,num_taken+1, val*arr[i] );
            rec(taken,num_taken+1, val-arr[i] );
            rec(taken,num_taken+1, val+arr[i] );
            taken[i]=0;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    vector <int> taken(5,0);
    int val=0;
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4], (arr[0] || arr[1] || arr[2] || arr[3] || arr[4]) ){
        poss = false;
        taken.assign(5,0);
        rec(taken,0, val);
        if (poss)
            cout<< "Possible"<<endl;
        else
            cout<< "Impossible"<<endl;
    }
    return 0;
}
