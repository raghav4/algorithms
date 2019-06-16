#include<bits/stdc++.h>
using namespace std;
void printBrackets(int n,char *output, int j)
{
	if(n==0){
		output[j] = ')';
		output[j+1] = '\0';
		return;
	}
	output[j] = '(';
	printBrackets(n-1,output,j+1);
	output[j]=')';
}
int main()
{
	int n;
	cin>>n;
	char output[1001];
	printBrackets(n,output,0);
}