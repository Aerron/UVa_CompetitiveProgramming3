#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    double v0, v, len, n, len_;
    bool flag, flag_;
    while((scanf("%lf %lf", &v, &v0)), (v0>0.0)||(v>0.0) ){
        len = (0.3 )*pow((v-v0),0.5);
        flag_ = flag = true;
        n=1;
        if(v<v0) flag_ = false;
        while(flag){
            n++;
            len_ =(n)*(0.3)*pow(( (v/n) -v0),0.5);
            
            if( (v/n <= v0) ||(len> len_) )flag = false;
            if( !flag && (fabs(len - len_) <= 1e-12) ) flag_ = false;
            len =len_;
            // cout<< len<<endl;
        }
        
        if(flag_) cout<< --n<< endl;
        else cout<< 0<<endl;
    }
    return 0;
}
