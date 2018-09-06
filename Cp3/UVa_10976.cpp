#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;

int main(int argc, char const *argv[])
{
    int x, y, k;
    vector <pp> vec;
    
    while(scanf("%d", &k)!=EOF){
        vec.clear();
        
        for(y=k+1; y<=2*k; y++){
            x = (y*k)/(y-k);
            if( (x*(y-k)==y*k)&&(x>=y) ){
                vec.push_back(make_pair(x,y));
            }
        }
        sort(vec.begin(), vec.end(), greater<pp>());
        // reverse(vec.begin(), vec.end());
        cout<< vec.size()<<endl;
        for (auto a: vec)
        {
            cout<< "1/"<<k<< " = "<< "1/"<<  a.first<< " + "<< "1/"<< a.second<<endl;
            /* code */
        }
    }
    return 0;
}

