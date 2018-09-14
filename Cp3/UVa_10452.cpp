#include <bits/stdc++.h>
using namespace std;


string goal = "IEHOVA";
vector <string > vec;
int M, N;


void rec(int line, int index, int path_index, vector<int>order ){
//    cout<<"line: "<< line<< " index: "<< index<<"path: "<< path_index<<endl;
    if(path_index==6){
        bool flag = false;
//        cout<<"line: "<< line<< " index: "<< index<<endl;
        if( (line==0 && ( (index>0 && vec[0][index-1]=='#')|| (index<=N-2 && vec[0][index+1]=='#') )) || (line==1 && vec[0][index]=='#') ){
//            cout<<"line: "<< line<< " index: "<< index<<endl;
            if(line ==1)
                order.push_back(2);
            else if(line ==0 && (index<=N-2 && vec[0][index+1]=='#') )
                order.push_back(1);
            else
                order.push_back(-1);
            flag = true;
        }
        if(flag){
            for(auto a= order.begin(); a!=order.end(); a++){
            	if(a!=order.begin())
                	cout<<" ";
                if(*a==-1)
                    cout<< "left";
                else if(*a==1)
                    cout<< "right";
                else
                    cout<< "forth";

            }
            cout<<endl;
            return;
        }
        else
            return;
    }
    char curr_ch = goal[path_index];
//    cout<<"line: "<< line<< " index: "<< index<<"path: "<< path_index<<"Goal: "<< curr_ch<<endl;
    if(index>0 && vec[line][index-1]==curr_ch){
        order.push_back(-1);
        rec(line, index-1, path_index+1, order);
        order.pop_back();
    }
    if(index<=N-2 && vec[line][index+1]==curr_ch){
        order.push_back(1);
        rec(line, index+1, path_index+1, order);
        order.pop_back();
    }
    if(line>0 && vec[line-1][index]==curr_ch){
        order.push_back(2);
        rec(line-1, index, path_index+1, order);
        order.pop_back();
    }
    return;
    
}

int main(int argc, char const *argv[])
{
    int TC;
    string input;
    
    vector <int> order;
    scanf("%d", &TC);
    while(TC--){
        cin>>M>>N;
        vec.clear();
        for(int i=0; i<M; i++){
            cin>>input;
            vec.push_back(input);
//            cout<<input<<endl;
        }
        order.clear();
        
        int index = int(vec[M-1].find('@'));
//        cout<< index<<endl;
        rec(M-1,index, 0, order);
        
    }
    return 0;
}
