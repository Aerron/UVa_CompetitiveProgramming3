#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int S, B, L, R, i;
    vector <int> vec;
    while(scanf("%d %d", &S, &B), S||B ){
        // vec.assign(S, true);
        vec.assign(S, 0);
        i = 1;
        for(auto a= vec.begin();a!=vec.end(); a++ ){
            *a = i;
            i++;
        }
        while(B--){
            scanf("%d %d ", &L, &R);
            auto it = find(vec.begin(), vec.end(), L);
            auto it2 = find(vec.begin(), vec.end(), R);
            it2++;
            if(it==vec.begin()){
                if(it2 == vec.end()){
                    cout<< "* *"<<endl;
                }
                else
                    cout<< "* "<< *(it2) <<endl;
            }
            else if(it2 == vec.end()){
                cout<< *prev(it)<< " *"<< endl;
            }
            else{
                cout<< *prev(it)<< " "<< *(it2)<<endl;
            }
            vec.erase(it, it2);
        }
        cout<< '-'<<endl;
    }
    return 0;
}
