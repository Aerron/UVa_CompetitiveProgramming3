#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int K, ite_rows;
	map <char, double> value;
	char input_char;
	string input_string;
	double sum,total, input_value;

	scanf("%d", &K);

	while(K--){
		scanf("%d",&ite_rows );
		sum = 0;
		value.clear();
		while(ite_rows--){
			cin>>input_char>> input_value;
			value[input_char] = input_value;
		}
		scanf("%d", &ite_rows);
		cin.ignore();
		while(ite_rows--){
			getline(cin, input_string);
			for(auto a:input_string){
				auto b = value.find(a);
				if(b!=value.end()){
					sum += b->second;
				}
			}
		}
		total = sum/100;
		cout<< total<< fixed << setprecision(2)<<"$"<<endl;
	}


	return 0;
}