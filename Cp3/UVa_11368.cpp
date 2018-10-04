//Have to debug

#include <bits/stdc++.h>
using namespace std;

typedef pair<long, long> pp;

vector <pp> vec;
vector <long> L;

long N;

bool cmp(pp v1, pp v2){
    if (v1.second==v2.second) return v1.first<v1.first;
    return v1.second>v2.second;
}


int main(int argc, char const *argv[])
{
    long TC,inputW, inputH;
    cin>>TC;
    while(TC--){
        scanf("%ld", &N);
        vec.clear();
        
        for(long i=0; i<N; i++){
            cin>>inputW>>inputH;vec.push_back(make_pair(inputW, inputH));
        }
        
        sort(vec.begin(), vec.end(), cmp);
        // for(auto a: vec){cout<<"{"<<a.first<<", "<<a.second<<"}		";}
        // cout<<endl;
        L.clear();
        long lis=0;
        for(long i=0; i<N; i++){
            long pos = lower_bound(L.begin(), L.end(), vec[i].first+1)-L.begin();
            if(pos==L.size()){lis++; L.push_back(vec[i].first);}
            else L[pos]=vec[i].first;
        }
        cout<<lis<<endl;
        
    }
    return 0;
}






// #include <stdio.h>
// #include <algorithm>
// #include <climits>
// #include <vector>
// #include <iostream>
// using namespace std;
// struct data
// {
//     int w,h;
// };
// data ar[20005];
// int L[20005];
// bool cmp(data a,data b)
// {
//     if(a.h == b.h)return a.w < b.w;
//     return a.h > b.h;
// }

// int NLOGK(int n)
// {
//     vector < int > vec;
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         int pos=lower_bound(vec.begin(),vec.end(),ar[i].w+1)-vec.begin();
//         // printf("position for ar[%d] = %d\n",i,pos);

//         if(pos==vec.size()){ans++; vec.push_back(ar[i].w);}
//         else vec[pos]=ar[i].w;

//     }
//     return ans;
// }
// int main()
// {
//     int test,n;
//     //freopen("in.txt","r",stdin);
//     scanf("%d",&test);
//     while(test--)
//     {
//         scanf("%d",&n);
//         for(int i=0;i<n;i++)scanf("%d %d",&ar[i].w,&ar[i].h);
//         sort(ar,ar+n,cmp);
//         //for(int i=0;i<n;i++)printf("%d %d\n",ar[i].w,ar[i].h);
//         int LIS=NLOGK(n);
//         printf("%d\n",LIS);
//     }
//     return 0;
// }
