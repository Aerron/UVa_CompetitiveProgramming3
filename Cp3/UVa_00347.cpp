#include <bits/stdc++.h>
using namespace std;



bool check(long number){
    
    bool flag = true;
    int curr_index = 0;
    string num = to_string(number);
    long count = num.size();
    vector<bool> arr(count,false);
    vector<bool> number_rep(10,false);
    
    while(flag){
        if( (arr[curr_index] ||  ( (number_rep[(num[curr_index]-'0')]) ==true ) ) || ( (num[curr_index]-'0')==0) ){
            flag = false;
            break;
        }
        number_rep[(num[curr_index]-'0')]=true;
        arr[curr_index]=true;
        curr_index = (curr_index+(num[curr_index]-'0') ) % (count);

    }

    if (curr_index==0)
        flag = true;
    else
        return false;
    for(auto a: arr){
        if(!a){
            flag = false;
            break;
        }
    }
    return flag;
}


int main(int argc, char const *argv[])
{
    long number;
    bool flag;
    int i=0;
    while(scanf("%ld", &number), number){
        flag = false;
        i++;
        while(!flag && number < 9876543210 ){
            flag = check(number);
            if(!flag) number++;
        }        
        cout<< "Case "<<i<<": "<<number<<endl;
    }

    return 0;
}



