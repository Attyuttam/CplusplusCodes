#include<bits/stdc++.h>
#include<string>

using namespace std;
int notForbidden(string cur_string, vector<string> forbid){
	for(int i=0;i<forbid.size();i++){
		//ith forbidden string
		string str = forbid[i];
		
		istringstream ss(str); 
   		int c=0;
   		int f=0;
   		int count=0;
	
		do { 
        	string word; 
        	ss >> word; 	
        	if(c==0){
        		f=0;
				for(int k=0;k<word.length();k++){
        			if(cur_string[0]==word[k]){
						count++;
						break;
					}
				}
				
				c++;
			}
			else if(c==1){
				f=0;
				for(int k=0;k<word.length();k++){
        			if(cur_string[1]==word[k]){
						count++;
						break;
					}
				}
			
				c++;
			}
			else if(c==2){
				f=0;
				for(int k=0;k<word.length();k++){
        			if(cur_string[2]==word[k]){
						count++;
						break;
					}
				}
				
				c++;
			}
			else if(c==3){
				f=0;
				for(int k=0;k<word.length();k++){
        			if(cur_string[3]==word[k]){
						count++;
						break;
					}
				}
			}
    	} while (ss);
    	if(count==4)return 0;
	}
	return 1;
}
int Visited(string cur_string,vector<string> visited){
	if(find(visited.begin(),visited.end(),cur_string)!=visited.end())return 1;
	return 0;
}
int notMoreThanOneDiff(string cur_string,string finish){
	for(int i=0;i<4;i++){
		if(abs(cur_string[i]-finish[i])>1)return 0;
	}
	return 1;
}
void findMinimumTranslations(string start,string finish,vector<string> forbid){
	queue<string> q;
	q.push(start);
	q.push("****");
	int count=0;
	int len=0;
	int sp=INT_MAX;
	cout<<endl;
	
	vector<string> visited;
	visited.push_back(start);
	while(!q.empty()){
		string cur_string = q.front();
		//cout<<cur_string<<" ";
		q.pop();
		if(cur_string=="****"){
			q.push("****");
			len++;
			//cout<<len<<endl;
			continue;
		}
		if(cur_string==finish){
			sp=len;
			cout<<endl<<sp<<endl;
			return;
		}
		string temp_string = cur_string;
		
		for(int i=0;i<4;i++){
			int p = temp_string[i]-97;
			p-=1;	
			if(p==-1)p=25;
			cur_string[i]=(char)(p+97);
			
			if(cur_string==finish && !notForbidden(cur_string,forbid)){
				cout<<endl<<"-1"<<endl;
				return;
			}
			if( !Visited(cur_string,visited) && notForbidden(cur_string,forbid)){
				q.push(cur_string);	
				visited.push_back(cur_string);
			}
			
			p = temp_string[i]-97;
			p+=1;
			if(p==26)p=0;
			cur_string[i]=(char)(p+97);	
			
			if(cur_string==finish && !notForbidden(cur_string,forbid)){
				cout<<endl<<"-1"<<endl;
				return;
			}
			if( !Visited(cur_string,visited) && notForbidden(cur_string,forbid)){
				q.push(cur_string);	
				visited.push_back(cur_string);
			}
			cur_string = temp_string;
		}
		
		
	}
	cout<<sp<<endl;
}
int main(){
	string start,finish;
	vector<string>forbid;
	cout<<"Enter the start string: ";
	cin>>start;
	cout<<"\nEnter the finish string: ";
	cin>>finish;
	
	char opt;
	
	while(1){
		cout<<"\nDo you want to enter forbidden words? (Y/N): ";
		cin>>opt;
		if(opt=='Y'){
			int fs=0;
			cout<<"Enter the number of forbidden strings: ";
			cin>>fs;
		    cin.clear();
    		cin.sync();
			cout<<"Enter the forbidden strings: ";
			for(int i=0;i<fs;i++){
				string s;
				getline(cin,s);
				forbid.push_back(s);
				
			}
			break;
		}
		else if(opt=='N'){
			break;
		}	
	}
	findMinimumTranslations(start,finish,forbid);
}
