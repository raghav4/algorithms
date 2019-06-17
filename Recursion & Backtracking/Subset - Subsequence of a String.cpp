// Subset or subsequence of a string using recursion.
#include<iostream>
using namespace std;
void generateSubsequences(char *inp, char *op, int i, int j)
{
	// Base Case. 
	// If our input is null, then our substring will also be null.
	if(inp[i]=='\0'){
		op[j]='\0';
		cout<<op<<", ";
		return;
	}
	// Recursive Case
	// 1. Will Include the ith letter once.
	op[j] = inp[i]; // Included the ith letter.
	// Calling Recursion to do the subtask.
	generateSubsequences(inp,op,i+1,j+1);
	// 2. Will not Include the ith letter.
	generateSubsequences(inp,op,i+1,j);
	// Here the value exists at op[j] but will be overwritten after further calls.
}
int main()
{
	char inp[10001];
	cin>>inp;
	char op[10001];
	generateSubsequences(inp,op,0,0);
}
// Every Character here has two options, either to include itself or not.
// The number of subsets of string having length 'n' is 2^n.