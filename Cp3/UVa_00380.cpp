#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pt;
typedef pair<pt, string> ps;
typedef vector<ps> vs;

map <string, vs > call_forwarding;

string origin_val;


string check(int ext_time, string ext_ori){
    
    if(call_forwarding.find(ext_ori)==call_forwarding.end()){
        return ext_ori;
    }
    
    // else if(ext_time< call_forwarding[ext_ori].first ){
    //     if(call_forwarding[ext_ori].second == origin_val)
    //         return "9999";
    //     else
    //         return check(ext_time,call_forwarding[ext_ori].second );
    // }
    // else
    //     return ext_ori;
    
    else{
        vs vec = call_forwarding[ext_ori];
        for(auto a: vec){
            if(a.first.first <= ext_time && ext_time<=a.first.second){
                if(a.second == origin_val)
                    return "9999";
                else
                    return check(ext_time, a.second);
            }
        }
        return ext_ori;
    }
}




int main(int argc, char const *argv[])
{
    int TC, test_case=0;
    cin>>TC;
    string ext_ori, ext_end, input;
    int time, ext_time;
    cout<< "CALL FORWARDING OUTPUT"<<endl;
    while(TC--){
        
        test_case++;
        cout<< "SYSTEM "<<test_case<<endl;
        call_forwarding.clear();
        while(cin>>ext_ori, ext_ori!="0000"  ){
            cin>>time>> ext_time>> ext_end;
            call_forwarding[ext_ori].push_back(make_pair( make_pair(time,time+ext_time) ,ext_end ));
        }
        
        while(cin>> input, input!="9000"){
            cin>> ext_ori;
            origin_val = ext_ori;
            cout<<"AT "<<input<<" CALL TO "<<ext_ori <<" RINGS " <<check( stoi(input), ext_ori)<<endl;
        }
        
    }
    cout<<"END OF OUTPUT"<<endl;
    
    return 0;
}




