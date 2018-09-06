#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    vector <int> vec;
    int input, degree, k, d, TC, n, sum, i;
    long long output;
    string line;
    stringstream ss;
    
    cin>>TC;
    while(TC--){
        vec.clear();
        
        // getline(cin, line);
        // ss.clear();
        // ss.str(line);
        // ss>>degree;
        // while(ss>>input)vec.push_back(input);
        cin>>degree;
        degree++;
        while(degree--){
            cin>>input;
            vec.push_back(input);
        }
        cin>>d>>k;
        
        sum=d;
        n=1;
        while(k>sum){
            n+=1;
            sum +=n*d;
        }
        
        i = output = 0;
        for(auto a: vec){
            output += a*pow(n,i++);
        }
        cout<<output<<endl;
    }
    return 0;
}
