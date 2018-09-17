#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int A,B;
    
    while(scanf("%d %d", &A, &B), (A!=1) || (B!=1) ) {
        int a=0, b=1, c=1, d=0;
//        cout<< A<< " "<< B;
        while(true){
            if( A*(d+b) == B*(a+c) ) break;
            else if(A*(b+d) < B*(a+c) ){
                cout<< "L";
                c += a;
                d += b;
            }
            else{
                cout<<"R";
                a +=c;
                b +=d;
            }
        }
        cout<<endl;
    }
    return 0;
}
