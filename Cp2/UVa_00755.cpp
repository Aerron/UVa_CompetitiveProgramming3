#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector <string> vec;
    map <string, int> count_val;
    int K, N;
    bool flag;
    string input;
    scanf("%d", &K);
    char alp[27] =  "22233344455566670778889990";
    while(K--){
        scanf("%d", &N);
        vec.clear();
        count_val.clear();
        while( N--){
            cin>>input;
            input.erase( (remove(input.begin(), input.end(), '-')), input.end());
            for(auto a= input.begin() ; a!=input.end(); a++){
                if(isalpha(*a)){
//                    cout<<a<<endl;
                    *a = alp[*a-'A'];
                    
                }
            }
            input.insert(input.begin()+3,'-');
            vec.push_back(input);
            count_val[input]++;
        }
        flag = true;
        sort(vec.begin(), vec.end());
        for(auto a: count_val){
//            cout<< a.first;
            if(a.second!=1){
                flag = false;
                cout << a.first << ' ' << a.second << endl;
            }
        }
        if(flag){
            cout << "No duplicates.\n";
        }
        
        if(K) cout<< "\n";
    }
    
    return 0;
}
