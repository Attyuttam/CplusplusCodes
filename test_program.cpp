#include<bits/stdc++.h>
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
void findMinimumTranslations(string start,string finish,vector<string> forbid){
	queue<string> q;
	q.push(start);
	int count=0;
	int len=0;
	int sp=INT_MAX;
	while(!q.empty()){
		string cur_string = q.front();
		q.pop();
		len++;
		if(cur_string==finish){
			if(len<sp){
				sp=len;
			}	
			len--;
			continue;
		}
		string temp_string = cur_string;
		//the first character
		for(int i=0;i<2;i++){
			if(i==0){
				int p = temp_string[0]-97;
				p-=1;
				if(p==-1)p=25;
				cur_string[0]=(char)(p+97);
			}
			else if(i==1){
				int p = temp_string[0]-97;
				p+=1;
				if(p==26)p=0;
				cur_string[0]=(char)(p+97);
			}
			//the second character
			for(int j=0;j<2;j++){
				if(j==0){
					int p = temp_string[1]-97;
					p-=1;
					if(p==-1)p=25;
					cur_string[1]=(char)(p+97);
				}
				else if(j==1){
					int p = temp_string[1]-97;
					p+=1;
					if(p==26)p=0;
					cur_string[1]=(char)(p+97);
				}
				//the third character
				for(int k=0;k<2;k++){
					if(k==0){
						int p = temp_string[2]-97;
						p-=1;
						if(p==-1)p=25;
						cur_string[2]=(char)(p+97);
					}
					else if(k==1){
						int p = temp_string[2]-97;
						p+=1;
						if(p==26)p=0;
						cur_string[2]=(char)(p+97);
					}	
					//the fourth character
					for(int l=0;l<2;l++){
						if(l==0){
							int p = temp_string[3]-97;
							p-=1;
							if(p==-1)p=25;
							cur_string[3]=(char)(p+97);
						}
						else if(l==1){
							int p = temp_string[3]-97;
							p+=1;
							if(p==26)p=0;
							cur_string[3]=(char)(p+97);
						}
						if(notForbidden(cur_string,forbid))
							q.push(cur_string);	
					}
				}
			}	
		}
		//all the strings which can be obtained from the current string have now been pushed into the queue
		
	}
	cout<<sp<<endl;
}
int main(){
	string start,finish;
	vector<string>forbid;
	cout<<"Enter the start string";
	cin>>start;
	cout<<"\nEnter the finish string";
	cin>>finish;
	
	char opt;
	
	while(1){
		cout<<"\nDo you want to enter forbidden words? (Y/N): ";
		cin>>opt;
		if(opt=='Y'){
			int fs=0;
			cout<<"Enter the number of forbidden strings: ";
			cin>>fs;
			cout<<"Enter the forbidden strings: ";
			for(int i=0;i<fs;i++){
				string s;
				cin>>s;
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
