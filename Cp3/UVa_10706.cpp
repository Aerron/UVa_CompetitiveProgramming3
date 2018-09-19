#include <bits/stdc++.h>
using namespace std;

vector <long> vec;
vector <long> vec_nc;


long check_dig(long number, long digit){
    if (digit==0)
        return (number-1)%10;
    long num_digits = long(log10(number))+1;
    long val = (number/(pow(10,(num_digits-digit))) ) ;
    return val%10;
}

long cal_digit(long input){
    auto index_val = upper_bound(vec.begin(), vec.end(), input);
//    cout<< *index_val<<" "<< *(index_val-1)<<endl;
    
    long digit_remaining = input- *(index_val-1);
//    cout<< digit_remaining<<endl;
    if(digit_remaining==0)
        return (index_val-vec.begin())%10;
    if(digit_remaining<10)
        return digit_remaining;
    
    digit_remaining-=9;
    long digits_num = 0;
    for(int i=2; i<10; i++){
//        cout<<i<<" " <<digit_remaining<<endl;
        digits_num = i*(9* pow(10,i-1) );
        
        if(digit_remaining < digits_num ){
            
            digits_num  = digit_remaining/i;
            digit_remaining = digit_remaining%i;

//            cout<<digits_num << " "<<digit_remaining<<endl;
            return check_dig(pow(10,i-1)+digits_num, digit_remaining );
        }
        else{
            digit_remaining -= digits_num;
        }
    }
    return 0;
    
}

int main(int argc, char const *argv[])
{
    long TC, input, dig=1, prev=1;
    vec.push_back(1);
    for(long i=2; i<= 31267; i++){
        dig=( long(log10(i)) +1 );
        prev+=dig;
//        if(i<220)
//            cout<< i<<" "<<dig<< " "<< prev<< " "<< vec.back()+prev<<endl;
        vec.push_back(vec.back()+prev);
    }
    
    cin>>TC;
    while(TC--){
        cin>>input;
        cout<<cal_digit(input)<<endl;
    }
    return 0;
}
