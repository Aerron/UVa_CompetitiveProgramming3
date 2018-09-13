#include <bits/stdc++.h>
using namespace std;

int n, m, max_val;



typedef vector <int> vi;
typedef pair<int, int> ii;

vector <int> edges_taken;
vector <vi> Adj_edges;
map <ii, int> edge_number;

vector <int> nodes;

int rec(int node){
    int deg = int(Adj_edges[node].size());
    int max_subvalue=0;
    
    if(deg !=0){
        for(int i=0; i<deg; i++){
            if( edges_taken[edge_number[make_pair(min(Adj_edges[node][i],node),max(Adj_edges[node][i],node))] ]==0 ){
                edges_taken[edge_number[make_pair(min(Adj_edges[node][i],node),max(Adj_edges[node][i],node))]]=1;

                max_subvalue = max(max_subvalue,rec(Adj_edges[node][i])+1) ;

                edges_taken[edge_number[make_pair(min(Adj_edges[node][i],node),max(Adj_edges[node][i],node))]]=0;
            }
        }
        return max_subvalue;
    }
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    int s,e;
    while(cin>>n>>m, n||m){
        Adj_edges.assign(n, vector<int>());
        edge_number.clear();
        for(int i=0; i<m; i++){
            cin>> s>>e;
            Adj_edges[s].push_back(e);
            Adj_edges[e].push_back(s);
            edge_number[make_pair(min(e,s), max(e,s))] = i;
        }
        max_val = INT_MIN;
        for(int i=0; i<n; i++){
            edges_taken.assign(m, 0);
            max_val = max(max_val, rec(i) );
        }
        cout<<max_val<<endl;
    }
    return 0;
}
