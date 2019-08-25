#include<bits/stdc++.h>
using namespace std;
int main(){
	int np;
	cout<<"Enter the number of num,rem pairs: ";
	cin>>np;
	int num[np];
	int rem[np];
	for(int i=0;i<np;i++){
		cout<<"\nEnter num: ";
		cin>>num[i];
		cout<<"\nEnter rem: ";
		cin>>rem[i];
	}
	cout<<endl;
	int x=1;
	while(true){
		int f=0;
		for(int i=0;i<np;i++){
			if(x%num[i]!=rem[i]){
				f=1;
				break;
			}
		}
		if(f==0){
			cout<<x<<endl;
			break;
		}
		x++;
	}
}
