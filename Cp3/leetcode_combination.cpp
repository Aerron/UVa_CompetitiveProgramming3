#include <bits/stdc++.h>
using namespace std;

int K, Number;

void Rec(vector<int> vec, int number){
    if(vec.size()==K){
        for(auto a: vec){
            cout<< a<<" ";
        }
        cout<<endl;
        return;
    }
    if(number == Number)
        return;

    //not taking
    Rec(vec, number+1);
    
    //taking
    vec.push_back(number+1);
    Rec(vec, number+1);

    
}


int main(int argc, char const *argv[])
{
    cin>> Number;
    cin>> K;
    vector<int> vec;
    
    Rec(vec, 0);
    return 0;
}