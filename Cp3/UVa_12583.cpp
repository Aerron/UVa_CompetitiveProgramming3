#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int TC, n, k, remember, q=0;
    cin>>TC;
    string s;
    
    while(TC--){
        q++;
        remember = 0;
        
        int arr[27]={-1};
        cin>>n>>k>>s;
        char c;
        for(int i=0; i<n; i++){
            c = s[i];
            if(arr[c-'A']>=i && i!=0){
                remember++;
            }
            arr[c-'A']= i+k;
        }
        cout << "Case "<< q << ": " <<  remember << endl;
    }
    
    return 0;
}

