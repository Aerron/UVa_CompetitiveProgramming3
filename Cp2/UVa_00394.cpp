#include <bits/stdc++.h>
using namespace std;

typedef struct arr
{
    int base, size, dim;
    int L[10];
    int U[10];
    int C[10];
}arr;

int main(int argc, char const *argv[])
{
    int N,R, input;
    cin >> N>> R;
    map<string, arr*> arr_map;
    string name;
    while(N--){
        cin >> name;
        arr *temp = new(arr);
        cin >> temp->base >> temp->size >> temp->dim;
        
        temp->C[temp->dim] = temp->size;
        for(int i=1; i<= temp->dim; i++){
            cin>> temp->L[i] >> temp->U[i];
        }
        temp->C[0] = temp->base -(temp->C[temp->dim]* temp->L[temp->dim] ) ;
        for(int i= temp->dim -1; i>0; i--){
            temp->C[i] = temp->C[i+1] * ( temp->U[i+1] - temp->L[i+1] +1);
            temp->C[0] = temp->C[0] - (temp->C[i] * temp->L[i]);
        }
        arr_map[name] = temp;
    }
    
    while(R--){
        cin >> name;
        arr *temp = arr_map[name];
        int arr_add = temp->C[0];
        cout << name << "[";
        for(int i = 1; i<=temp->dim; i++ ){
            cin>> input;
            if(i==1) cout << input;
            else cout << ", "<< input;
            arr_add+= input* temp->C[i];
        }
        cout<<"] = "<< arr_add<< endl;
        
    }
    
    return 0;
}



