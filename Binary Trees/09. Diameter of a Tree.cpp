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
int HeightOfBT(Node* root)
{
	if(root==NULL){
		return 0;
	}
	int left_height = HeightOfBT(root->left);
	int right_height = HeightOfBT(root->right);
	return max(left_height,right_height) + 1;
}
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
int DiamterOfTree(Node* root)
{
	if(root==NULL){
		return 0;
	}
	int h1 = HeightOfBT(root->left);
	int h2 = HeightOfBT(root->right);
	return max((h1,h2),(h1+h2));
}
int main()
{
	Node* root = BuildTree();
	cout<<DiamterOfTree(root);
}

// O(N^2)
// 
// In order to optimize the solution try bottom up approach instead of top down approach.