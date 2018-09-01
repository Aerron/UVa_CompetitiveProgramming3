#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{
	int TC, a, b;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &a, &b);
		printf("%d\n",a+b );
	}	
	return 0;
}