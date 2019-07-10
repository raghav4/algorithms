#include<iostream>
using namespace std;
int mixtures(int *a, int i, int j, int dp[][10])
{
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	// Recursive Case
	int ans = INT_MAX;
	for(int k=i+1;k<=j;k++){
		int c_ans = mixtures(a,i,k,dp) + mixtures(a,k+1,j,dp) + csum(a,i,k,dp);
		ans = min(ans,c_ans);
	}
	return dp[i][j] = ans;
}
int main()
{
	int dp[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			dp[i][j] = -1;
		}
	}
	int mix[] = {40,60,20};
	int n = 3;
	cout<<mixtures(mix,0,n-1,dp)<<endl;
	// for(int i=0;i<10;i++){
	// 	for(int j=0;j<10;j++){
	// 		cout<<dp[i]
	// 	}
	// }
}

// O(N^4), csum has to be improved.