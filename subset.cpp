#include<bits/stdc++.h>
using namespace std;
void possibleSubsets(char A[100], int N)
{
    for(int i = 0;i < (1 << N); ++i)
    {
        for(int j = 0;j < N;++j)
            if(i & (1 << j))
                cout << A[j] <<" ";
        cout << endl;
	}
}

int main(){
	char A[100];
	possibleSubsets(A,3);	
}
