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
void InsertAtPth(Node *&head, int data, int position)
{ 
	Node* temp = head;
	for(int i=1;i<position-1;i++){
		temp = temp->next;
	}
	Node* nn = new Node(data);
	nn->next = temp->next;
	temp->next = nn;
	return;
}
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
	InsertAtTail(head,1);
	InsertAtTail(head,3);
	InsertAtTail(head,4);
	InsertAtPth(head,2,2);
	print(head);
	return 0;
}