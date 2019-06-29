#include<iostream>
#include<queue>
#define pii pair<int,pair<int,int>>
#define mp make_pair
using namespace std;
vector<int> MergeKSortedArrays(vector<vector<int>> v)
{
	vector<int> output;
	int sz = v.size(); // sz = k.
	priority_queue<pii,vector<pii>,greater<pii> >pq; // But why greater is sorting on behalf of first element not the indices? check it
	for(int i=0;i<sz;i++){
		pq.push(mp(v[i][0],mp(i,0)));
	}
	while(!pq.empty()){
		pii current = pq.top();
		pq.pop();
		int i = current.second.first;
		int j = current.second.second;
		output.push_back(current.first);
		if((j+1)<v[i].size()){
			pq.push(mp(v[i][j+1],mp(i,j+1)));
		}
	}
	return output;
}
int main()
{
	int k,n;
	cin>>k>>n;
	vector<vector<int> >v(k);
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	vector<int>op = MergeKSortedArrays(v);
	for(auto x: op){
		cout<<x<<" ";
	}
}	

// Time complexity : NK(LogK)
// As, we are traversing our 2D array for N*K times, and inserting every element in the priority queue whose time complexity will also be equal to O(logNK),
// So, our time complexity of this algorithm will be O(NK).

// Sample Input: 
// 3 4
// 1 3 5 7
// 2 4 6 8
// 0 9 10 11