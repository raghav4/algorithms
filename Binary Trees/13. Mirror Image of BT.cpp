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
// void MirrorBT(Node* root)
// {
// 	if(root==NULL){
// 		return;
// 	}
// 	if(root->left && root->right){
// 		swap(root->left,root->right);
// 	}
// 	if(root->left && !root->right){
// 		root->right = root->left;
// 		root->left = NULL;
// 	}
// 	if(!root->left && root->right){
// 		root->left = root->right;
// 		root->right = NULL;
// 	}
// 	MirrorBT(root->left);
// 	MirrorBT(root->right);
// 	return;
// }
void MirrorBT(Node* root)
{
	if(root==NULL){
		return;
	}
	swap(root->left,root-right);
	MirrorBT(root->left);
	MirrorBT(root->right);
	return;
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
int main()
{
	Node* root = BuildTree();
	PrintTree(root);
	cout<<endl;
	MirrorBT(root);
	PrintTree(root);
}