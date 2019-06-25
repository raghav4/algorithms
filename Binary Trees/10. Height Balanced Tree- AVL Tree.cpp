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
// bool CheckHeightBalance(Node* root)
// {
// 	if(root==NULL){
// 		return true;
// 	}
// 	int lh = HeightOfBT(root->left);
// 	int rh = HeightOfBT(root->right);

// 	if(abs(lh-rh)>1){
// 		return false;
// 	}
// 	return (CheckHeightBalance(root->left) || CheckHeightBalance(root->right));
// }
int main()
{
	Node* root = BuildTree();
	bool ans = CheckHeightBalance(root);
}