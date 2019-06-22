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
int CountNodes(Node* root)
{
	if(root==NULL){
		return 0;
	}
	return 1 + CountNodes(root->left) + CountNodes(root->right);
}
int main()
{
	Node* root = BuildTree();
	cout<<CountNodes(root);
}