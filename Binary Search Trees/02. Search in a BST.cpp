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
bool SearchInBST(Node* root, int target)
{
	if(root==NULL){
		return false; // Can't find in the target in the tree.
	}
	if(root->data==target){
		return true; // found the target.
	}
	else if(target< root->data){
		return SearchInBST(root->left,target);
	}
	return SearchInBST(root->right,target);
}
Node* BuildTree(Node* root, int data)
{
	if(root==NULL){
		return new Node(data);
	}
	if(data < root->data){
		root->left = BuildTree(root->left,data);
	}
	else{
		root->right = BuildTree(root->right,data);
	}
	return root;
}
Node* TakeInput()
{
	int data;
	cin>>data;
	Node* root = NULL;
	while(data!=-1){
		root = BuildTree(root,data);
		cin>>data;
	}
	return root;
}
int main()
{
	Node* root = TakeInput();
	int value; 
	cin>>value;
	(SearchInBST(root,value))?(cout<<"The value is found in BST\n"):(cout<<"Can't find the value in BST\n");
}