#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
	int data;
	Node* left; // Pointer to the left node
	Node* right; // Pointer to the right node
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
	
};

Node* BuildBST(Node* root, int data)
{
	if(root==NULL){
		return new Node(data);
	}
	// If the data is smaller then the data of root, call the BuildBST function for left part of root.
	if(data < root->data){
		root->left = BuildBST(root->left,data);
	}
	// Else call for the right part of the root.
	else{
		root->right = BuildBST(root->right,data);
	}
	return root;
}
Node* TakeInput()
{
	int data;
	cin>>data;
	Node* root = NULL;
	while(data!=-1){
		root = BuildBST(root,data);
		cin>>data;
	}
	return root;
}

// Level order print 
void PrintLevelOrder(Node*root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		Node* f = q.front();
		if(f==NULL)
		{
			q.pop();
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<f->data<<" ";
			if(f->left!=NULL){
				q.push(f->left);
			}
			if(f->right!=NULL){
				q.push(f->right);
			}
		}
	}
}
void PrintInOrder(Node* root)
{
	if(root==NULL){
		return;
	}
	cout<<root->data<<endl;
	PrintInOrder(root->left);
	PrintInOrder(root->right);
}
int main()
{
	Node* root = TakeInput();
	PrintInOrder(root);
	cout<<endl;
	PrintLevelOrder(root);
}

/*
Inorder traversal of a Binary Search Tree will always be in a sorted order, for eg: consider a tree

              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80
The Inorder traversal of this tree will be, 20,30,40,50,60,70,80. Which is in sorted order.
*/