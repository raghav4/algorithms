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
class HBPair
{
public:
	int height;
	bool balanced;
};
Node* BuildTree(string s)
{
	if(s=="true")
	{
		int data;
		cin>>data;
		Node* root = new Node(data);
		string lt;
		cin>>lt;
		if(lt=="true"){
			root->left = BuildTree(lt);
		}
		string rt;
		cin>>rt;
		if(rt=="true"){
			root->right = BuildTree(rt);
		}
		return root;
	}
	return NULL;
}

int height(Node* root)
{
	if(root==NULL){
		return 0;
	}
	return max(height(root->left),height(root->right)) + 1;
}
void PrintKthLevelLeft(Node* root, int k)
{
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}
	PrintKthLevelLeft(root->left,k-1);
	PrintKthLevelLeft(root->right,k-1);
}
void PrintKthLevel(Node* root, int k)
{
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}
	PrintKthLevel(root->right,k-1);
	PrintKthLevel(root->left,k-1);
}
void PrintZigZag(Node* root)
{
	int ht = height(root);
	for(int i=0;i<ht;i++){
		if(i%2==0){
			PrintKthLevelLeft(root,i);
		}
		else{
			PrintKthLevel(root,i);
		}
	}
}
int main()
{
	Node* r1 = BuildTree("true");
	PrintZigZag(r1);
}

// Improve this solution.