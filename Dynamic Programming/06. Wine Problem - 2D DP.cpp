#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int MaxProfit(int *arr, int i, int n, int year)
{
	if(i>n){
		return 0;
	}
	if(dp[i][n]!=-1){
		return dp[i][n];
	}
	int option1 = arr[i]*year + MaxProfit(arr,i+1,n,year+1);
	int option2 = arr[n]*year + MaxProfit(arr,i,n-1,year+1);
	return dp[i][n] = max(option1,option2);
}
int main()
{
	int arr[10001];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	int ans = MaxProfit(arr,0,n-1,1);
	cout<<ans<<endl;
}
