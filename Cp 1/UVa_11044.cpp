#include <stdio.h>


int main(int argc, char const *argv[])
{
	int TC, a, b;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &a, &b);
		printf("%d\n", ((a+1)/3)* ((b+1)/3) );
	}
	return 0;
}