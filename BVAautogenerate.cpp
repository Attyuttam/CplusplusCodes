#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int makeTestCasesBVA[100][5];
int makeTestCasesECP[100][3];
char varList[100];
int varIndex = 0;
int globalIndexBVA = 0 ;
int globalIndexECP = 0 ;
int makeNum(int pos,string line){
	int num=0;
	int k=pos;
	while(!(line[k]>='0' && line[k]<='9'))k++;
	for(int i=k;line[i]>='0' && line[i]<='9';i++){
		num = num*10+(line[i]-'0');
	}
	//cout<<"num: "<<num<<endl;
	return num;
}
void printBoundaryValues(char var,int lb,int ub){
	cout<<"Boundary value analysis: "<<endl;
	cout<<"Variable located: "<<var<<endl;
	varList[varIndex++]=var;
	makeTestCasesBVA[globalIndexBVA][0]=lb-1;
	makeTestCasesBVA[globalIndexBVA][1]=lb;
	makeTestCasesBVA[globalIndexBVA][2]=(lb+ub)/2;
	makeTestCasesBVA[globalIndexBVA][3]=ub;
	makeTestCasesBVA[globalIndexBVA++][4]=ub+1;
	
	cout<<"lb-1 : "<<lb-1<<endl<<"lb : "<<lb<<endl<<"ub : "<<ub<<"\nub+1 : "<<ub+1<<endl<<endl;
}
void printEquivalencePartitionValues(int lb,int ub){
	cout<<"Equivalence class partition: "<<endl;
	if(lb<0 && ub>0){
		cout<<"CLASS 1: "<<endl;
		cout<<"lb-1 : "<<lb-1<<endl;
		cout<<"lb : "<<lb<<endl;
		cout<<"lb+1 : "<<lb+1<<endl;
		cout<<"ub : -1"<<endl;
		
		cout<<"CLASS 2: "<<endl;
		cout<<"value: 0 "<<endl;
		 
		cout<<"CLASS 3: "<<endl;
		
		cout<<"lb : 1"<<endl;
		cout<<"ub-1 : "<<ub-1<<endl;
		cout<<"ub : "<<ub<<endl;
		cout<<"ub+1 :"<<ub+1<<endl;
		
		makeTestCasesECP[globalIndexECP][0]=lb;
		makeTestCasesECP[globalIndexECP][1]=0;
		makeTestCasesECP[globalIndexECP++][2]=ub;
	}
	else{
		cout<<"CLASS 1: "<<endl;
		cout<<"lb-1 : "<<lb-1<<endl;
		cout<<"lb : "<<lb<<endl;
		cout<<"lb+1 : "<<lb+1<<endl;
		cout<<"ub-1 : "<<((lb+ub)/2)-2<<endl;
		cout<<"ub : "<<((lb+ub)/2)-1<<endl;
		
		cout<<"CLASS 2: "<<endl;
		cout<<"lb : "<<((lb+ub)/2)<<endl;
		cout<<"lb+1 : "<<((lb+ub)/2)+1<<endl;
		cout<<"ub-1 : "<<ub-1<<endl;
		cout<<"ub: "<<ub<<endl;
		cout<<"ub+1 : "<<ub+1<<endl;
		
		makeTestCasesECP[globalIndexECP][0]=lb;
		makeTestCasesECP[globalIndexECP][1]=-1;
		makeTestCasesECP[globalIndexECP++][2]=ub;

	}
	cout<<endl;
}
void makeTestCasesBVA_f(){
	for(int i =0 ;i <globalIndexBVA;i++){
		for(int k=0;k<5;k++){
			cout<<"var "<<varList[i]<<" = "<<makeTestCasesBVA[i][k]<<" ";
			for(int j =0 ;j<globalIndexBVA;j++){
				if(j==i)continue;
				cout<<"var "<<varList[j]<<" = "<<makeTestCasesBVA[j][2]<<" ";
			}
			cout<<endl;
		}
	}
}
void makeTestCasesECP_f(){
	for(int i =0 ;i <globalIndexECP;i++){
		for(int k=0;k<3;k++){
			if(makeTestCasesECP[i][k]!=-1){
				cout<<"var "<<varList[i]<<" = "<<makeTestCasesBVA[i][k]<<" ";
				for(int j =0 ;j<globalIndexECP;j++){
					if(j==i)continue;
					cout<<"var "<<varList[j]<<" = "<<makeTestCasesECP[j][2]<<" ";
				}
				cout<<endl;	
			}
		}
	}	
}
void makeTestCases(){
	cout<<"BOUNDARY VALUE TEST CASES:\n";
	makeTestCasesBVA_f();
	cout<<endl<<endl;
    cout<<"EQUIVALENCE CLASS PARTITION TEST CASES:\n";
	makeTestCasesECP_f();
}
int main(){
	ifstream input_file;
	input_file.open("test_program.cpp");
	string line="";
	while(getline(input_file,line)){
		line+=" ";
		//analyse the code
		//if and else if check
		//cout<<line<<endl;
		for(int i=0;i<line.length()-2;i++){
			if(line[i]=='i' && line[i+1]=='f'){
				int pos=-1;
				int lb=-1;
				int ub=-1;
				int flag1=0;
				int flag2=0;
				char var=line[i+3];
				for(int p=i+4;flag1==0 || flag2 == 0;p++){
					if(line[p]=='<' && flag1 == 0){
						 ub=makeNum(p,line);
						 if(line[p+1]!='=')ub-=1;
						flag1=1;
					}
					else if(line[p]=='>' && flag2==0){
						 lb=makeNum(p,line);
						 if(line[p+1]!='=')lb+=1;	
						flag2=1;
					}
				}
				
				printBoundaryValues(var,lb,ub);
				printEquivalencePartitionValues(lb,ub);
				break;	
			}	
			else if(line[i]=='f' && line[i+1]=='o' && line[i+2]=='r'){
				//cout<<"caught";	
				int pos=i+3;
				int lb,ub;
				while(line[pos]!=' '){
					pos++;
				}
				pos++;
				char var;
				var = line[pos];
				while(line[pos]!='='){
					pos++;
				}
			
				lb=makeNum(pos,line);
			
				while(line[pos]!='<' && line[pos]!='>')pos++;
				if(line[pos]=='<'){
					ub=makeNum(pos,line);
					if(line[pos+1]!='=')ub-=1;
				}
				
				else if(line[pos] == '>'){
					ub=lb;
					lb=makeNum(pos,line);
					if(line[pos+1]!='=')lb+=1;
				}
				printBoundaryValues(var,lb,ub);
				printEquivalencePartitionValues(lb,ub);
				break;
			}
			else if(line[i]=='w' &&line[i+1]=='h' &&line[i+2]=='i' &&line[i+3]=='l' &&line[i+4]=='e' ){
				int pos=-1;
				int lb=-1;
				int ub=-1;
				int flag1=0;
				int flag2=0;
				char var=line[i+6];
				for(int p=i+5;flag1==0 || flag2 == 0;p++){
					if(line[p]=='<' && flag1 == 0){
						 ub=makeNum(p,line);
						 if(line[p+1]!='=')ub-=1;
						flag1=1;
					}
					else if(line[p]=='>' && flag2==0){
						 lb=makeNum(p,line);
						 if(line[p+1]!='=')lb+=1;	
						flag2=1;
					}
				}
				printBoundaryValues(var,lb,ub);
				printEquivalencePartitionValues(lb,ub);
				break;
			}
		}
	
	}
	input_file.close();
	makeTestCases();
}
