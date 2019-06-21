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
void InsertAtTail(Node *&head, int data)
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
int main()
{
	Node* head = NULL;
	int n,data;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data;
		InsertAtTail(head,data);
	}
	print(head);
	return 0;
}