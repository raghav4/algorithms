#include<iostream>
#include<queue>
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
Node* BuildTree(int *arr, int s, int e)
{
	if(s>e){
		return NULL;
	}
	Node* root = new Node(arr[s]);
	root->left = BuildTree(arr,2*s+1,e);
	root->right = BuildTree(arr,s,2*s+2);
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
	return;
}
int main()
{
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node* root = BuildTree(arr,0,n-1);
	PrintTree(root);
}