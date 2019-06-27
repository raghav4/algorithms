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
Node* DeleteInBST(Node* root, int data)
{
	if(root==NULL){
		return NULL;
	}
	if(data < root->data){
		root->left = DeleteInBST(root->left,data);
	}
	else if(data==root->data){
		// Case 1: When there is 0 child.
		if(root->left==NULL&&root->right==NULL){
			delete root;
			return NULL;
		}
		// Case 2: When there is 1 child.
		if(root->left!=NULL && root->right==NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		// Case 3: When there are 2 children.
		else{
			Node* replace = root->right;
			while(replace->left!=NULL){
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = DeleteInBST(root->right,replace->data);
			return root;
		}
	}
	else{
		root->right = DeleteInBST(root->right,data);
		return root;
	}
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
void PrintTree(Node* root)
{
	if(root==NULL){
		return;
	}
	// Inorder Print
	PrintTree(root->left);
	cout<<root->data<<" ";
	PrintTree(root->right);
}
int main()
{
	cout<<"Enter the Tree, followed by -1 to terminate taking Input\n";
	Node* root = TakeInput();
	PrintTree(root);
	cout<<endl;
	int data;
	cout<<"Enter the data to delete from the node\n";
	cin>>data;
	root = DeleteInBST(root,data);
	PrintTree(root);

}