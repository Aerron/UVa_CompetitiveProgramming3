//Dp sol
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int TC, routes, input, sum, prev_ind, i_ind, j_ind, max_val, case_val=0;
    vector <int> vec;
    cin>>TC;
    while(TC--){
        cin>>routes;
        
        max_val = INT_MIN;
        vec.clear();
        i_ind=j_ind=0;
        case_val++;

        //DP
        //vec.push_back(0);
        
        for(int i=1; i<routes; i++){
            cin>>input;
            vec.push_back(input);
        }
        
        
        sum=0;
        max_val = INT_MIN;
        prev_ind=0;
        for (int i = 0; i < routes-1; i++) {
            sum += vec[i];
//            cout<< "sum: "<< sum<< " ,max_val: "<< max_val<< " ,i_prev: "<< prev_ind<< " ,i_ind: "<< i_ind<< " ,j_ind: "<< j_ind<<endl;
            if(max_val< sum){
                i_ind = prev_ind; j_ind = i; max_val = sum;
            }
            else if(max_val==sum && (i-prev_ind)>(j_ind-i_ind)){
                i_ind = prev_ind; j_ind = i;
            }
            if (sum < 0){
                sum = 0;
                prev_ind = i+1;
            }
//            cout<< "sum: "<< sum<< " ,max_val: "<< max_val<< " ,i_prev: "<< prev_ind<< " ,i_ind: "<< i_ind<< " ,j_ind: "<< j_ind<<endl;
        }
        if(max_val>0) cout<< "The nicest part of route "<<case_val<<" is between stops "<<i_ind+1<<" and "<<j_ind+2<<endl;
        else cout<< "Route "<<case_val<<" has no nice parts"<<endl;
        
//        max_val = INT_MIN;
//        i_ind=j_ind=0;
////        Dp solution
//         for(auto it = vec.begin()+1; it!=vec.end(); it++){
//             *it += *(it-1);
//         }
//
//
//
//         for(int i=0; i<routes; i++){
//             for(int j=i+1; j<routes; j++){
//                 if(max_val< (vec[j]-vec[i]) ){
//                     i_ind=i; j_ind=j; max_val = vec[j]-vec[i];
//                 }
//                 else if(max_val == (vec[j]-vec[i]) && (j-i)>(j_ind-i_ind)){
//                     i_ind=i; j_ind=j;
//                 }
//             }
//         }
//
//         if(max_val>0) cout<< "The nicest part of route "<<case_val<<" is between stops "<<i_ind+1<<" and "<<j_ind+1<<endl;
//         else cout<< "Route "<<case_val<<" has no nice parts"<<endl;
        
    }
    return 0;
}
