#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    unordered_map <int,int> hash_set;
    vector <int>vec;
    int number, input;
    char remv;
    bool found_pair;
    while(cin>> number, number){
        cin>> remv;
        vec.clear();
        hash_set.clear();
        found_pair=true;
        
        for(int i=0; i<number;i++){
            cin>>input;
            hash_set[input]=i;
            vec.push_back(input);
        }
        
        for(int i=0; i<number && found_pair ;i++ ){
            for(int j=i+1; j<number; j++){
                
                if(hash_set.find( 2*vec[j]-vec[i] )!=hash_set.end()){
                    if(hash_set[2*vec[j]-vec[i]]>j) found_pair=false;
                }
            }
        }
        if(found_pair)
            cout<< "yes"<<endl;
        else
            cout<<"no"<<endl;
        
        
    }
    return 0;
}
