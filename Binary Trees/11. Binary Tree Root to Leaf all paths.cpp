#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
Node* BuildTree()
{
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	Node* root = new Node(data);
	root->left = BuildTree();
	root->right = BuildTree();
	return root;
}
void PrintTree(Node* root)
{
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	PrintTree(root->left);
	PrintTree(root->right);
}
void PrintAllPaths(Node* root, vector<int> v)
{
	if(root==NULL){
		return;
	}
	if(root->left==NULL && root->right==NULL){
		v.push_back(root->data);
		for(auto x: v){
			cout<<x<<"->";
		}
		cout<<endl;
		v.pop_back(); //
		return;
	}
	v.pb(root->data);
	PrintAllPaths(root->left,v);
	PrintAllPaths(root->right,v);
	// In case of by value , the copy is created again.
	// If we pass the vector by reference then we have to do v.pop_back() again.
	return;
}

int main()
{
	Node* root = BuildTree();
	vector<int>v;
	PrintAllPaths(root,v);
	//PrintTree(root);
}

// Input : 1 2 4 -1 -1 -1 3 5 8 -1 -1 -1 6 -1 -1
// 
// 
// 
// 
// 
// Know, how the recursion is popping the element