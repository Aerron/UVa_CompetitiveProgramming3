#include <bits/stdc++.h>
using namespace std;

typedef pair<long,long> pp;


bool check(long s){
    bitset<10> bit_check;
    long val;
    while(s){
        if(bit_check[s%10])
            return false;
        else
            bit_check[s%10]=true;
        s/=10;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    long number, s1, s2, limit, TC;
    vector <pp> vec;
    cin>> TC;
    while(TC--){
        cin>>number;
        vec.clear();
        limit = 1e10/number;
        for(s2=1; s2<= limit; s2++){
            if(check(s2)){
                s1 = number*s2;
                if(check(s1)){
                    vec.push_back(make_pair(s1,s2));
                }
            }
        }
        sort(vec.begin(), vec.end());

        for(auto a: vec){
        	cout<< a.first<< " / "<< a.second<< " = "<<number<<endl;
        }
        if( TC!=0 )cout<<endl;

    }
    return 0;
}
