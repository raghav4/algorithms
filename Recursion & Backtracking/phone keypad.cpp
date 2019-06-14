#include<bits/stdc++.h>
using namespace std;
string table[] = { "", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void printKeypad(char *inp, char *op, int i, int j)
{
	if(inp[i]=='\0'){
		op[j]='\0';
		cout<<op<<endl;
		return;
	}
	int nn = inp[i] - '0';
    if(nn==0){
    	op[j] = ' ';
        printKeypad(inp,op,i+1,j+1);
    }
	for(int k=0;k<table[nn][k]!='\0';k++){
		op[j] = table[nn][k];
		printKeypad(inp,op,i+1,j+1);
	}
}
int main()
{
	char inp[100];
	cin>>inp;
	char op[1000];
	printKeypad(inp,op,0,0);
}