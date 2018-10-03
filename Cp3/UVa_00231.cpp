#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<long> vec;
    vector<long> L;
    long input, n, lis, case_val=0;
    while(cin>>input, input!=-1){
        if(case_val++) cout<<endl;
        vec.clear();
        vec.push_back(input);
        
        while(cin>>input, input!=-1){
            vec.push_back(input);
            
        }
        reverse(vec.begin(), vec.end());
        n=vec.size();
        
        L.clear();
        
        lis=0;
        for(long i=0; i<n; i++){
            long pos = upper_bound(L.begin(), L.end(), vec[i])-L.begin();
            
            if(pos+1<=lis) L[pos]= vec[i];
            else {L.push_back(vec[i]);lis++;}
        }
        
        cout<<"Test #"<<case_val<<":\n  "<<"maximum possible interceptions: "<<lis<<endl;
    }
    return 0;
}
