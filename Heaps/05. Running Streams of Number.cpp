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
	cin>>n;
	k = 3;
	int cnt = 0;
	while(scanf("%d",&n)!=EOF){
		if(n==-1){
			// Query, Print heap
		PrintHeap(h);

		}
		else{
			 if(cnt<k){
				h.push(n);
				cnt++;
			}
			else{
				if(n>h.top()){
					h.pop();
					h.push(n);
				}
			}
		}
	}
}

// Input : 1 2 5 3 -1 6 8 0 -1 4 18 -1

// scanf internally represents how many number it has taken as an input 