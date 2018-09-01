#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    
    vector <int> vec;
    char temp;
    bool bool_value, running = true;
    int current_time, input, T = 1;
    string line;
    while(getline(cin, line)){
        vec.clear();

        int lowest = 91;

        stringstream ss(line);

        while(ss>> input){
            lowest = min(lowest , input);
            vec.push_back(input);
        }

        bool_value = true;
        sort(vec.begin(), vec.end(), greater<int>());
        for(current_time= lowest * 2; (current_time <= 3601) && bool_value; current_time ++){
            bool_value = false;
            for(auto i: vec){
                if( (current_time % (i*2) ) >= (i-5) ){
                    bool_value = true;
                    break;
                }
            }
            
        }
        
        current_time--;
        if(current_time> 3600){
            cout << "Set " << T << " is unable to synch after one hour.\n";
        }
        else
            cout << "Set " << T << " synchs again at " << current_time / 60 << " minute(s) and " << current_time % 60 << " second(s) after all turning green.\n";
        
        T++;
        if (cin.fail()){
            running = false;
        }
    }
    
    return 0;
}
