#include<iostream>
#include<queue>
#define ll long long
using namespace std;
ll max_level = 0;
class Node
{
public:
	ll data;
	Node* left;
	Node* right;
	Node(ll d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
Node* levelOrderBuild( ){
	queue<Node*> q;
	int d;
	cin>>d;

	Node*root = new Node(d);
	q.push(root);

	while(!q.empty())
	 {
		int c1,c2;
		cin>>c1>>c2;
		Node*f = q.front();
		q.pop();

		if(c1!=-1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}
	return root;
}
void left(Node*root,int level,int *max){
	if(root==NULL){
		return;
	}
	if(*max<level){
		cout<<root->data<<" ";
		*max=level;
	}
	left(root->right,level+1,max);
	left(root->left,level+1,max);
}
int main()
{
	Node* root = levelOrderBuild();
	int max = 0;
	left(root,1,&max);
}
