#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int CountWays(int n, int *arr, int k, vector<vector<int> > dp)
{
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	// When denomination array is empty
	if(k==0){
		return 0;
	}
	// Check if computed, 
	if(dp[n][k]>=0){ //=? It can be zero, that is, I can't find the change for the value, so it'll be 0.
		return dp[n][k];
	}
	// Find the denomiation for n-arr[0] 
	// i.e ,we've given n coins now we need to find out the way to give n-arr[0] coins.
	int option1 = CountWays(n-arr[0],arr,k,dp);
	// If we can't use denomination for arr[0], we will look up for next denomination in the array, and reduce the size of denomination array by 1.
	int option2 = CountWays(n,arr+1,k-1,dp);
	return dp[n][k] = option1 + option2;
}
int CountWaysDP(int n,int *arr, int k)
{
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(i==0){
				dp[i][j] = 1;
			}
			else if(i>0 && j<=0){
				dp[i][j] = 0;
			}
			else{
				if(i>=arr[j-1]){
					dp[i][j] = (dp[i-arr[j-1]][j] + dp[i][j-1])%mod;
				}
				else{
					dp[i][j] = (dp[i][j-1])%mod;
				}
			}
		}
	}
	return dp[n][k];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>k;
		int *arr = new int[k];
		for(int i=0;i<k;i++){
			cin>>arr[i];
		}
		cin>>n;
		cout<<CountWaysDP(n,arr,k)%mod<<endl;
		delete []arr;
	}
}