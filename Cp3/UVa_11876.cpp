#include <bits/stdc++.h>
using namespace std;


int noffac(int val){
    int limit, sum = 0;
    limit = (int)sqrt(val);
    
    for (int i = 2; i <= limit; i++)
        if (val%i==0) sum++;
    sum *= 2;
//    cout<<endl;
//    cout<<limit<<" "<<sqrt(val)<<" "<<val<< " "<<sum<<endl;
    if (limit-sqrt(val)==0) sum--;
    
    return sum+2;
}


int main(int argc, char const *argv[])
{
    vector <int> vec;
    int TC, A,B, test_case=0;
    vec.insert(vec.end(),{1, 2, 4, 7, 9, 12, 18});
    int val =18;
//    for(auto a: vec){
//        cout<< a<<" ";
//    }
//    cout<<endl;
//    cout<< noffac(100)<<endl;
    while(val<=1000000){
        val = val+ noffac(val);
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    cin>>TC;
    while(TC--){
        cin>>A>>B;
        auto lower = lower_bound(vec.begin(), vec.end(), A);
        auto upper = upper_bound(vec.begin(), vec.end(), B);
        if(upper!=vec.end() && *upper == B)
            cout<< "Case "<< ++test_case<<": " <<upper-lower+1<<endl;
        else
            cout<< "Case "<< ++test_case<<": " <<upper-lower<<endl;
    }
    return 0;
}
