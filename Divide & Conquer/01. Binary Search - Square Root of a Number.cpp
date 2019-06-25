#include<iostream>
using namespace std;
int bs(int s, int e)
{
	int mid = e/2;
	int num = e;
	float ans = 0.0;
	while(s<=e)
	{
		mid = s + (e-s)/2;
		if(mid*mid==num)
			return mid;
		else if(mid*mid>num){
			ans = mid;
			e = mid-1;
		}
		else if(mid*mid<num){
			ans = mid;
			s = mid+1;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int srt = bs(0,n);
	cout<<srt<<endl;
}