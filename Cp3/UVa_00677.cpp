#include <bits/stdc++.h>
using namespace std;


int N, walk_n;
vector <vector <int>> adj_mat;
int count_val;

void Rec( vector <int> taken, vector<int> order, int path_len)
{
    if(path_len==walk_n+1){
        cout<<"(";
        auto a= order.begin();
        for(; a+1!=order.end(); a++){
            cout<<*a+1<<",";
        }
        cout<< *a+1<<")"<<endl;
        count_val++;
        return;
    }
    // if(path_len==0){
    //     for(int i=0; i<N; i++){
    //         taken[i]=1;
    //         order.push_back(i);
    //         Rec(taken, order, path_len+1);
    //         order.pop_back();
    //         taken[i]=0;
    //     }
    //     return;
    // }
    int last = order.back();
    for(int i=0; i<N; i++){
        if( (taken[i]==0) && (adj_mat[last][i]==1) ){
            taken[i]=1;
            order.push_back(i);
            Rec(taken, order, path_len+1);
            order.pop_back();
            taken[i]=0;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int input, junk;
    vector <int> taken;
    vector <int> order;
    while(scanf("%d %d", &N,&walk_n)!=EOF){
    	order.clear();
        adj_mat.assign(N, vector<int> (N,0) );
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>input;
                if(input)
                    adj_mat[i][j]=1;
            }
        }
        count_val = 0;
        taken.assign(N,0);
        
        taken[0]=1;
        order.push_back(0);
        
        Rec(taken,order,1);
        if(count_val==0)
            cout<<"no walk of length "<< walk_n<<endl;
        if(scanf("%d",&junk)!=EOF){
        	cout<<endl;
        }
    }
    return 0;
}
