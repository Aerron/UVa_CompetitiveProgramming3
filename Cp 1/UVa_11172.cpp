#include <stdio.h>

int main(int argc, char const *argv[])
{
	int TC, a, b;
	scanf("%d", &TC);
	while(scanf("%d %d",&a,&b),TC--){
		(a>b)?printf(">\n"): (a<b)?printf("<\n"):printf("=\n");
	}
	return 0;
}		