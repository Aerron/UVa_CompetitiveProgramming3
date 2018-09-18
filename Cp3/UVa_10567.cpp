#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int main(int argc, char const *argv[])
{
    string input_str, q_str;
    int TC, start_ind;
    cin>>input_str;
    cin>>TC;
    vector <vi> vec(100);
    
    for(int i=0; i<input_str.size(); i++){
        vec[input_str[i]-'A'].push_back(i);
    }
    
    while(TC--){
        cin>>q_str;
        int ind = -1;
        bool f_tra = true;
        for(auto a: q_str){
            auto lower_in = upper_bound(vec[a-'A'].begin(), vec[a-'A'].end(), ind);
            if( lower_in== vec[a-'A'].end() ){
                f_tra = false;
                break;
            }
            if(ind==-1){
                start_ind = *lower_in;
            }
            ind = *lower_in;
        }
        if(f_tra)
            cout<< "Matched "<< start_ind<< " "<< ind<<endl;
        else
            cout<<"Not matched"<<endl;
        
    }
    
    return 0;
}

