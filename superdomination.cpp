#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<ceil(1.5)<<endl;
	for(int i = 1;i<500;i++){
		if(i%6==0){
			cout<<"mod result 0, n = "<<i<<" , true lower bound = "<<ceil(i/2.0)<<" , actual observed = "<<((2*i)/3.0)<<" , difference = "<< ((2*i)/3) - ceil(i/2) <<" , value= "<<ceil(i/2)/3<<endl;
		}
		else if(i%6==1){
			cout<<"mod result  1, n = "<<i<<" , true lower bound = "<<ceil(i/2.0)<<" , actual observed = "<<((4*floor(i/6.0)) + 1)<<" , difference = "<<((4*floor(i/6.0)) + 1)- ceil(i/2.0)<<" , value= "<<floor(ceil(i/2.0)/3.0) +1<<endl;
		}
		else if(i%6==2){
			cout<<"mod  result 2, n = "<<i<<" , true lower bound = "<<ceil(i/2.0)<<" , actual observed = "<<((4*floor(i/6.0)) + 2)<<" , difference = "<<((4*floor(i/6.0)) + 2)- ceil(i/2.0)<<" , value= "<<floor(ceil(i/2.0)/3.0) +1<<endl;
		}
		else if(i%6==3){
			cout<<"mod  result 3, n = "<<i<<" , true lower bound = "<<ceil(i/2.0)<<" , actual observed = "<<((4*floor(i/6.0)) + 2)<<" , difference = "<<((4*floor(i/6.0)) + 2)- ceil(i/2.0)<<" , value= "<<floor(ceil(i/2.0)/3.0) +1<<endl;
		}
		else if(i%6==4){
			cout<<"mod  result 4, n = "<<i<<" , true lower bound = "<<ceil(i/2.0)<<" , actual observed = "<<((4*floor(i/6.0)) + 3)<<" , difference = "<<((4*floor(i/6.0)) + 3)- ceil(i/2.0)<<" , value= "<<floor(ceil(i/2.0)/3.0)+1<<endl;
		}
		else if(i%6==5){
			cout<<"mod  result 5, n = "<<i<<" , true lower bound = "<<ceil(i/2.0)<<" , actual observed = "<<((4*floor(i/6.0)) + 3)<<" , difference = "<<((4*floor(i/6.0)) + 3)- ceil(i/2.0)<<" , value= "<<floor(ceil(i/2.0)/3.0)+1<<endl;
		}
	}
}
