#include <bits/stdc++.h>
using namespace std;

#define pss pair<string, string>

int main(int argc, char const *argv[])
{
	vector <pss> books;
	map<string, bool> borrowed;
	map<string, bool> returned;
	
	string input;
	char title[85], author[85];

	while(getline(cin, input)){
		if(input=="END") break;

		sscanf(input.c_str(),"\" %[^\"]\" by %[^\n]",title, author);
		books.push_back(make_pair(author,title) );
		borrowed[title] = false;
		returned[title] = false;
	}
	sort(books.begin(), books.end());

	while(getline(cin, input)){
		if(input=="END"){
			break;
		}
		if(input=="SHELVE"){
			string previous;
			for(auto book: books){
				if(borrowed[book.second]){
					if(returned[book.second]){
						if(previous.length())
							cout<< "Put \""<< book.second << "\" after \""<< previous<< "\""<< endl;
						else
							cout << "Put \""<< book.second << "\" first"<< endl;
						borrowed[book.second]=false;
						returned[book.second]=false;
					}
				}
				if(!borrowed[book.second]){
					previous = book.second;
				}

				
			}
			cout<< "END"<< endl;
		}
		else if(input[0] == 'B'){
			sscanf(input.c_str(), "BORROW \"%[^\"]\"",title);
			borrowed[title]=true;
		}
		else if(input[0] == 'R'){
			sscanf(input.c_str(), "RETURN \"%[^\"]\"",title);
			returned[title]=true;
		}
	}



	return 0;
}