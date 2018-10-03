#include <bits/stdc++.h>
using namespace std;



vector <vector<long>> vec;
vector <long> L;
vector <long> P;

bool cmp(vector<long> l1, vector<long> l2){
    return l1[1]>l2[1];
}

void print_f(long index){
    if(index<0) return;
    print_f(P[index]);
    cout<<vec[index][2]<<endl;
    return;
}

int main(int argc, char const *argv[])
{
    
    long N, w, iq, ind=1;
    vector <long> temp;
    while(scanf("%ld %ld", &w, &iq)!=EOF){
        temp.clear();
        temp.insert(temp.end(),{w,iq,ind++});
        vec.push_back(temp);
    }
    
    N=vec.size();
    
    sort(vec.begin(), vec.end(), cmp);
    long index,lis_end=0,lis=0;
    for(long i=0; i<N; i++){
        index=0;
        long max_val=0;
        for(long j=0; j<i; j++){
            if(vec[j][0]<vec[i][0] && vec[i][1]<vec[j][1]){
                if(max_val<=L[j]){max_val=L[j];index=j;}
            }
        }
        
        L.push_back(max_val+1);
        (max_val!=0)?P.push_back(index):P.push_back(-1);
        if(lis<max_val+1){lis=max_val+1; lis_end=i;}
    }
    cout<<lis<<endl;
    print_f(lis_end);
    
    return 0;
}
