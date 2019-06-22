#include<bits/stdc++.h>
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
void PrintKthLevel(Node* root, int k)
{
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}
	PrintKthLevel(root->left,k-1);
	PrintKthLevel(root->right,k-1);
}
int HeightOfBT(Node* root)
{
	if(root==NULL){
		return 0;
	}
	int left_height = HeightOfBT(root->left);
	int right_height = HeightOfBT(root->right);
	return max(left_height,right_height) + 1;
}
void PrintLevelWise(Node* root)
{
	int ht = HeightOfBT(root);
	for(int i=0;i<=ht;i++){
		PrintKthLevel(root,i);
		cout<<endl;
	}
}
int main()
{
	Node* root = BuildTree();
	PrintLevelWise(root);
}

// Input : 1 2 4 -1 -1 -1 3 5 8 -1 -1 -1 6 -1 -1
// 
// Time Complexity : O(N^2) When, Tree is a skew Tree.