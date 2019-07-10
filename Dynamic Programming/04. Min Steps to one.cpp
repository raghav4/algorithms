#include<iostream>
#include<climits>
using namespace std;
int minStepsDp(int *arr, int n)
{
	if(n==1){
		return 0;
	}
	if(arr[n]>0){
		return arr[n];
	}
	int ans = minStepsDp(arr,n-1) + 1;
	if(n%2==0){
		ans = min(ans, minStepsDp(arr,n/2) + 1);
	}
	if(n%3==0){
		ans = min(ans, minStepsDp(arr,n/3) + 1);
	}
	arr[n] = ans;
	return ans;
}
int MinStepsto1_Recursive(int n)
{
	if(n==1){
		return 0;
	}
	int op1,op2,op3,ans;
	op1 = MinStepsto1_Recursive(n-1);
	if(n%2==0){
		op2 = MinStepsto1_Recursive(n/2);
	}
	if(n%3==0){
		op3 = MinStepsto1_Recursive(n/3);
	}
	ans = min(op1,min(op2,op3)) + 1; 
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int* arr = new int[n+1];
	cout<<MinStepsto1_Recursive(n)<<endl;
//	cout<<minStepsDp(arr,n);
	delete []arr;
}