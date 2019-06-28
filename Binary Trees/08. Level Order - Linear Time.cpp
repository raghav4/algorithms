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
void PrintLevelOrder(Node* root)
{
	queue<Node*>qq;
	qq.push(root);
	qq.push(NULL);
	// Looping Until our Queue isn't empty
	while(!qq.empty())
	{
		Node* f = qq.front();
		// If front is NULL, then print a new line and insert a NULL at the end of the queue.
		if(!f){
			qq.pop();
			cout<<endl;
			if(!qq.empty()){ // If queue is empty and we keep on pushing NULLs then it'll lead to a infinite loop.
				qq.push(NULL);
			}
		}
		else{
			cout<<f->data<<" "; // Print the front of the Queue.
			qq.pop(); // Remove the Node from the Queue.
			if(f->left!=NULL){
				qq.push(f->left);
			}
			if(f->right!=NULL){
				qq.push(f->right);
			}
		}
	}
	return;
}
int main()
{
	Node* root = BuildTree();
	
	PrintLevelOrder(root);
}

// Here we're using the Queue for printing the Tree in Level Order having Linear O(N) time complexity