#include <bits/stdc++.h>
using namespace std;


int noffac(int val){
    int limit, sum = 1;

    for (int i = 2, limit = (int)sqrt(val); i <= limit; i++)
        if (val%i==0) sum++;
    sum *= 2;

    if (limit-sqrt(val)==0) sum--;

    return sum;
}


int main(int argc, char const *argv[])
{
    vector <int> vec;
    int TC, A,B, test_case=0;
    vec.insert(vec.end(),{1, 2, 4, 7, 9, 12, 18});
    int val =18;
    
    while(val<=1000000){
        val = val+ noffac(val);
        vec.push_back(val);
    }
    cin>>TC;
    while(TC--){
        cin>>A>>B;
        auto lower = lower_bound(vec.begin(), vec.end(), A);
        auto upper = upper_bound(vec.begin(), vec.end(), B);
        cout<< "Case "<< ++test_case<<": " <<upper-lower<<endl;
    }
    return 0;
}
