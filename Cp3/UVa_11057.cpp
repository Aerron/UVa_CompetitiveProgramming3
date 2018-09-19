#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> vec;
    int N, M, input;
    int i_val,j_val, diff;
    
    while(scanf("%d", &N)!=EOF){
        vec.clear();
        while(N--){
            cin>>input;
            vec.push_back(input);
        }
        cin>>M;
        sort(vec.begin(), vec.end());
        diff=INT_MAX;
        for(auto a: vec){
            if(M<2*a)
                break;
            else if(M==2*a){
                auto lower = lower_bound(vec.begin(), vec.end(), a);
                if( *(lower+1)==a ){
                    i_val=j_val=a;
                    diff=0;
                    break;
                }
            }
            else{
                auto found = binary_search(vec.begin(),vec.end(),M-a);
                if(found){
                    if( (M-2*a)<diff ){
                        i_val=a;
                        j_val=M-a;
                        diff = M-2*a;
                    }
                }
            }
            
        }
        cout<< "Peter should buy books whose prices are "<<i_val<< " and " <<j_val<<".\n"<<endl;
        
    }
    return 0;
}
