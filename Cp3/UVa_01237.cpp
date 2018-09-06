#include <bits/stdc++.h>
using namespace std;

//Error have to change maps to array of structs to accomodate multiple ranges

typedef pair<int,int> pp;

int main(int argc, char const *argv[])
{
	int database, TC, query, input;
	map <string, pp> map_values;
	cin>>TC;
	string input_str;
	int low, high, counter;

	while(TC--){
		map_values.clear();
		cin>>database;
		while(database--){
			cin>> input_str>> low>> high;
			auto found = map_values.find(input_str);
			if(found == map_values.end())
				map_values[input_str] = make_pair(low, high);
			else{
				if(map_values[input_str].first>low) map_values[input_str].first = low;
				if(map_values[input_str].second<high) map_values[input_str].second = high;
			}

		}
		cin>>query;
		while(query--){
			cin>>input;
			counter = 0;
			for(auto a: map_values){
				if(input>=a.second.first && input<=a.second.second){
					counter++;
					input_str = a.first;
				}
			}
			if(counter==1) cout<< input_str<<endl;
			else cout<< "UNDETERMINED" <<endl;
		}
		cout<<endl;
	}
	return 0;
}
