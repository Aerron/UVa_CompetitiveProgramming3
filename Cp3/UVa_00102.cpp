#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int  sum, min_value, temp_sum;
    int arr[3][3];
    string input;
    vector <int> vec; 
    vector <int> v_c;
    char col[4] = "GCB" ;
    while(scanf("%d %d %d %d %d %d %d %d %d",&arr[0][2],&arr[0][0],&arr[0][1],&arr[1][2],&arr[1][0],&arr[1][1],&arr[2][2],&arr[2][0],&arr[2][1])!=EOF){
        
        // sum = accumulate(arr, arr+9, 0, plus<int>());
        // auto sum = ranges::accumulate(ranges::view::join(arr), 0);
        vec.clear();
        sum = 0;
        for(int i=0; i<3; i++){
            for (int j = 0; j < 3; ++j)
            {
                sum += arr[i][j];
            }
        }
        min_value = INT_MAX;
        vec.insert(vec.end(), {0,1,2} );
        
        for(int i=0,j=0; i<6; i++, j=0 ){
            temp_sum = sum;
            for(auto a:vec){
                temp_sum -= arr[j++][a];
            }
            
            if(temp_sum<=min_value){
                min_value=temp_sum;
                v_c = vec;
            }
            
            next_permutation(vec.begin(), vec.end());
        }
        
        cout<< col[v_c[0]]<< col[v_c[1]] << col[v_c[2]] << " "<< min_value <<endl;
        
    }
    return 0;
}
