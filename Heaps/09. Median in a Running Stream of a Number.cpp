#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pmx; // Max Heap
priority_queue<int,vector<int>,greater<int> > pmin; // Min Heap
int ans = 0;
//Helper fn. to find the median.
void median()
{
	if(pmx.size()==pmin.size()){
		ans = (pmx.top()+pmin.top())/2;
		return;
	}
	else if(pmx.size()-pmin.size()==1){
		ans = pmx.top();
		return;
	}
	else if(pmin.size()-pmx.size()==1){
		ans = pmin.top();
		return;
	}
	// Condition to handle balancing.
	else if(pmin.size()-pmx.size()==2){
		// Remove the top of min heap and add that to max heap.
		pmx.push(pmin.top());
		pmin.pop();
		// Since they're equal in size so finding median.
		ans = (pmx.top()+pmin.top())/2;
		return;
	}
	else if(pmx.size()-pmin.size()==2){
		pmin.push(pmx.top());
		pmx.pop();
		ans = (pmx.top()+pmin.top())/2;
		return;
	}
}
// Helper fn. to insert into heap
void InsertInHeap(int x)
{
	if(pmx.empty()){
		pmx.push(x);
		median();
		return;
	}
	else if(x>ans){
		pmin.push(x);
		median();
		return;
	}
	else {
		pmx.push(x);
		median();
		return;
	}
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,x;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			InsertInHeap(x);
			cout<<ans<<" ";
		}
		while(!pmx.empty()){
			pmx.pop();
		}
		while(!pmin.empty()){
			pmin.pop();
		}
		ans = 0;
		cout<<endl;
	}
}

// Input : 
// 1
// 6
// 5 15 1 3 2 8