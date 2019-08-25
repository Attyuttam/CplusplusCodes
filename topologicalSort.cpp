#include<bits/stdc++.h>
using namespace std;
stack<int> topoSortUtil(vector< vector<int> > adj,int visited[100],stack<int> s,int val){
	
	if(adj[val].size()==0){
		s.push(val);
		visited[val]=1;
	}
	else{
	//	cout<<val<<endl;
		for(int i=0;i<adj[val].size();i++){
			if(visited[adj[val][i]]==0)
				s=topoSortUtil(adj,visited,s,adj[val][i]);
		}
		s.push(val);
		//cout<<"\n "<<val<<" "<<s.top()<<"getting pushed!\n";
		visited[val]=1;
		
	}
	return s;
}
int allVisited(int visited[100],int n){
	for(int i=0;i<n;i++){
		if(visited[i]==0)return 0;
	}
	return 1;
}
void topoSort(vector< vector<int> > adj,int visited[100],int n){
	stack<int> s;
	for(int i=0;i<n;i++){
		if(visited[i]==0){
			s = topoSortUtil(adj,visited,s,i);
		}
	}	
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main(){
	int n;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	vector< vector<int> > adj;
	int visited[100];
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	for(int i=0;i<n;i++){
		cout<<"Enter the vertices adjacent to vertex "<<i<<" : \n";
		cout<<"Enter the number of vertices adjacent to vertex "<<i<<" : ";
		int num_adj;
		cin>>num_adj;
		vector<int> v;
		cout<<"\nEnter the vertices : \n";
		for(int j=0;j<num_adj;j++){
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		adj.push_back(v);
	}
	topoSort(adj,visited,n);
}
