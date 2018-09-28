#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
    int sum, ans, input,n;
    while(scanf("%d", &n) && n){
        sum=ans=0;
        for (int i = 0; i < n; ++i){
            cin>>input;
            sum +=input;
            ans = max(sum, ans);
            if(sum<0) sum=0;
        }

        if(ans>0) cout<<"The maximum winning streak is "<<ans<<"."<<endl;
        else cout<< "Losing streak." <<endl;
        
    }
    return 0;
}
