
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int allVisited(int visited[100],int V){
    for(int i=1;i<V+1;i++){
        if(visited[i]==0)return 0;
    }
    return 1;
}
int spanningTree(int V, int e, vector<pair<int, int>> adj[])
{
    
    // Your code here
    int visited[100];
    for(int i=1;i<V+1;i++){
        visited[i]=0;
    }
    pair<int,int> v = pair<int,int>(1,0);
    int sum=0;
   while(!allVisited(visited,V)){
       int vertex = v.first;
       //cout<<"\nOUTER\n";
       //cout<<vertex<<" "<<sum<<" "<<adj[vertex].size()<<endl;
      
       //cout<<endl;
       visited[vertex]=1;
       if(allVisited(visited,V)){
	   		//cout<<"hoh";
		   break;
	   	
	   }
       //cout<<"nVISITED\n";
       // for(int i=1;i<=V;i++)cout<<visited[i]<<" ";
       int nextVertex;
       int nextVertexWeight=INT_MAX;
       int f=0;
       for(int i=0;i<adj[vertex].size();i++){
       	 //cout<<"\nINNER ka bahar wala\n";
       	//cout<<adj[vertex][i].first<<endl;
           if(visited[adj[vertex][i].first]==0 && adj[vertex][i].second+v.second<nextVertexWeight){
               f=1;
               //cout<<"\nINNER\n";
         //      cout<<"\nadj: "<<adj[vertex][i].first<<endl;
               nextVertex=adj[vertex][i].first;
               nextVertexWeight=adj[vertex][i].second+v.second;
           }
       }
       v=pair<int,int>(nextVertex,nextVertexWeight);
       sum=nextVertexWeight;
       cout<<sum<<endl;
      
   }
   return sum;
   
}
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
	int n,e;
    cin >> n>> e;
    int x,y, w;
    
    vector<pair<int, int>> adj[n+1];
    for(int i = 0;i < e;++i)
    {
    	cin >> x >> y >> w;
    	adj[x].push_back(make_pair(y, w));
    	adj[y].push_back(make_pair(x, w));
    }
    cout << spanningTree(n, e, adj) << endl;
	}
	
    return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


/*  Function to find the sum of weights of edges in minimum spanning tree
*   V: number of vertices
*   e: number of edges
*   adj[]: array of vectors representing the graph
*/

