#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector <vector<int>> vec(4,vector <int>() ) ;
    
    int square, input;
    int lim[4] = {10,100,1000,10000};
    
    for(int i=0; i<10000; i++){
        square = i*i;
        for(int j=0; j<4; j++){
            if( (i<lim[j]) && (i == (square/lim[j]+square%lim[j]))){
                vec[j].push_back(square);
            }
        }
    }
    
    while(scanf("%d", &input)!=EOF){
        for(auto a: vec[input/2-1]){
        	cout.width(input);
        	cout.fill( '0' );
            cout<<a<<right<<endl;
        }
    }
    
    return 0;
}
