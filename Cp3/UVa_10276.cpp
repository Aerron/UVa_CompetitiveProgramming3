#include <bits/stdc++.h>
using namespace std;

int N, max_val;


bool check(int num){
    int root = pow(num,0.5);
    
    if(num == pow(root,2))
        return true;
    else
        return false;
}

void rec(vector <int> vec, int next_num){
    int count =0;
    int size_vec = int(vec.size());
    int temp;
    // if(size_vec<N){
        
    //     vec.push_back(next_num);
    //     rec(vec, next_num+1 );
    //     count +=1;
    //     vec.pop_back();
        
    //     return;
    // }
    
    if(size_vec!=0){
        for(int i= 0; i < size_vec ; i++){
            if(check(next_num+vec[i])){
                temp = vec[i];
                vec[i] = next_num;
                rec(vec, next_num+1 );
                count +=1;
                return;
            }
        }
        
    }
    
    if(count==0){
	    if(size_vec<N){
	        
	        vec.push_back(next_num);
	        rec(vec, next_num+1 );
	        count +=1;
	        vec.pop_back();
	        
	        return;
	    }
//        for(auto a: vec){
//            cout<< a;
//        }
//        cout<<endl;
        else max_val  = max( *max_element(vec.begin(), vec.end()), max_val);
    }
    
}

int main(int argc, char const *argv[])
{
    int TC;
    vector <int> vec;
    scanf("%d",&TC);
    while(TC--){
        vec.clear();
        cin>>N;
        max_val  =0;
        rec(vec, 0);
        cout<< max_val<<endl;
    }
    return 0;
}
