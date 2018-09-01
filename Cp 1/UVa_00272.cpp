#include <stdio.h>

int main(int argc, char const *argv[])
{
	char a;
	bool cond = false;
	while(scanf("%c", &a)!= EOF){
		if( a =='"'){
			if(cond) printf("''");
			else printf("``");
			cond = !cond;
		}
		else 
			printf("%c",a );
	}
	return 0;
}