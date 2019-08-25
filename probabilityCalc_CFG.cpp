#include<bits/stdc++.h>
using namespace std;

void find_max(vector< vector<double> > graph,vector<double> weights,int nov){
	int maxPaths = 0;

	int flag = 0;

	//find maxPath
	for(int i=1;i<nov-1;i++){
		vector<int> node_vec;
		vector<double> weight_vec;
		flag = 0;
		for(int j=0;j<nov;j++){
			//seeking for nodes from which some edges have come out
			if(graph[i][j]>0){
				node_vec.push_back(j);
				weight_vec.push_back(graph[i][j]);	
				graph[i][j]=0;
				
				flag = 1;
			}
		}
		//if such node from which edges have come out are found
		if(flag == 1){
			//find all the nodes which has incidence edges on node i
			for(int a=0;a<nov;a++){
				if(graph[a][i]>0){
					//find the nodes that correspond to the one in node_vec
					double temp = graph[a][i];
					
					graph[a][i] = 0;
				
					//checking for loops
					for(int b=0;b<nov;b++){
						int loop_check = 0;
					
						for(int c =0 ;c <node_vec.size();c++){
							if(node_vec[c]==b && b==i){
							
								weight_vec[c] = (1/(double)(1-weight_vec[c]));
						
								temp*=weight_vec[c];
								
								//remove c from there and its corresponding weight too
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

}
	
int main(){
	vector< vector<double> > graph;
	int noe;
	int nov;
	vector<double> weights;

	cout<<"Enter the number of vertices : ";
	cin>>nov;
	cout<<"\nEnter the incidence matrix of probabilities: ";
	for(int i=0;i<nov;i++){
		vector<double> temp_vec;
		for(int j=0;j<nov;j++){
			double temp;
			cin>>temp;
			temp_vec.push_back(temp);
		}
		graph.push_back(temp_vec);
	}
	find_max(graph,weights,nov);
}
