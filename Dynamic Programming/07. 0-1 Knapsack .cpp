#include<iostream>
using namespace std;
int KnapSackBottomUp(int *w, int *prices, int n, int c)
{
	int dp[100][100]={0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=c;j++){
			if(i==0 or w==0){
				dp[i][j] = 0;
			}
		}
	}
}
int main()
{

}