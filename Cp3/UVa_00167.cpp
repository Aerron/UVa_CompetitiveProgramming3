#include <bits/stdc++.h>
using namespace std;
int Arr[9][9];
int max_value;
int row[9];

bool check(int row_num, int col_value){
    for(int prev=1; prev<row_num; prev++){
        if (row[prev]==col_value || abs(row[prev]-col_value)==abs(row_num-prev) )
        {
            return false;
        }
    }
    return true;
}


void backtracking(int row_num){
	// cout<< "Row Number: "<< row_num<<endl;
    if(row_num==9){
        int sum =0;
        for(int i=1;i<9;i++ ){
            sum+= Arr[i][row[i]];
        }
        // cout<< row[1]<<" "<< row[2]<<" "<< row[3]<<" "<< row[4]<<" "<< row[5]<<" "<< row[6]<<" "<< row[7]<<" "<< row[8]<<" "<<endl;
        // cout<< "Max Value: "<<max_value<<" "<<sum<<endl;
        max_value = max(max_value, sum);
        return;
    }
    for(int i=1; i<9; i++){
        if(check(row_num, i)){
            row[row_num]=i;
            backtracking(row_num+1);
        }
    }
}


int main(int argc, char const *argv[])
{
    int TC, input;
    scanf("%d", &TC);
    while(TC--){
        for(int i=1; i<9; i++){
            for(int j=1; j<9; j++){
                cin>>input;
                Arr[i][j] =  input;
            }
        }
        max_value = INT_MIN;
        for(int i=1; i<9; i++){
            memset(row, 0, sizeof row);
            row[1] = i;
            // cout<< "test "<< i<<endl;
            
            // cout<< row[1]<<" "<< row[2]<<" "<< row[3]<<" "<< row[4]<<" "<< row[5]<<" "<< row[6]<<" "<< row[7]<<" "<< row[8]<<" "<<endl;
            backtracking(2);
        }
        cout.fill(' ');
        cout<< setw(5)<<max_value<<endl;
    }
    return 0;
}




