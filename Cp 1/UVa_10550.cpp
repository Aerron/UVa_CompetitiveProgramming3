#include <stdio.h>


int main(int argc, char const *argv[])
{
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d), (a||b||c||d)){
		printf("%d\n",1080+ ( (40+a-b)%40 + (40+c-b)%40 + (40+c -d )%40)*9 );
	}
	return 0;
}