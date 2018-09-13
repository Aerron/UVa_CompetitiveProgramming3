#include <bits/stdc++.h>
using namespace std;

vector <string> vec;


void Rec(string str_format, int pos, vector <string> vec_que){
    if(pos==str_format.size()){
        for(auto a: vec_que){
            cout<<a;
        }
        cout<<endl;
        
    }
    else if(str_format[pos]=='0'){
        for(int i=0; i<10; i++){
            vec_que.push_back(to_string(i));
            Rec(str_format, pos+1, vec_que);
            vec_que.pop_back();
        }
    }
    else{
        for(auto it= vec.begin(); it!=vec.end();it++){
            vec_que.push_back(*it);
            Rec(str_format, pos+1, vec_que);
            vec_que.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    int word_num, test_num;
    string input_string;
    vector <string> vec_que;
    
    while(scanf("%d", &word_num)!=EOF){
        vec.clear();
        while(word_num--){
            cin>> input_string;
            vec.push_back(input_string);
        }
        scanf("%d",&test_num);
        cout<<"--"<<endl;
        while(test_num--){
            vec_que.clear();
            cin>>input_string;
            
            Rec(input_string, 0, vec_que);
        }
        
    }
    return 0;
}



