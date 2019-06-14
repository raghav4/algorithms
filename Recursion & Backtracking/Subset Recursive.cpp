#include<bits/stdc++.h>
using namespace std;
void subsequences(char *inp, char *op, int i, int j)
{
	if(inp[i]=='\0'){
		op[j] = '\0';
		cout<<op<<endl;
		return;
	}
	// Including the first char.
	op[j]=inp[i];
	subsequences(inp,op,i+1,j+1);
	// Not including the first char,
	subsequences(inp,op,i+1,j);
}
int main()
{
	char inp[1001];
	cin>>inp;
	char op[1001];
	subsequences(inp,op,0,0);
}

// The string of length n-1 is handled by recursion suppose our string is ABC, so BC is the subproblem which is handled by recursion.
// Now, Recursion will give us 4 subsequences of BC, " ", "BC" ,"B", "C".
// We can see that these are nothing but a subsequences of ABC substrings, so we will include "A" once and another time, only empty char. 