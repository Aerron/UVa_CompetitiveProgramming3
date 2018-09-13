
#include <bits/stdc++.h>
using namespace std;

int a,b;
int row[9];
int number_out;


bool check(int row_val, int column_val){
    for(int prev =1; prev<row_val; prev++){
        if( row[prev]==column_val || abs(row[prev]-column_val)==abs(row_val-prev) ){
            return false;
        }
    }
    return true;
}

void backtracking(int row_num){
    if(row_num==9 && row[b]==a){
        cout.fill(' ');
        cout<<setw(2)<<number_out<<"      ";
        for(int i=1; i<9; i++){
        	if(i!=1) cout<<" ";
            cout<< row[i];
        }
        cout<<endl;
        number_out++;
        return;
    }
    
	for(int i=1; i<9; i++){
        if(check(row_num, i)){
            row[row_num] = i;
            backtracking(row_num+1);
        }
	}
    
    
}


int main(int argc, char const *argv[])
{
    int TC, test_case=1;
    cin>>TC;
    while(TC--){
    	if(test_case!=1)
    		cout<<endl;
    	test_case++;
    	cout << "SOLN       COLUMN\n";
    	cout<< " #      1 2 3 4 5 6 7 8\n\n";
        number_out=1;
        cin>>a>>b;
        memset(row, 0, sizeof(row));
        backtracking(1);
    }
    return 0;
}
