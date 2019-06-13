#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr, int n)
{
	if(n<=1){
		return;
	}
	for(int i=0;i<=n-2;i++){
			if(arr[i]>arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	bubbleSort(arr,n-1);
}
int main()
{
	int arr[]={4,3,2,0,1};
	int n = sizeof(arr)/sizeof(int);
	bubbleSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}