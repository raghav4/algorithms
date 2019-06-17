// Recursive program to count the number of ways such that no consecutive 1's are together in a Binary String(String consisting of only 0 and 1)
#include<iostream>
using namespace std;
int countWays(int n)
{
	if(n<=1)
		return n+1;
	else
		return countWays(n-1)+countWays(n-2);

}
int main()
{
	int n;
	cin>>n;
	cout<<countWays(n);
}