#include<bits/stdc++.h>
using namespace std;

int main(){
	int msgBits=4, r=0;
    
    vector<int> msg(msgBits+1);
    // msg[5]=0;
    msg[4]=1; 
    msg[3]=0; 
    msg[2]=0; 
    msg[1]=1; 

    while(true) {
        if(pow(2,r) >= msgBits + r + 1)
            break;
        r++;
    }
    cout<<r<<endl;

    int n = msgBits + r, temp=0;

    vector<int> hamCode(n+1);
    for(int i=1;i<=n; i++){
        if(pow(2,temp) == i){
            hamCode[i] = -1;
            temp++;
        }
    }
    int j=1;
    for(int i=1 ;i<=n; i++){
        if(hamCode[i] != -1){
            hamCode[i] = msg[j];
            j++;
        }
    }


    for(int i=1; i<=n; i++){
        
        int oneCount = 0;
        if(hamCode[i] == -1){
            for(j=i+1; j<=n; j++){
                if(i & j){
                    if(hamCode[j] == 1) oneCount++; 
                }
            }
            
            if(oneCount % 2 == 0)
                hamCode[i] = 0;
            else
                hamCode[i] = 1;
        }
    }

    
    for(int i=n; i>0; i--)
        cout<<hamCode[i]<<" ";
    cout<<endl;

    return 0;
}
