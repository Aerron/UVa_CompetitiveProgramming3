#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    std::vector< long> vec;
    
    long limi = pow(2,31);
    
    long val, input;
    
    for(int i=0; i<32; i++){
        for(int j=0; j<32; j++){
            val = pow(2,i)*pow(3,j);
            if(val<=limi){
                vec.push_back(val);
            }
        }
    }
    
    sort(vec.begin(), vec.end());
//    for(auto a: vec){
//        cout<<a<<", ";
//    }
//    cout<<endl;
    while(cin>>input, input){
        auto upper = upper_bound(vec.begin(), vec.end(), input );
        if(*(upper-1)==input)
            cout<<input<<endl;
        else
            cout<< *upper<<endl;
    }
    
    return 0;
}
