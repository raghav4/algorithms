#include<iostream>
using namespace std;
void heapify(int *arr, int i, int n)
{
	int left = i<<1;
	int right = left + 1;
	int maxIndex = i;
	if(left<n && arr[i]<arr[left]){
		maxIndex = left;
	}
	if(right<n && arr[maxIndex]<arr[right]){
		maxIndex = right;
	}
	if(i!=maxIndex){
		swap(arr[i],arr[maxIndex]);
		heapify(arr,maxIndex,n);
	}
}
int main()
{
	int arr[] = {-1,5,4,1,2,3,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=n/2;i>=1;i--){ // Bottom up , Time Complexity : O(LogN), for N elements it is O(NLogN)
		heapify(arr,i,n);
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

}
// for sorting , start popping the elements in order to get the 