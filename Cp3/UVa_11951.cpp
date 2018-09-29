//small error Have to debug
#include <bits/stdc++.h>
using namespace std;

long arr[105][105];

int main(int argc, char const *argv[])
{
    long TC, N, M, K, ai1, ai2, aj1, aj2, sum, max_val, case_val=0;
    cin>>TC;
    while(TC--){
        case_val++;
        cin>>N>>M>>K;
        for (long i = 0; i < N; ++i)for (long j = 0; j < M; ++j)
        {
            cin>>arr[i][j];
            if(i>0) arr[i][j]+=arr[i-1][j];
            if(j>0) arr[i][j]+=arr[i][j-1];
            if(i>0 && j>0) arr[i][j]-=arr[i-1][j-1];
        }
        
        max_val = 0;
        ai1=aj1=ai2=aj2=0;
        for(long i=0; i<N; i++)for(long j=0; j<M; j++)for(long i1=i; i1<N; i1++)for(long j1=j; j1<M; j1++){
            if( (abs(ai1-ai2)+1)*(abs(aj1-aj2)+1)<= (abs(i-i1)+1)*(abs(j-j1)+1) ){
                sum=arr[i1][j1];
                if(i>0) sum-=arr[i-1][j1];
                if(j>0) sum-=arr[i1][j-1];
                if(i>0 && j>0) sum+=arr[i-1][j-1];
                // if(sum>K)break;
                // if((abs(ai1-ai2)*abs(aj1-aj2))==(abs(i-i1)*abs(j-j1)) && (sum<max_val)){
                //     max_val=sum;
                //     ai1=i; ai2=i1; aj1=j; aj2=j1;
                // }
                // cout<<sum<<", "<<K<<", "<<max_val<<"    "<<"i1: "<<ai1<<" "<<i<<", i2: "<<ai2<<" "<<i1<<", j1: "<<aj1<<" "<<j<<", j2: "<<aj2<<" "<<j1<<"          "<<(abs(ai1-ai2)+1)*(abs(aj1-aj2)+1)<<"     "<<(abs(i-i1)+1)*(abs(j-j1)+1)<<endl;
                if(sum>K) break;
                // cout<<"test"<<endl;
                // cout<<"sum: "<<sum<<"	max_val: "<<max_val<<endl;
                // if(sum>max_val)
                	// cout<<"true"<<endl;
                // if((abs(ai1-ai2)+1)*(abs(aj1-aj2)+1)!= (abs(i-i1)+1)*(abs(j-j1)+1))
                	// cout<<"true2"<<endl;
                if(max_val==0)
                {
                    max_val=sum;
                    ai1=i; ai2=i1; aj1=j; aj2=j1;
                    // cout<<"ack1"<<endl;
                }
                else if( (abs(ai1-ai2)+1)*(abs(aj1-aj2)+1)== (abs(i-i1)+1)*(abs(j-j1)+1) && (sum<max_val)){
                    max_val=sum;
                    ai1=i; ai2=i1; aj1=j; aj2=j1;
                    // cout<<"ack2"<<endl;
                }
                else if((abs(ai1-ai2)+1)*(abs(aj1-aj2)+1)!= (abs(i-i1)+1)*(abs(j-j1)+1)&&(sum>max_val))
                {
                    max_val=sum;
                    ai1=i; ai2=i1; aj1=j; aj2=j1;
                    // cout<<"ack3"<<endl;
                }
                // cout<<"ack4"<<endl;
                
            }
            
        }
        if(max_val!=0)cout<<"Case #"<<case_val<<": "<<(abs(ai1-ai2)+1)*(abs(aj1-aj2)+1)<<" "<<max_val<<endl;
        else cout<< "Case #"<<case_val<<": "<<0<<" "<<0<<endl;
        
        
    }
    
    return 0;
}
