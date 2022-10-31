#include<bits/stdc++.h>
using namespace std;

void hamming(vector<int> &msg){
    int msgBits = msg.size()-1, r=0;
    
    while(true) { //---------------------------find r
        if(pow(2,r) >= msgBits + r + 1)
            break;
        r++;
    }
    cout<<r<<endl;

    int n = msgBits + r, temp=0;

    vector<int> hamCode(n+1);//create hamming without parity
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


    for(int i=1; i<=n; i++){// find parity
        
        int oneCount = 0;
        if(hamCode[i] == -1){
            for(j=i+1; j<=n; j++){
                if(i & j){ // if pi has component in j  [i to n]
                    if(hamCode[j] == 1) oneCount++; 
                }
            }
            
            if(oneCount % 2 == 0) // even parity 
                hamCode[i] = 0;
            else
                hamCode[i] = 1;
        }
    }

    
    for(int i=n; i>0; i--)
        cout<<hamCode[i]<<" ";
    cout<<endl;
}

int main(){
	int msgBits=4;
    
    vector<int> msg(msgBits+1);
    // msg[5]=0;
    msg[4]=1; 
    msg[3]=0; 
    msg[2]=0; 
    msg[1]=1; 

    hamming(msg);

    return 0;
}
