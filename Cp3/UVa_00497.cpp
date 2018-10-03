#include <bits/stdc++.h>
using namespace std;


vector <long> vec;
vector <long> P;
vector <long> L;
vector <long> L_id;

void prlong_f(long index){
    if(index<0) return;
    prlong_f(P[index]);
    cout<<vec[index]<<endl;
}

int main(int argc, char const *argv[])
{
    string input;
    long TC, N, case_val=0;
    cin>>TC;
    getline(cin, input);
    cin.ignore();
    while(TC--){
    	if(case_val++) cout<<endl;
        vec.clear();
        P.clear();
        L.clear();
        L_id.clear();
        while(getline(cin,input), !input.empty()){
//            cout<<"t1"<<endl;
            vec.push_back(stoi(input));
        }
        N=vec.size();
//        cout<<N<<endl;
        
        long lis=0, lis_end=0 ;
        
        for(long i=0; i<N; i++){
            long pos= lower_bound(L.begin(), L.end(), vec[i])-L.begin();
            
            if(pos+1<=lis){L[pos]=vec[i];L_id[pos]=i;}
            else{L.push_back(vec[i]);L_id.push_back(i);lis++;lis_end=i;}
//            if(pos+1==lis) lis_end=i;
            P.push_back((pos==0)?-1:L_id.at(pos-1));
        }
        cout<<"Max hits: "<<lis<<endl;
        prlong_f(lis_end);
        // cout<<endl;
    }
    return 0;
}
