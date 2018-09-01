#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    vector <vector <int> > vec;
    vector <int> col;
    vector <int> row;
    int K, r_count, c_count, r_row, c_col;
    
    while(scanf("%d", &K), K){
        vec.assign(K, (vector < int>(K, 0)) );
        row.clear();
        col.clear();
        
        for (int i = 0; i < K; ++i)
        {
            for (int j = 0; j < K; ++j)
            {
                cin>>vec[i][j];
                /* code */
            }
            /* code */
        }
        
        
        
        for(int i= 0; i<K; i++){
            row.push_back(accumulate(vec[i].begin(), vec[i].end(),0));
        }
        
        for(int i=0; i<K; i++){
            int temp = 0;
            for(int j=0;j<K; j++){
                temp += vec[j][i];
            }
            col.push_back(temp);
        }
        
        r_count = 0;
        c_count = 0;
        r_row=0;
        c_col=0;
        for(int i=0; (i<K); i++){
//            cout<< col[i]<< " " << row[i]<<endl;
            if( col[i]%2!=0){
                c_count++;
                c_col = i;
            }
            if(row[i]%2 !=0){
                r_count++;
                r_row = i;
            }
        }
//        cout<< c_count<< " "<< r_count<< " "<< r_row<< " "<< c_col<< endl;
        if(!(c_count||r_count))
            cout<< "OK" <<endl;
        else if( (c_count==1) & (r_count==1) )
            cout<< "Change bit ("<< r_row+1<< ","<< c_col+1<<")"<< endl;
        else
            cout<< "Corrupt"<< endl;
        
    }
    return 0;
}
