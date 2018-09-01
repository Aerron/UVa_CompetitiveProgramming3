// incomplete: Have to write output format and add null solved teams


#include <bits/stdc++.h>
using namespace std;

struct teamstat
{
    int time, team, problems;
};

#define pp pair<int, string>
#define ps pair<int, int>

int caltime(string t){
    int min, hr;
    sscanf(t.c_str(), "%d:%d", &hr, &min);
    return (min+hr*60);
}

bool func(teamstat a, teamstat b){
	if(a.problems!=b.problems) return (a.problems>b.problems);
	else{
		if(a.time!=b.time) return (a.time < b.time);
		else{
			return (a.team<b.team);

		}
	}
}

int main(int argc, char const *argv[])
{
    vector <teamstat>vec;
    map <pp, int> pre;
    map <pp, bool> sol_sums;
    
    
    string line, input_prob, input_time, input_sol;
    stringstream ss;
    teamstat temp;
    pp mp;
    while(getline(cin, line), line.length()){
        ss.clear();
        ss.str(line);
        ss>>temp.team>>input_prob>> input_time>> input_sol;
        mp = make_pair(temp.team,input_prob );
        auto search_mp = sol_sums.find(mp);
        
        if( input_sol == "N" ){
            pre[mp]+=20 ;
//            cout << mp.first<< mp.second<<" "<< pre[mp]<<endl;
            if(search_mp==sol_sums.end())
                sol_sums[mp]=false;
            else if(search_mp->second!=true )
                search_mp->second = false;
        }
        else if(search_mp == sol_sums.end()){
//            cout<< mp.first<< " "<< mp.second<<endl;
            search_mp->second = true;
            auto a= vec.begin();
            for(; a!= vec.end(); a++){
                if(a->team == temp.team){
                    a->problems++;
                    a->time += caltime(input_time);
                    break;
                }
            }
            if(a==vec.end()){
                temp.time = caltime(input_time);
                temp.problems = 1;
                vec.push_back(temp);
            }
            
        }
        else if(search_mp->second!=true ){
//            cout<< mp.first<< mp.second<<endl;
            search_mp->second = true;
            auto a= vec.begin();
            for(; a!= vec.end(); a++){
                if(a->team == temp.team){
                    a->problems++;
                    a->time += (caltime(input_time)+pre[mp]);
                    break;
                }
            }
            if(a==vec.end()){
                temp.time = caltime(input_time)+pre[mp];
                temp.problems = 1;
                vec.push_back(temp);
            }
            
            
        }
    }
    cout << "RANK TEAM PRO/SOLVED TIME" << endl;
    for(auto a: vec ){
        cout<< a.team<< " "<< a.time<< " "<< a.problems<<endl;
    }
    sort(vec.begin(), vec.end(), func);

    return 0;
}
