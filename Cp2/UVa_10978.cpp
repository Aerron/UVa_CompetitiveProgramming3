#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int K, size;
    vector <string> vec;
    string line, input, input_name;
    int count;
    
    while(scanf("%d", &K), K){
        size = K;
        // vec.clear();
        vec.assign(size, "");
        count = -1;
        while(K--){

            cin>>input >> input_name;
            // cout<< input << " "<< input_name <<endl;
            int len = input_name.length();
            
            while(len){
                count = (count+1)%size;
                len--;
                while(vec[count]!=""){
                    count = (count+1)%size;
                }
            }
            // cout<< count<<endl;
            vec[count] = input;
        }
        
        for(int i=0; i<size; i++){
            if(i) cout<< " ";
            cout<< vec[i];
        }
        cout<<"\n";
    }
    return 0;
}
