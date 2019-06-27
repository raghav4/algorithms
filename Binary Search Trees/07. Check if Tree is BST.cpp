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
class C
Node* BuildBST(Node* root, int data)
{
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
int checkBST(Node* root)
{
	if(root==NULL){
		return true;
	}
	int left_max = checkBST(root->left);
	int right_min = checkBST(root->right);
	if(root->left!=NULL && root->right!=NULL){

	}
}
int main()
{
	Node* root = TakeInput();
	PrintBST(root);
}