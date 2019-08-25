#include<bits/stdc++.h>
using namespace std;
int findParent(int checkVector[100],int vertex){
	if(checkVector[vertex]==-1)return vertex;
	return findParent(checkVector,checkVector[vertex]);
}
void Union(int checkVector[100],int i,int j){
	int x=findParent(checkVector,i);
	int y=findParent(checkVector,j);
	if(x!=y){//this is the union operation
		checkVector[x]=y;	
	}
}
int checkCycle(vector< vector<int>> adj,int v){
	int checkVector[100];
	int mat[v][v]={0};
	for(int i=0;i<v;i++)checkVector[i]=-1;
	for(int i=0;i<v;i++){
		for(int j=0;j<adj[i].size();j++){
			if(i!=j && (mat[i][j]==0)){
			
				int x=findParent(checkVector,i);
				int y=findParent(checkVector,j);
				if(x!=y){//this is the union operation
					Union(checkVector,x,y);	
				}
				else{
					return 1;
				
				}
				mat[i][j]=1;
				mat[j][i]=1;	
			}
		}
	}
	return 0;
}
int main(){
	int v;
	int e;
	cout<<"Enter the number of vertices: ";
	cin>>v;
	
	vector<vector<int>> adj;
	for(int i=0;i<v;i++){
		vector<int> v;
		cout<<"\nEnter the number of adjacent vertices of "<<i<<" : ";
		cin>>e;
		for(int j=0;j<e;j++){
			int t;
			cin>>t;
			v.push_back(t);
		}
		adj.push_back(v);
	}
	if(checkCycle(adj,v))
		cout<<"\nCYCLE EXISTS";
	else
		cout<<"\nCYCLE DOES NOT EXIST";
}
