#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

typedef pair<int, int> ii; 
typedef pair<double,int> di;
typedef pair<int, double> id;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<id> vid;


int V;
vii stone(200);
vector <vid> AdjList;
vi taken, parent;                                 
priority_queue<di> pq;           

void adjlists(){
	AdjList.clear();
    AdjList.assign(V, vid());
    double w;
    for(int i=0; i< V; i++){
        for(int j=i+1; j<V; j++){
            w = sqrt(pow((stone[i].first - stone[j].first), 2) + pow((stone[i].second - stone[j].second), 2));
            AdjList[i].push_back(id(j, w));
            AdjList[j].push_back(id(i, w));
        }
    }
}

void process(int vtx) {    
    taken[vtx] = 1;
    
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        id v = AdjList[vtx][j];
        if (!taken[v.first]) pq.push(di(-v.second, -v.first));
    }

}


void prims(){
	V = stone.size();
    adjlists();                          
    taken.assign(V, 0);               
    parent.assign(V, 0);
    process(0);
    int u,par =0;
    double w;

    while(!pq.empty()){
        di front = pq.top();
        pq.pop();
        u = -front.second, w = -front.first;
        if(!taken[u]){
            parent[u]= par;
            par = u;
            process(u);
        }
    }
}

double dist(){
    int c1 = 1,c2 = parent[1];
    double  distance = -1;
    while(c1 != c2){
        distance = max(distance,  sqrt(pow((stone[c1].first - stone[c2].first), 2) + pow((stone[c1].second - stone[c2].second), 2)) );
        c1 = c2;
        c2 = parent[c2];
    }
    return distance;
}

int main()
{
    int stones,x,y,senario=0;
    
    while(scanf("%d",&stones),stones){
        stone.clear();
        while(stones--){
            scanf("%d %d",&x, &y);
            stone.push_back(make_pair(x,y));
        }
        prims();
        printf("Scenario #%d\nFrog Distance = %0.3lf\n\n",++senario,dist() );
    }
}

