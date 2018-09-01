#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int TC, a, b, x, y;

	while(cin>>TC, TC){
		cin>> a >> b;
		while(TC--){
			cin>>x>>y;
			if(x==a || y== b) printf("divisa\n");
    		else if(x>a){
    			if(y>b) printf("NE\n");
    			else printf("SE\n");
    		}
    		else{
    			if(y>b) printf("NO\n");
    			else printf("SO\n");
    		}
		}
	}
	return 0;
}