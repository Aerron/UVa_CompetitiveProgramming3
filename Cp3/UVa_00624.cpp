#include <bits/stdc++.h>
using namespace std;


int N, nt, sum;
vector <int> final;

void Rec(vector<int> vec, vector<int> vec_max, int number, int sum_sub){
//    cout<<"Case: "<< sum_sub<<" Number: "<< number<< " Sum_sub: "<< sum_sub<<endl;
//    for(auto a: vec)
//        cout<<a;
//    cout<<endl;
    if(number==N){
        if(sum<sum_sub){
            final = vec_max;
            sum = sum_sub;
        }
        if(sum==sum_sub && vec_max.size()>final.size() ){
        	final = vec_max;
        	sum = sum_sub;
        }
        return;
    }
    
    Rec(vec, vec_max, number+1, sum_sub);
    
    if(sum_sub+vec[number] <=nt ){
//        cout<< number<<" Suml2 "<< sum_sub<<" "<<vec[number]<<endl;
        vec_max.push_back(vec[number]);
        sum_sub += vec[number];
//        cout<< number<<" Suml3 "<< sum_sub<<" "<<vec[number]<<endl;
        Rec(vec, vec_max, number+1, sum_sub);
    }
}
         
         
         
int main(int argc, char const *argv[])
{
    int input;
    
    vector<int> vec;
    vector <int> vec_max;
    
    while(scanf("%d %d", &nt,&N)!=EOF){
//        cout<<"N: "<<N<<"nt: "<<nt<<endl;
        vec.clear();
        vec_max.clear();
        sum =0;
        for(int i= 0; i<N; i++){
            cin>>input;
            vec.push_back(input);
        }
        Rec(vec, vec_max, 0, 0);
        for(auto a: final){
            cout<<a<<" ";
        }
        cout<<"sum:"<<sum<<endl;
    }
    
    return 0;
}
