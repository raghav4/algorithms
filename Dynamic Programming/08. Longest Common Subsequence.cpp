#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
// int LongestCommonSubsequence(string a, string b)
// {
// 	int al = a.length();
// 	int bl = b.length();
// 	int n = max(al,bl);
// 	int dp[n][n];
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<n;j++){
// 			if(a[i]==b[j])
// 			{
// 				dp[i][j] = 1 + max(dp[i-1][j],dp[i][j-1]);
// 			}

// 		}
// 	}
// }
int lcs(string a, string b, int al, int bl)
{
	if(al==0 || bl==0){
		return 0;
	}
	if(a[al-1]==b[bl-1]){
		return 1;
	}
	return max(lcs(a,b,al-1,bl),lcs(a,b,al,bl-1)) + 1;
}
int main()
{
	string a,b;
	cin>>a>>b;
	int al = a.length();
	int bl = b.length();
	cout<<lcs(a,b,al,bl);
}