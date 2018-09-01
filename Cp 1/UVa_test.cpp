#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{
	// int TC, a, b;
	// scanf("%d", &TC);
	// while(TC--){
	// 	scanf("%d %d", &a, &b);
	// 	printf("%d\n",a*b );
	// }	

	// int a, b;
	// while(scanf("%d %d ", &a, &b), (a||b)){
	// 	printf("%d\n",a+b );
	// }

	// int a, b;
	// while(scanf(" %d %d ", &a, &b)!=EOF){
	// 	printf("%d\n",a+b );
	// }

	// int a, b, c=1;
	// while(scanf(" %d %d ", &a, &b)!=EOF){
	// 	if(c>1) printf("\n");
	// 	printf("Case %d: %d\n",c++, a+b );
	// }

	int ans, b, k;
	while(scanf("%d", &k)!=EOF){
		ans = 0;
		while(k--){
			scanf("%d", &b);
			ans +=b;
		}
		printf("%d\n",ans );
	}

	return 0;
}