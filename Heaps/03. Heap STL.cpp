#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int>h; // Max Heap
	int arr[] = {1,3,2,5,0,8,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		h.push(arr[i]);
	}

	// Popping while not empty
	while(!h.empty()){
		std::cout<<h.top()<<" ";
		h.pop();
	}
	return 0;
}