#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int K, input, len;
    vector <int> vec;
    vector <int> med;
    while(scanf("%d", &K)!=EOF){
        vec.clear();
        med.clear();
        while(K--){
            cin>> input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        len = int(vec.size());
        
        if(len&1){
            med.push_back(vec[ (len)/2 ]);
        }
        else
        {
            if(vec[len/2]==vec[(len-1)/2])
                med.push_back(vec[len/2]);
            else{
                med.push_back(vec[(len-1)/2]);
                med.push_back(vec[len/2]);
            }
        }
        if(med.size()==1)
            cout<< med[0]<<" "<< (upper_bound(vec.begin(), vec.end(), med[0])-lower_bound(vec.begin(), vec.end(), med[0]) )<<" " <<1<<endl;
        else
            cout<< med[0]<< " " << (upper_bound(vec.begin(), vec.end(), med[1])-lower_bound(vec.begin(), vec.end(), med[0]) )<< " "<< med[1]-med[0]+1 << endl;
        
    }
    return 0;
}
