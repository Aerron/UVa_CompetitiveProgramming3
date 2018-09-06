#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int TC, n, input, df, mx, mn;
    vector <int> vec;
    
    cin>> TC;
    while(TC--){
        cin>>n;
        vec.clear();
        while(n--){
            cin>> input;
            vec.push_back(input);
        }
        df = INT_MIN;
        mx = mn = vec[0];
        for(auto a= vec.begin()+1; a!=vec.end(); a++){
            df = max(df, mx-*a );
            mx= max(mx, *a);
            mn = min(mn, *a);
        }
        cout<< df<< endl;
    }
    return 0;
}
