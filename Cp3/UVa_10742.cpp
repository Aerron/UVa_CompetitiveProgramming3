#include <bits/stdc++.h>
using namespace std;

vector <int> vec;


bool isprime(int value){
    for(auto a: vec){
        if(value%a==0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int value, number_types, max_val, case_val=0;
    vec.insert(vec.end(), {2,3,5,7});
    
    for(int i=11; i<1000000; i++){
        if(isprime(i)){
            vec.push_back(i);
        }
    }
    
    while(scanf("%d", &value), value){
        case_val++;
        number_types =0;
        for(int i=0;  vec[i]<value&& i<vec.size(); i++){
            max_val = value- vec[i];
            if(max_val>vec[i]){
                auto upper = upper_bound(vec.begin(), vec.end(), max_val);
                if(*upper==max_val)
                    number_types += (upper-(vec.begin()+i));
                else
                    number_types += (upper-1-(vec.begin()+i));
//            cout<<number_types<<" "<<vec[i]<<endl;
            }
        }
        cout<<"Case "<<case_val<<": "<<number_types<<endl;
    }
    return 0;
}
