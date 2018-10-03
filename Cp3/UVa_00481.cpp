#include <bits/stdc++.h>
using namespace std;


std::vector<long> P;
std::vector<long> vec;

void print_f(long index){
    
    if(index==-1) return;
    print_f(P[index]);
    cout<<vec[index]<<endl;
}


int main(int argc, char const *argv[])
{
    
    std::vector<long> L;
    std::vector<long> L_id;
    long N,input;
    
    while(scanf("%ld", &input)!=EOF){
        vec.push_back(input);
    }
    N=vec.size();
//    cout<<"t1"<<endl;
    //TLE
    // long index, max_val,max_value=0, max_index,lis=0;
    // for(long i=0; i<N; i++){
    //     max_val=0;
    //     index=0;
    //     for(int j=0; j<i; j++){
    //         if(vec[i]>vec[j] && max_val<=L[j]){index=j;max_val=L[j];}
    //     }
    //     L.push_back(max_val+1);
    //     (max_val!=0) ? P.push_back(index):P.push_back(-1);
    //     if(max_value<=L[i]){max_value=L[i];max_index=i;}
    // }
    // cout<<max_value<<"\n-"<<endl;
    // print_f(max_index);

    //nlog(n)
    int lis=0, lis_end;
    for(long i=0; i<N; i++){
//        cout<<i<<endl;
        int pos = lower_bound(L.begin(), L.end(), vec[i])-L.begin();
        
        if(pos+1<=lis) {L[pos]= vec[i];L_id[pos]=i;}
        else {L.push_back(vec[i]);lis++;L_id.push_back(i); lis_end=i;}
        
        if(pos+1==lis) lis_end=i;
        
        P.push_back( (pos>0)? L_id.at(pos-1): -1);
//        if(pos>0)cout<<P[i]<<", "<<pos<<", "<<L_id.at(pos-1)<<endl;
    }
//    cout<<1<<endl;
    cout<<lis<<"\n-"<<endl;
    print_f(lis_end);
    
    return 0;
}


