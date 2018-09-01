#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int K, max_len, size, number, element, R;
    vector <string> vec;
    string input;
    
    
    while(scanf("%d", &K)!=EOF){
        size = K;
        vec.clear();
        cin.ignore();
        while(K--){
            //            cin>>input;
            getline(cin, input);
            vec.push_back(input);
            
        }
        sort(vec.begin(), vec.end());
        max_len = -1;
        for(int i=0; i<size; i++){
            if(max_len < int(vec[i].length()) ) max_len = int(vec[i].length());
            //            cout<< max_len << " "<< vec[i]<< " "<< vec[i].length()<<endl;
        }
        number = 62/(max_len+2);
        
        R = ceil(size/float(number));
        for(int i=0; i<60; i++){
            cout<< '-';
        }
        //        cout<< number<< " "<< size<< " "<< R<< " "<< max_len <<endl;
        cout<< "\n";
        //        cout.precision(number+2);
        //        cout.width(max_len+2);
        for(int i=0; i<R;i++){
            element = i;
            for(int j=0; (j<number) &&(i+j*R)<size ; j++){
                element = i+ j* R;
                if( (j<(number-1))& ((element+R)<size) )cout.width(max_len+2);
                else cout.width(max_len);
                cout<<left<<vec[element];
            }
            cout<<"\n";
        }
    }
    return 0;
}
