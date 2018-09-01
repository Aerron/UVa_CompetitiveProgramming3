#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int K, size, input;
    vector <int> vec;
    bool flag;
    while(scanf("%d", &K),K){
        vec.clear();
        size = K;
        flag = true;
        // cout<<K<< endl;
        while(K--){
            cin>> input;
            vec.push_back(input);
        }
        // vec.push_back(1422);
        sort(vec.begin(), vec.end());
        for(auto a=vec.begin(); a!=vec.end()-1 ;a++){
//            cout<< *a<<*(a+1)<<flag<<endl;
            if( (*(a+1)-*a)>200 ){
                flag = false;
            }
        }
//        cout<< vec[size-1]<<size<< flag<<endl;
        if( (1422-vec[size-1])>100 ){
            flag = false;
        }
//        cout<< vec[size-1]<<size<< flag<<endl;
        if(flag) cout <<"POSSIBLE" <<endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
