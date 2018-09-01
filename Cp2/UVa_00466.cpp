#include <bits/stdc++.h>
using namespace std;


void rotate(vector <vector <char> > &vec ){
    vector <vector <char> > temp = vec;
    int size = vec.size();
    for(int i = 0; i<size; i++){
        for(int j=0; j<size; j++){
            vec[j][size-i-1] = temp[i][j];
        }
    }
}

void reverse(vector <vector <char> > &vec ){
    vector <vector <char> > temp = vec;
    int size = vec.size();
    for(int i=0; i<size; i++){
        vec[i] = temp[size-1-i];
    }
}

int main(int argc, char const *argv[])
{
    vector <vector <char> > vec;
    vector <vector <char> > new_vec;
    
    string line;
    int K, size, t_case=0;
    bool flag;
    
    while(scanf("%d", &K)!=EOF){
        t_case++;
        vec.assign(K, vector < char >(K, 0));
        new_vec.assign(K, vector < char >(K, '.'));
        size = K;
        
        for(int r=0; r<K; r++){
            for(int i=0; i<K; i++){
                cin>>vec[r][i];
            }
            for(int i=0; i<K; i++){
                cin>>new_vec[r][i];
            }
        }
        flag = true;
        if((vec==new_vec)&&flag){
            flag = false;
            cout<< "Pattern " << t_case << " was preserved."<<endl;
        }
        for(int i=1; i<4; i++){
            rotate(vec);
            if((vec==new_vec)&&flag){
                flag = false;
                cout<< "Pattern " << t_case << " was rotated " << i*90 << " degrees."<<endl;
                break;
            }
        }
        rotate(vec);
        reverse(vec);
        if((vec==new_vec)&&flag){
            flag = false;
            cout<< "Pattern " << t_case << " was reflected vertically."<<endl;
            
        }
        
        for(int i=1; i<4; i++){
            rotate(vec);
            if((vec==new_vec)&&flag){
                flag = false;
                cout<< "Pattern " << t_case << " was reflected vertically and rotated " << i*90 << " degrees."<<endl;
            }
        }
        if(flag){
            flag = false;
            cout<< "Pattern " << t_case << " was improperly transformed."<<endl;
        }
        
    }
    
    return 0;
}





