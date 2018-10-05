
//Memory limit error due to excess size of array
//Have to implement bottom up
#include <bits/stdc++.h>

using namespace std;

long ferry_len, N;
vector <long> vec;
// vector <long> vec_print;
long memo[105][10100][10100], picked[105][10100][10100];

long dp(long index, long left, long right){
    if(index>=N) return 0;
    if(memo[index][left][right]!=-1) return memo[index][left][right];

    long left_val=0, right_val=0;
    if(left>=vec[index]) left_val = dp(index+1, left-vec[index], right)+1;
    if(right>=vec[index]) right_val = dp(index+1, left, right-vec[index])+1;
    
    if(left_val==right_val){
        if(left_val==0) picked[index][left][right]=0;
        else picked[index][left][right]=2;
    } 
    else if( left_val<right_val) picked[index][left][right]=2;
    else if( right_val<left_val) picked[index][left][right]=1;

    return memo[index][left][right] = max(left_val, right_val);

}


void print_f(long index, long left, long right){
    // || picked[index][left][right]==0
    if(index>=N ) return;
    if(picked[index][left][right]==1){
        cout<< "port"<<endl;
        print_f(index+1, left-vec[index], right);
    }
    else if(picked[index][left][right]==2){
        cout<< "starboard"<<endl;
        print_f(index+1, left, right-vec[index]);
    }
    return;
}


int main(int argc, char const *argv[])
{
    long TC ,input;
    cin>>TC;
    while(TC--){
        fill(&memo[0][0][0], &memo[105][0][0], -1);
        fill(&picked[0][0][0], &picked[105][0][0], -1);
        cin>>ferry_len;
        ferry_len*=100L;
        vec.clear();

        while(cin>>input, input){
            vec.push_back(input);
        }
        N = vec.size();
        // for(auto a: vec)cout<<a<<", ";
            // cout<<N<<" "<<endl;
        dp(0, ferry_len, ferry_len);
        // cout<<"ack1"<<endl;
        cout<<dp(0, ferry_len, ferry_len)<<endl;
        // cout<<"ack2"<<endl;
        print_f(0, ferry_len, ferry_len);
        cout<<endl;
    }
    return 0;
}


