#include<bits/stdc++.h>
using namespace std;

void print(int x, int win, int frames){
	for(int i=x;i<x+win && i<frames;i++){
		cout<<"sending :"<<i+1<<endl;
	}
}

void transmit(int frames, int win){
	int i=0;
	print(i, win, frames);
	
	while(i<frames){
		int k=0;
		for(int j=i; j<i+win && j<frames; j++){
			int r = rand() % 4;
			bool rand = (r == 0) ? false : true;
			
			if(rand){
				cout<<"Ack :"<<j+1<<endl;
				cout<<"sending :"<<(j+1+win)<<endl;
				k++;
			}
			else{
				cout<<"Error :"<<j+1<<endl;
				cout<<"Resending window"<<endl;
				print(j, win, frames);
			}
		}	
		i += k;
		cout<<endl;
	}
}
	
int main(){
	srand(time(NULL));
	int frames = 6, winSize =3;
	transmit(frames, winSize);
	
	return 0;
	}
