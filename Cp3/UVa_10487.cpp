#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int num, query, input, size, min_val, case_val=0;
    int sum;
    vector <int> vec;
    while(scanf("%d",&num), num){
        case_val++;
        sum = 0;
        while(num--){
            cin>>input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        size = int(vec.size());
        cin>>query;
        cout<< "Case "<<case_val<<":"<<endl;
        while(query--){
            cin>>input;
            min_val = INT_MAX;
            for(int i=0; i<size-1;i++){
                for (int j=i+1; j<size; j++){
                    if( abs(input-(vec[i]+vec[j])) < min_val ){
                        min_val = abs(input-(vec[i]+vec[j]));
                        sum = vec[i]+vec[j];
                    }
                }
            }
            cout<< "Closest sum to " <<input<<" is "<<sum<<"."<<endl;
            
        }
        
    }
    return 0;
}
