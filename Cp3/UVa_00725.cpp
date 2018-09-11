#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

int main(int argc, char const *argv[])
{
    int N;
    int abcde, fghij, used, temp, count,limit;
    int t=1;
    while(scanf("%d", &N), N){
        count = 0;
        limit = 98765/N;
        if(t!=1) cout<<endl;
        t++;
        for(fghij= 1234;fghij<=limit; fghij++ ){
            abcde = fghij * N;
            
            if(fghij<10000) used = 1;
            else used = 0;
            
            temp = fghij;
            while(temp){ used |= 1<<(temp%10); temp/=10;}
            temp = abcde;
            while(temp){ used |= 1<<(temp%10); temp/=10;}
            
            if(used == (1<<10)-1){
                count++;
                cout.fill('0');
                cout<< abcde<< " / "<< setw(5)<<fghij<< " = " << N <<endl;
            }
            
        }
        if(count==0)
            cout<< "There are no solutions for "<<N<<"."<<endl;
    }
    
    return 0;
}
