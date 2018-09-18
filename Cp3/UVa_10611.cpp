#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, Q, h, input;
    vector <int> vec;
    
    cin>>N;
    while(N--){
        cin>>input;
        vec.push_back(input);
    }
    
    cin>>Q;
    while(Q--){
        cin>>input;
        auto lower_val = lower_bound(vec.begin(), vec.end(), input );
        auto upper_val = upper_bound(vec.begin(), vec.end(), input);
        if(lower_val !=vec.begin() && *(lower_val-1)<input )
            cout<< *(lower_val-1)<<" ";
        else
            cout<< "X ";
        if( *upper_val>input )
            cout<< *(upper_val)<<endl;
        else
            cout<< "X\n";
    }
    return 0;
}
