#include<iostream>
using namespace std;
void p(int n, string prefix = "")
{
	// Base Case
	if(n==0){
		cout<<prefix<<endl;
		return;
	}
	// Recursive Case
	else{
		p(n-1, prefix + "0");
		p(n-1, prefix + "1");
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	p(n);
}

// Time : 2^n
// Space : 2^n

// Think Process : Once we'll append 0 with our output and once we'll append 1 with our output, rest will be handled by recursion.
// Why are we appending 0 and 1?
// If we closely look at the output for eg-1, it is
// 0
// 1
// for eg-2, it is 
// 00
// 01
// 10
// 11
// and so on. Now, we can clearly see that we've appended 0 once with the output of 1, then we've appended 1 once with the output of 1, 
// This series goes on and this is how our recursion worked out.