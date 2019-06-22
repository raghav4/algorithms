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
int main()
{
	Node* root = BuildTree();
	PrintKthLevel(root,2);
}