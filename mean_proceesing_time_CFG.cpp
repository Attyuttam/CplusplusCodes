#include<bits/stdc++.h>
using namespace std;

void find_max(vector< vector<double> > graph_prob,vector< vector<double> > graph_time,int nov){

	int flag = 0;

	//find maxPath
	for(int i=1;i<nov-1;i++){
		vector<int> node_vec;
		vector<double> weight_vec;
		
		vector<int> node_vec_time;
		vector<double> weight_vec_time;
		
		flag = 0;
		for(int j=0;j<nov;j++){
			//seeking for nodes from which some edges have come out
			if(graph_prob[i][j]>0){
				node_vec.push_back(j);
				weight_vec.push_back(graph_prob[i][j]);	
				
				node_vec_time.push_back(j);
				weight_vec_time.push_back(graph_time[i][j]);	
				
				graph_prob[i][j]=0;
				graph_time[i][j]=0;
				
				flag = 1;
			}
		}
		//if such node from which edges have come out are found
		if(flag == 1){
			//find all the nodes which has incidence edges on node i
			for(int a=0;a<nov;a++){
				if(graph_prob[a][i]>0){
					//find the nodes that correspond to the one in node_vec
					double temp = graph_prob[a][i];
					double temp_time = graph_time[a][i];
					
					graph_prob[a][i] = 0.0;
					graph_time[a][i] = 0.0;
					//checking for loops
					for(int b=0;b<nov;b++){
						int loop_check = 0;
					
						for(int c =0 ;c <node_vec.size();c++){
							if(node_vec[c]==b && b==i){
							
								weight_vec_time[c] = ((weight_vec_time[c]*weight_vec[c])/(double)(1-weight_vec[c]));
								temp_time+=weight_vec_time[c];
								
								weight_vec[c] = (1/(double)(1-weight_vec[c]));
								temp*=weight_vec[c];

								
								//remove c from there and its corresponding weight too
								node_vec[c]=-1;
								weight_vec[c]=-1;
								node_vec_time[c]=-1;
								weight_vec_time[c]=-1;
								loop_check = 1;
								break;
							}
						}
						if(loop_check == 1)break;
					}
					for(int b=0;b<nov;b++){
						for(int c =0 ;c <node_vec.size();c++){
							if(node_vec[c]==b){
								cout<<endl<<node_vec[c]<<endl;
								if(graph_time[a][b]!=0)
									graph_time[a][b]=(double)(((graph_prob[a][b]*graph_time[a][b])+((weight_vec_time[c] + temp_time)*(weight_vec[c]*temp)))/(double)((weight_vec_time[c] + temp_time)+(weight_vec[c]*temp)));
								else
									graph_time[a][b] +=	(double)(weight_vec_time[c] + temp_time);								
								graph_prob[a][b]+=(double)(weight_vec[c]*temp);
							
							}
						}
						cout<<"\nintermediate calculations: \n";
						for(int i=0;i<nov;i++){
							for(int j=0;j<nov;j++){
								cout<<graph_time[i][j]<<" ";
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
			cout<<graph_time[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Thus the final max probability is: "<<graph_prob[0][nov-1]<<endl;
		cout<<"Thus the final mean processing time: "<<graph_time[0][nov-1]<<endl;


}
	
int main(){
	vector< vector<double> > graph_prob;
	vector< vector<double> > graph_time;
	int noe;
	int nov;

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
		graph_prob.push_back(temp_vec);
	}
	cout<<"\nEnter the incidence matrix of processing times: ";
	for(int i=0;i<nov;i++){
		vector<double> temp_vec;
		for(int j=0;j<nov;j++){
			double temp;
			cin>>temp;
			temp_vec.push_back(temp);
		}
		graph_time.push_back(temp_vec);
	}
	find_max(graph_prob,graph_time,nov);
}
