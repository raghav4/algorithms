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
	cout<<"The Diamter of the Binary Tree is "<<DiamterOfTree(root);
}

// O(N^2)
// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
