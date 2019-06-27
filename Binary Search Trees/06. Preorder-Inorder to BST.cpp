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
Node* BuildBST(Node* root, int data)
{
	if(root==NULL){
		Node* nn = new Node(data);
		return nn;
	}
	if(data<root->data){
		root->left = BuildBST(root->left, data);
	}
	else{
		root->right = BuildBST(root->right, data);
	}
	return root;
}
Node* TakeInput(){
	int data;
	cin>>data;
	Node* root = NULL;
	while(data!=-1){
		root = BuildBST(root,data);
		cin>>data;
	}
	return root;
}
Node* CreateTreeTraversal(int *inO, int *preO, int s, int e)
{
	static int x = 0;
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	Node *root = new Node(preO[x]);
	int index = -1;
	for(int j=s;j<=e;j++){
		if(inO[j]==preO[x]){
			index = j;
			break;
		}
	}
	x++;
	root->left = CreateTreeTraversal(inO,preO,s,index-1);
	root->right = CreateTreeTraversal(inO,preO,index+1,e);
	return root;

}

void bfs(Node *root)
{
    if(root==NULL){
    	return;
    }
    if(root->left)
      cout<<root->left->data;
    else
      cout<<"END";
    cout<<" => "<<root->data<<" <= ";
    if(root->right)
      cout<<root->right->data;
    else
      cout<<"END"<<endl;
    bfs(root->left);
    bfs(root->right);
}
int main()
{
	int m,n;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	Node* root = CreateTreeTraversal(b,a,0,n-1);
	bfs(root);
}