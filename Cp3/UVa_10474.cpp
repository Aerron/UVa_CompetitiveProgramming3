#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,q, input, case_val=0;
    vector <int> vec;
    
    while(cin>>n>>q, n||q){
        cout<< "CASE# "<<++case_val<<":" <<endl;
        vec.clear();
        while(n--){
            cin>>input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        while(q--){
            cin>>input;
            auto lower = lower_bound(vec.begin(),vec.end(),input);
            if(*lower==input){
                cout<<  input<< " found at "<< lower- vec.begin() +1<<endl;
            }
            else
                cout<< input<<" not found"<<endl;
            
        }
    }
    return 0;
}
