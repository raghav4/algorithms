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
class HBPair
{
	public: 
	int height;
	bool balanced;
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
HBPair CheckHeightBalance(Node* root)
{
	HBPair P;
	if(root==NULL){
		P.height = 0;
		P.balanced = true;
		return P;
	}
	HBPair left = CheckHeightBalance(root->left);
	HBPair right = CheckHeightBalance(root->right);
	P.height = max(left.height,right.height) + 1;
	if(abs(left.height-right.height)<=1 && left.balanced && right.balanced){
		P.balanced = true;
	}
	else{
		P.balanced = false;
	}
	return P;
}
int main()
{
	Node* root = BuildTree();
	bool ans = CheckHeightBalance(root).balanced;
	(ans)?(cout<<"Yes, It's Balanced\n"):(cout<<"No, its not a height balanced tree!\n");
}