#include<bits/stdc++.h>
using namespace std;

long long int findMinPath(long long int mat[100][100],long long int row,long long int col,long long int i,long long int j,long long int len){
	
	if(i<0 || i>=row ||j<0 || j>=col) return INT_MAX;
	
	if((i==0||i==row-1||j==0||j==col-1) && (mat[i][j]==0||mat[i][j]==2))return len;
	if(mat[i][j]==1||mat[i][j]==-1) return INT_MAX;
	mat[i][j] = -1;
	long long int l = findMinPath(mat,row,col,i,j-1,len+1); 
	long long int r = findMinPath(mat,row,col,i,j+1,len+1);
	long long int u = findMinPath(mat,row,col,i-1,j,len+1);
	long long int d = findMinPath(mat,row,col,i+1,j,len+1);
	if(l<=u && l<=d && l<=r)return l;
	if(r<=u && r<=d && r<=l)return r;
	if(d<=u && d<=l && d<=r)return d;
	return u;
}
int main(){
	long long int mat[100][100],row,col;
	cin>>row>>col;
	for(long long int i=0;i<row;i++){
		for(long long int j=0;j<col;j++){
			cin>>mat[i][j];
		}
	}
	
	for(long long int i=0;i<row;i++){
		for(long long int j=0;j<col;j++){
			if(mat[i][j]==2){
				int len = findMinPath(mat,row,col,i,j,0);
				if(len==INT_MAX) cout<<"-1";
				else cout<<len;
			}
		}
	}
}
