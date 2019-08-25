#include<bits/stdc++.h>
using namespace std;
int calcCost(vector<int> v,int n){
	int c=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(v[j]<v[i])c++;
		}
	}
	return c;
}
vector<int> swapElement(vector<int> v,int i,int j){
	int t=0;
	t = v[i];
	v[i]=v[j];
	v[j]=t;
	return v;
}
void sortVector(vector<int> v,int n){
	int bC = calcCost(v,n);
	int nC=0,swap=0;;
	while(bC>0){
		for(int i=0;i<n-1;i++){
			v = swapElement(v,i,i+1);
			nC = calcCost(v,n);
			if(nC<bC){
				swap++;
				cout<<"\nAfter swap "<<swap<<endl;
				for(int i=0;i<n;i++){
					cout<<v[i]<<" ";
				}
				cout<<endl;
				bC=nC;
			}	
			else{
				v = swapElement(v,i,i+1);
			}
		}
	}
	cout<<"\nFinal swap "<<endl;
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}
int main(){
	int n;
	vector<int> v;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"\nEnter the elements: ";
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sortVector(v,n);
}
