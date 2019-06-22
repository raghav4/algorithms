#include<iostream>
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
int ReplaceBySum(Node* root)
{
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int root_data = root->data;
	root->data = ReplaceBySum(root->left) + ReplaceBySum(root->right);
	return root->data + root_data;
}
int main()
{
	Node* root = BuildTree();
	cout<<endl;
	PrintTree(root);
	int d = ReplaceBySum(root);
	cout<<endl;
	PrintTree(root);
}

// Post Order Traversal.
// TC : O(N)