#include<iostream>
#include<queue>
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
void PrintTree(Node* root)
{
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	PrintTree(root->left);
	PrintTree(root->right);
}
void LevelOrder(Node* root)
{
	queue<Node*>qq;
	qq.push(root);
	qq.push(NULL);
	while(!q.empty())
	{
		Node* f = qq.front();
		if(!f){
			qq.pop();
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			qq.pop(); // Removing Node from the front of the queue.
			cout<<f->data<<" ";
			if(f->left!=NULL){
				qq.push(f->left);
			}
			if(f->right!=NULL){
				qq.push(f->right);
			}
		}
	}
}
int main()
{
	Node* root = BuildTree();
	
	PrintTree(root);
}

// Here we're using the Queue for printing the Tree in Level Order having Linear O(N) time complexity