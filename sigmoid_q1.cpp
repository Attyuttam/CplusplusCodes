#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue< pair<int,int> > pq;
	pq.push(make_pair(5,1));
	pq.push(make_pair(15,12));
	pq.push(make_pair(105,21));
	pq.push(make_pair(55,15));
	
	for(int i=0;i<4;i++){
		cout<<pq[i].first<<" "<<pq[i].second<<endl;
	}
	
}
