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
Node* BuildBST(Node* root, int data)
{
	// int data;
	// cin>>data;
	if(root==NULL){
		Node* nn = new Node(data);
		return nn;
	}
	if(data<root->data){
		root->left = BuildBST(root->left, data);
	}
	else{
		root->right = BuildBST(root->right, data);
	}
	return root;
}
Node* TakeInput(){
	int data;
	cin>>data;
	Node* root = NULL;
	while(data!=-1){
		root = BuildBST(root,data);
		cin>>data;
	}
	return root;
}
void PrintBST(Node* root)
{
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	PrintBST(root->left);
	PrintBST(root->left);
}
int main()
{
	Node* root = TakeInput();
	PrintBST(root);
}