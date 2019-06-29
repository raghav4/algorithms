#include<iostream>
#include<queue>
using namespace std;
void PrintHeap(priority_queue<int,vector<int>, greater<int> >h){
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	cout<<endl;
	return;
}
int main()
{
	priority_queue<int,vector<int>, greater<int> >h; // Min Heap
	int n,k;
	k = 3;
	int cnt = 0;
	while(scanf("%d",&n)!=EOF){
		if(n==-1){// Query, Print heap
			PrintHeap(h); // If input is -1, then print K largest number in the stream.
		}
		else{
			 if(cnt<k){ // If the count of the heap or the elements in the heap is less then K, then keep pushing the elements into the heap.
				h.push(n); // Push the input in the heap as cnt<k.
				cnt++; // Increment the counter.
			}
			else{
				// Case when the size of the heap >= K. 
				if(n>h.top()){ // Only push the element into the heap if it is greater then the largest element in the heap.
					h.pop(); // If we've inserted an element we need to remove the smallest number from the heap. 
					h.push(n); // Insert that element (n) into the heap.
				}
			}
		}
	}
}

// Input : 1 2 5 3 -1 6 8 0 -1 4 18 -1

// Largest K Elements in a Running Stream.
// In Running Stream, you can't store the numbers and you don't know how many numbers are there.
// At any point you've to find out K largest elements in it.
// In this problem we will be using the Min-heap.
// Why Min Heap? because if we get number which is greater then previously inserted it'd be easier from us to remove the smallest from previous, for eg:
// if we had 1,2,3 and now we get 5, so we will remove 1 and will have new heap as 2,3,5.
// scanf internally represents how many number it has taken as an input 