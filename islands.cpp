#include<bits/stdc++.h>
using namespace std;
int maxIslands=0;
void findUtil(vector< vector<char> > sea,int i,int j,int numI,char d){
	if(i<0 || j<0 || i>=sea.size() || j>=sea[0].size()){
		if(numI>maxIslands){
			maxIslands = numI;
		}
		return;
	}
	if(sea[i][j]=='#'){
		numI++;
		sea[i][j]='*';
		cout<<i<<" "<<j<<" "<<numI<<endl;
		findUtil(sea,i-1,j,numI,'u');
		findUtil(sea,i+1,j,numI,'d');
		findUtil(sea,i,j+1,numI,'r');
		findUtil(sea,i,j-1,numI,'l');
	}
	else if (sea[i][j]=='~'){
		if(d=='u'){
			findUtil(sea,i-1,j,numI,'u');
		}
		else if(d=='d'){
			findUtil(sea,i+1,j,numI,'u');
		}
		else if(d=='l'){
			findUtil(sea,i,j-1,numI,'u');
		}
		else if(d=='r'){
			findUtil(sea,i,j+1,numI,'u');
		}
	}
}
int find(vector< vector<char> > sea){
	findUtil(sea,0,0,0,'x');
	return maxIslands;
}
int main(){
	vector< vector<char> > sea;
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++){
		vector<char> v;
		for(int j=0;j<c;j++){
			char temp;
			cin>>temp;
			v.push_back(temp);
		}
		sea.push_back(v);
	}
	int res= find(sea);
	cout<<res<<endl;
}
