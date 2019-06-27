// Given an array build a height balanced tree.
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
Node* ArrayToBalancedBST(int *arr, int s, int e)
{
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	Node* root = new Node(arr[mid]);
	root->left = ArrayToBalancedBST(arr,s,mid-1);
	root->right = ArrayToBalancedBST(arr,mid+1,e);
	return root;
}
int main()
{
	int arr[]={5, 3, 2, 4, 7, 6, 8};
	// The Array Must be in Sorted Order in order to build Height Balanced Binary Search Tree,
	// As It will the Inorder traversal and the middle element of the array will be the root node of BST,
	// and left elements from mid will be the part of left subtree and right elements after the mid
	// will be part of right subtree.
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);
	Node* root = ArrayToBalancedBST(arr,0,n-1);
	PrintTree(root);
}