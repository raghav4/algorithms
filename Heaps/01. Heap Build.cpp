#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
class Heap
{
	vector<int> v;
	// Flag for deciding the type of the heap.
	bool HeapType;
	// Custom Comparator to Update the Inserted Element
	bool compare(int a, int b){
		if(!HeapType)
			return a<b; // Max Heap
		else
			return a>b; // Min Heap
	}
	void heapify(int index){
		int leftChild = 2*index;
		int rightChild = 2*index + 1;
		int lastElement = v.size()-1;
		int maxIndex =  index;
		if(leftChild<=lastElement && compare(v[index],v[leftChild])){
			maxIndex = leftChild;
		}
		if(rightChild<=lastElement && compare(v[maxIndex],v[rightChild])){
			maxIndex = rightChild;
		}
		if(maxIndex!=index){
			swap(v[index],v[maxIndex]);
			heapify(maxIndex);
		}
	}
	public:
	Heap(int size=10, bool ht=true)
	{
		v.reserve(size);
		v.pb(-1); // Blocking the 0th Index.
		HeapType = ht;
	}
	// Insertion in Heap, Time complexity : O(LogN)
	void push(int data)
	{
		v.pb(data);
		int index = v.size()-1;
		int parentIndex = index/2;
		while(index>1 && compare(v[parentIndex],v[index]))
		{
			swap(v[parentIndex],v[index]);
			index = parentIndex;
			parentIndex/=2;
		}
	}
	// Get Max/Min in Heap , Time complexity: O(1)
	int top(){
		return v[1];
	}
	void pop()
	{
		// Swap first and last node. 
		int last = v.size()-1;
		swap(v[1],v[last]);
		v.pop_back(); // Remove the last node.
		// Heapify,
		heapify(1);
	}
	bool empty(){
		if(v.size()==1){
			return true;
		}
		return false;
	}
};
int main()
{
	int data;
	cin>>data;
	Heap h;
	while(data!=-1){
		h.push(data);
		cin>>data;
	}
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
}

// dynamic array? while constructing tree but howcome will the size of the array can grow unlike in vectors.
// Dynamic Object.
// Heap Sort
// class is taking O(NLogN) to build up the tree, whereas it can be reduced to O(N).