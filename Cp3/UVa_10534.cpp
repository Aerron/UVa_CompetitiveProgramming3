#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, input;
    vector <int> vec;
    vector <int> Li;
    vector <int> Ld;
    vector <int> L;
    
    while(scanf("%d", &N)!=EOF){
        vec.clear();
        Li.clear();
        Ld.clear();
        for(int i=0; i<N; i++){
            cin>>input;
            vec.push_back(input);
        }
        int lis=0, lds=0;
        
        L.clear();
        for(int i=0; i<N; i++){
            int pos = lower_bound(L.begin(), L.end(), vec[i])-L.begin();
            if(pos+1<=lis)L[pos]=vec[i];
            else {L.push_back(vec[i]);lis++;}
            Li.push_back(pos+1);
            
//            cout<<pos+1<<", ";
        }
        
//        cout<<endl;
        reverse(vec.begin(), vec.end());
        
        L.clear();
        for(int i=0; i<N; i++){
            int pos = lower_bound(L.begin(), L.end(), vec[i])-L.begin();
            if(pos+1<=lds)L[pos]=vec[i];
            else {L.push_back(vec[i]);lds++;}
            Ld.push_back(pos+1);
//            cout<<pos+1<<", ";
        }
//        cout<<endl;
        reverse(Ld.begin(), Ld.end());
        int max_val=0;
        for(int i=0; i<N; i++){
            if(Ld[i]>=Li[i])		max_val = max(max_val, Li[i]);
            else if(Ld[i]<Li[i]) 	max_val = max(max_val, Ld[i]);
            // else if(Li[i]<Ld[i]) 	max_val = max(max_val, Li[i]);

        }
        max_val = 2*max_val-1;
        
        cout<<max_val<<endl;
        
        
    }
    return 0;
}





