#include<bits/stdc++.h>
using namespace std;

void find_max(vector< vector<int> > graph,vector<int> weights,int nov){
	int maxPaths = 0;
	int minPaths = 0;
	int flag = 0;
	vector< vector<int> > graph_min;
	for(int i=0;i<nov;i++){
		vector<int> temp_graph;
		for(int j=0;j<nov;j++){
			temp_graph.push_back(graph[i][j]);
		}
		graph_min.push_back(temp_graph);
	}
	//find maxPath
	for(int i=1;i<nov-1;i++){
		vector<int> node_vec;
		vector<int> weight_vec;
		flag = 0;
		for(int j=0;j<nov;j++){
			//seeking for nodes from which some edges have come out
			if(graph[i][j]>0){
				node_vec.push_back(j);
				weight_vec.push_back(graph[i][j]);	
				graph[i][j]=0;
				graph_min[i][j]=0;
				flag = 1;
			}
		}
		//if such node from which edges have come out are found
		if(flag == 1){
			//find all the nodes which has incidence edges on node i
			for(int a=0;a<nov;a++){
				if(graph[a][i]>0){
					//find the nodes that correspond to the one in node_vec
					int temp = graph[a][i];
					int temp_min = graph_min[a][i];
					graph[a][i] = 0;
					graph_min[a][i]=0;
					//checking for loops
					for(int b=0;b<nov;b++){
						int loop_check = 0;
						int min_weight_var = 0;
						for(int c =0 ;c <node_vec.size();c++){
							if(node_vec[c]==b && b==i){
								cout<<"\nloop detected!\nEnter 1 if the loop runs for 0,1,2,..k times \n2 if the loop runs for exactly k times\n";
								int opt,k,loop_val =0 ;
								cin>>opt;
								cout<<"\nEnter the value of k:";
								cin>>k;
								min_weight_var = weight_vec[c];
								if(opt==1){
									for(int h=0;h<=k;h++){
										loop_val += pow(weight_vec[c],h);
									}
									weight_vec[c]=loop_val;
								}
								else{
									weight_vec[c] = pow(weight_vec[c],k);
								}
								
								temp*=weight_vec[c];
								temp_min = max(temp_min,min_weight_var);
								//remove 3 from there and its corresponding weight too
								node_vec[c]=-1;
								weight_vec[c]=-1;
								loop_check = 1;
								break;
							}
						}
						if(loop_check == 1)break;
					}
					for(int b=0;b<nov;b++){
						for(int c =0 ;c <node_vec.size();c++){
							if(node_vec[c]==b){
								graph[a][b]+=(weight_vec[c]*temp);
								graph_min[a][b] =max(weight_vec[c],temp_min);
							}
						}
						cout<<"\nintermediate calculations: \n";
						for(int i=0;i<nov;i++){
							for(int j=0;j<nov;j++){
								cout<<graph[i][j]<<" ";
							}
							cout<<endl;
						}
					}	
				}
			}
		}
	}
	cout<<"\nfinal\n";
	for(int i=0;i<nov;i++){
		for(int j=0;j<nov;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Thus the final max number of times the loop runs is: "<<graph[0][nov-1]<<endl;
	cout<<"Thus the final min number of times the loop runs is: "<<graph_min[0][nov-1]<<endl;
}
	
int main(){
	vector< vector<int> > graph;
	int noe;
	int nov;
	vector<int> weights;

	cout<<"Enter the number of vertices : ";
	cin>>nov;
	cout<<"\nEnter the incidence matrix: ";
	for(int i=0;i<nov;i++){
		vector<int> temp_vec;
		for(int j=0;j<nov;j++){
			int temp;
			cin>>temp;
			temp_vec.push_back(temp);
		}
		graph.push_back(temp_vec);
	}
	find_max(graph,weights,nov);
}
