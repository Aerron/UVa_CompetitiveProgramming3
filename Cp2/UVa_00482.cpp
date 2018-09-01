#include <bits/stdc++.h>
using namespace std;

#define pis pair <int, string>

int main(int argc, char const *argv[])
{
    int K, input_int;
    string input_string;
    vector <pis> vec;
    vector <int> indices;
    string line;
    cin >> K ;
    cin.ignore();
    while(K--){
    	if (!std::cin.good()) return 0;
        vec.clear();
        indices.clear();
        
        getline(cin, line);
        getline(cin, line);
        stringstream ss(line);
        

        
        while(ss>>input_int){
            indices.push_back(input_int);
        }
        
        getline(cin, line);
        stringstream sf(line);
        for(auto i: indices){
            sf>>input_string;
            vec.push_back(make_pair(i,input_string));
        }
        
        sort(vec.begin(), vec.end());
        
        for(auto i: vec){
            cout<< i.second << endl;
        }
        cout<<"\n";
    }
    return 0;
}



