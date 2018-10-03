#include <bits/stdc++.h>
using namespace std;


int ans[100];

bool cmp( vector<int> v1, vector<int> v2 )
{
    
    if(v1[0]!=v2[0]) return v1[0]<v2[0];
    if(v1[1]!=v2[1]) return v1[1]<v2[1];
    return v1[2]<v2[2];
}

int main(int argc, char const *argv[])
{
    int N, a, b, c, max_value, case_value=0;
    vector<vector<int>> vec;

    vector<int> temp;
    while(cin>>N, N){
        max_value=0;
        vec.clear();
        
        for(int i=0; i<N; i++){
            cin>>a>>b>>c;
            temp.clear(); temp.insert(temp.end(),{min(a,b),max(b,a),c});vec.push_back(temp);
            temp.clear(); temp.insert(temp.end(),{min(c,b),max(b,c),a});vec.push_back(temp);
            temp.clear(); temp.insert(temp.end(),{min(a,c),max(c,a),b});vec.push_back(temp);
        }
        sort(vec.begin(), vec.end(), cmp);
        
//        if(N==5){
//            for(auto a:vec){
//                cout<<a[0]<<", "<<a[1]<<", "<<a[2]<<endl;
//            }
//        }
        memset(ans, -1, sizeof ans);
        for(int i=0; i<vec.size(); i++){
            int max_val =0;
            for(int j=0; j<i; j++){
                if(vec[j][0]<vec[i][0] && vec[j][1]<vec[i][1]){
                    max_val=max(max_val, ans[j]);
                }
            }
            ans[i]= max_val+vec[i][2];
            max_value=max(max_value,  ans[i]);
        }
        cout<<"Case "<<++case_value<<": maximum height = "<<max_value<<endl;
        
    }
    return 0;
}
