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
class Pair
{
public:
	int height;
	int diameter;
};
int height(Node* root)
{
	if(root==NULL){
		return 0;
	}
	return 1 + max(height(root->left),height(root->right));
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
Pair DiameterOfBT(Node* root)
{
	Pair P;
	if(root==NULL){
		P.height = P.diameter = 0;
		return P;
	}
	Pair left = DiameterOfBT(root->left);
	Pair right = DiameterOfBT(root->right);

	P.height = max(left.height,right.height) + 1;
	P.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
	return P;
}
int main()
{
	Node* root = BuildTree();
	Pair P = DiameterOfBT(root);
	cout<<P.diameter<<endl;
}

// Diameter : Two Points who are farthest from each other, and the distance between them is known as the diameter. We consider edges as the distance.
// Input : 5 4 8 -1 -1 6 -1 3 -1 -1 9 -1 1 -1 -1
// 	     	 5
//    	   /  \
//        4    9
//      /  \    \
//     8    6	 1
//     		 \
//        	  3	
//  
//  Answer : 5, as the maximum distance between any two nodes is 5 and the nodes are 3 and 1.
//  Time Complexity : O(N)
