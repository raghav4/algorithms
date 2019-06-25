#include<iostream>
#include<algorithm>
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
int main()
{
	int arr[] = {7,3,1,5,10,9,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	int cpy[n];
	for(int i=0;i<n;i++){
		cpy[i] = arr[i];
	}
	sort(cpy,cpy+n);

}


// Time Complexity : O(N) {Counting Sort} + O(LogN) {Searching} + O(N) {Tree Build}
// Recursive Thinking.