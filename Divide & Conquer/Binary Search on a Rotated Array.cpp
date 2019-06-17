#include<iostream>
using namespace std;
int bSearch(int *arr, int n, int key)
{
	int s = 0;
	int e = n-1;

	while(s<=e)
	{
		int mid = s + (e-s)/2;
		if(arr[mid]==key){
			return mid;
		}
		if(arr[s]<=key) // First half of the array.
	    {
	        if(key>=arr[s] && key<=arr[mid]){
	            e = mid-1;
	        }
	        else{
	            s = mid+1;
	        }
	    }
	    else if(key>=arr[mid] && key<=arr[e]){ //second half.
	        s = mid+1;
	    }
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	int index = bSearch(arr,n,key);
	if(index!=-1){
		cout<<"Element Found at Position : "<<index;
	}
	else{
		cout<<"Sorry! Can't found Element\n";
	}
}