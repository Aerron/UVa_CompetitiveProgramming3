#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int K, input, size;
    bool flag;
    vector <int> vec;
    vector <bool> bool_vec;
    while(scanf("%d", &K)!=EOF){
        flag = true;
        vec.clear();
        size = K;
        bool_vec.assign(K, false);
        while(K--){
            scanf("%d", &input);
            if(input <=0){
                flag = false;
            }
            vec.push_back(input);
        }
        if(flag){
            auto pre = vec.begin();
            for(auto curr = vec.begin()+1; curr!=vec.end(); curr++){
                bool_vec[abs(*curr-*pre)] = true;
                pre = curr;
            }
            
            for(int i=1; i<size; i++){
                if(!bool_vec[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout<< "Jolly" << endl;
        else cout<< "Not jolly" << endl;
    }
    return 0;
}
