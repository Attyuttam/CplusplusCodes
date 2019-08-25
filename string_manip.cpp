#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s3;
	string final_string="";
	cin>>s1;
	cin>>s2;
	cin>>s3;
	for(int i=0;i<s1.length();i++){
		if(s1[i]=='u'||s1[i]=='o'||s1[i]=='i'||s1[i]=='e'||s1[i]=='a'||s1[i]=='U'||s1[i]=='O'||s1[i]=='I'||s1[i]=='E'||s1[i]=='A'){
			s1[i]='$';
		}
	}
	
	for(int i=0;i<s2.length();i++){
		if(!(s2[i]=='u'||s2[i]=='o'||s2[i]=='i'||s2[i]=='e'||s2[i]=='a'||s2[i]=='U'||s2[i]=='O'||s2[i]=='I'||s2[i]=='E'||s2[i]=='A')){
			s2[i]='#';
		}
	}
	
	for(int i=0;i<s3.length();i++){
		if(s3[i]>='a' && s3[i]<='z'){
			s3[i]=(char)(s3[i]-97+65);
		}
	}
	final_string=s1+s2+s3;
	cout<<final_string<<endl;
}
