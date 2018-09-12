#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int N;
    vector <int> vec_start;
    map <int,int> map_end;
    
    string input;
    int input_num;
   
    
    int overtakes, temp_index;
    
    while(scanf("%d", &N)!=EOF){
        

        vec_start.clear();
        map_end.clear();
        overtakes = 0;

        for(int i=0; i<N; i++){
            cin>>input_num;
            vec_start.push_back(input_num);
        }
        for(int i=0; i< N; i++){
            cin>>input_num;
            map_end[input_num]=i;
        }
        
        
        for(int i=0; i<N; i++){
            temp_index = map_end[ vec_start[i] ];
            for(int j= i-1; j>=0; j--){
                if( map_end[vec_start[j] ]> temp_index )
                    overtakes++;
            }
        }
        cout<< overtakes<<endl;
    }
    
    return 0;
    
}


