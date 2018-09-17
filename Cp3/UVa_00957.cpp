#include <bits/stdc++.h>
using namespace std;
int Y;

void check_large(vector <int> vec){

    int e_year = vec.front(), last_val = vec.back(), s_year=vec.back(), max_val =  INT_MIN ;
    for(auto a= vec.begin(); a!=vec.end(); a++ ){
        if(*a+Y-1>=last_val){
            if(max_val< vec.end()-a ){
                max_val = int(vec.end()-a);
                cout<< max_val<<" " << *a<< " "<< *(vec.end()-1)<<endl;
            }
            else{
                cout << max_val<< " "<<  s_year<< " "<< e_year<< endl;
            }
            return ;
        }
        else{
            auto found = upper_bound(vec.begin(), vec.end(), *a+Y-1 );
            if(max_val< found-a){
                max_val = int(found-a);
                s_year = *a;
                e_year = *(found-1);
            }
        }
    }
    // cout << max_val<< " "<<  s_year<< " "<< e_year<< endl;
    return;
    
}


int main(int argc, char const *argv[])
{
    int pope, input;
    vector <int> vec;
    
    cin>>Y;
    
    do{
        vec.clear();
        cin>>pope;
        while(pope--){
            cin>>input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        check_large(vec);
        
    }while(scanf("%d", &Y)!=EOF);
    return 0;
}
