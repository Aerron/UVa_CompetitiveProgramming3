#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int i=0;
	while(cin>>str, str!="#"){
		cout<< "Case "<< ++i <<": ";
		if(str== "HELLO") printf("ENGLISH\n" );
        else if(str== "HOLA") printf("SPANISH\n" );
        else if(str== "HALLO") printf("GERMAN\n" );
        else if(str== "BONJOUR") printf("FRENCH\n" );
        else if(str== "CIAO") printf("ITALIAN\n" );
        else if(str== "ZDRAVSTVUJTE") printf("RUSSIAN\n" );
        else printf("UNKNOWN\n" );
	}
	return 0;
}