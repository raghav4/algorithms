#include<iostream>
using namespace std;
class Node 
{
 public:
	 int data; 
	 Node* next; 
	 Node(int d)
	 {
	 	data = d;
	 	next = NULL;
	 }
};
int length(Node* head)
{
	if(head==NULL){
		return 0;
	}
	return 1 + length(head->next);
}
void Insert(Node *&head, int data)
{
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	Node* nn = new Node(data);
	temp->next = nn;
	return;
}
void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
void fn(Node* &head, int k, int n)
{
	Node* first = head;
	Node* temp=head;
	for(int i=0;i<n-k-1;i++){
		temp = temp->next;
	}
	Node* second = temp->next;
	Node* nn = second;
	temp->next = NULL;
	while(second->next!=NULL){
		second = second->next;
	}
	second->next = head;
	head = nn;
}
int main()
{
	Node* head = NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		Insert(head,data);
	}
	int k;
	cin>>k;
	k%=n;
	fn(head,k,n);
	print(head);
	return 0;
}