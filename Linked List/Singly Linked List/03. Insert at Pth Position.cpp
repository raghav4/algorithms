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
	// Handling the special cases
	// If we want to insert at the 0th position.
	Node* nn = new Node(data);
	if(position==1){
		nn->next = head;
		head = nn;
		return;
	}
	Node* temp = head;
	for(int i=0;i<position-2;i++){
		temp = temp->next;
	}
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
	// InsertAtTail(head,1);
	// InsertAtTail(head,3);
	// InsertAtTail(head,4);
	// Inserting 2 at 1st position then our ll will be 1->3->4 to 2->1->3->4
	InsertAtPth(head,2,1);
	InsertAtPth(head,3,2);
	InsertAtPth(head,4,1);
	InsertAtPth(head,5,2);
	print(head);
	return 0;
}

