/*
	Here i have implemented a hill climbing algorithm to convert a sequence of letters to a given sequence of letters
	ex:
		A B C D is the correct sequence 
		D C B A is the given sequence and i need to convert it into the given sequence
		
	The heuristic function that i am going to use is:
		+1 if the character is at its correct position, i.e it has the exact same elements on its left and right as in the correct sequence
		-1 else
*/

#include<bits/stdc++.h>
using namespace std;
int find(char t,string cs){
	for(int i=0;i<cs.length();i++){
		if(cs[i]==t)return i;
	}
	return -1;
}
int calcCost(string s,string cs){
	int val=0;
	for(int i=0;i<s.length();i++){
		if(i==0){
			int ind_0 = find(s[i],cs);
			if(ind_0==-1) return INT_MAX;
			if(ind_0==0){
				if(s[i+1] == cs[ind_0+1])val++;
			}
			else{
				val--;
			}
		}		
		else if(i==s.length()-1){
			int ind_last = find(s[i],cs);
			if(ind_last==-1) return INT_MAX;
			if(ind_last==cs.length()-1){
				if(s[i-1] == cs[ind_last-1])val++;
			}
			else{
				val--;
			}
		}
		else{
			int ind = find(s[i],cs);
			if(ind==-1) return INT_MAX;
			if(ind!=0 && ind!=cs.length()-1){
				if(s[i-1] == cs[ind-1] && s[i+1]==cs[ind+1])val++;
				else val--;
			}
			else{
				val--;
			}
		}
	}
	return val;
}
string swapElement(string s,int i,int j){
	char temp = s[j];
	s[j]=s[i];
	s[i]= temp;
	return s;
}
void convert(string s,string cs){
	int bC = calcCost(cs,cs);
	int nC = calcCost(s,cs),swap=0;
	
	if(bC==INT_MAX || nC==INT_MAX){cout<<"\nThe string cannot be converted!\n";return;}
	
	while(bC!=nC){
		for(int i=0;i<s.length()-1;i++){
			s = swapElement(s,i,i+1);
			int nC_temp = calcCost(s,cs);
			//<<nC_temp<<endl;
			if(nC_temp>=nC){
				nC= nC_temp;
				swap++;
				cout<<"After swap "<<swap<<endl;
				cout<<s<<endl;
			}
			else{
				s = swapElement(s,i,i+1);	
			}
		}
	}
	cout<<"Final Result: ";
	cout<<s<<endl;
	
}
int main(){
	string cs,s;
	cout<<"Enter the correct sequence: ";
	cin>>cs;
	cout<<"Enter the sequence to be converted: ";
	cin>>s;
	if(s.length()!=cs.length()){
		cout<<"\nThe string cannot be converted!\n";return 0;
	}
	convert(s,cs);
}
