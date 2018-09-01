#include <bits/stdc++.h>
using namespace std;


struct PersonInfo {
    string title, first, last;
    string adds, dep;
    string homephone, workphone, campusbox;
};

bool comp(PersonInfo a, PersonInfo b){
    return (a.last<b.last);
}

int main(int argc, char const *argv[])
{
    string line, input, dept;
    vector< PersonInfo> vec;
    int K, size;
    PersonInfo temp;
    
    scanf("%d", &K);
    cin.ignore();
    while(K--){
        getline(cin,dept);
        // cout<< K<< " "<< dept<<endl;
        while(getline(cin, line), line.length()){
            stringstream ss(line);
            // cout<< line<<endl;
            getline(ss, input,',' );
            temp.title = input;
            getline(ss, input,',' );
            temp.first = input;
            getline(ss, input,',' );
            temp.last = input;
            temp.dep = dept;
            getline(ss, input,',' );
            temp.adds = input;
            getline(ss, input,',' );
            temp.homephone = input;
            getline(ss, input,',' );
            temp.workphone = input;
            getline(ss, input,',' );
            temp.campusbox = input;
            vec.push_back(temp);
        }
    }
    sort(vec.begin(), vec.end(), comp);
    size = int(vec.size());
    for(int i=0 ; i<size;i++ ){
        puts("----------------------------------------");
        cout << vec[i].title << " " << vec[i].first << " " << vec[i].last << endl;
        cout << vec[i].adds << endl;
        printf("Department: "); cout << vec[i].dep << endl;
        printf("Home Phone: "); cout << vec[i].homephone << endl;
        printf("Work Phone: "); cout << vec[i].workphone << endl;
        printf("Campus Box: "); cout << vec[i].campusbox << endl;
    }
    return 0;
}
