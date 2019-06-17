#include<iostream>
using namespace std;
int power(int a, int n)
{
	if(n==0){
		return 1;
	}
	int ans = power(a,n/2);
	if(n&1){
		return a*ans*ans;
	}
	else{
		return ans*ans;
	}
}
int powerBitMasking(int a, int n)
{
	// Time: O(logN), Space: O(1)
	int ans = 1;
	while(n){
		if(n&1){
			ans*=a;
		}
		a*=a; // 1<<a
		n>>=1;
	}
	return ans;
}
int main()
{	
	int a,n;
	cin>>a>>n;
	cout<<power(a,n);
}

// Time : O(logN)
// Space : O(logN)