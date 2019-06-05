// Singly LL: Insert in the Middle.
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
	}
};

void InsertAtNth(Node *&head, int data, int position)
{
	Node* temp = new Node(data);
	temp -> next = NULL;
	// When the position is 1 or head = null.
	if(position==1){
		temp -> next = head;
		head = temp;
		return;
	}
	Node* tt = head;
	for(int i=0;i<(position-2);i++){
		tt = tt -> next;
	}
	temp -> next = tt->next;
	tt -> next = temp;
	return;
}
void printLL(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head -> next;
	}
	return;
}
int main()
{
	Node* head = NULL;
	InsertAtNth(head,1,1); // OP: 1
	InsertAtNth(head,2,2); // OP: 1,2
	InsertAtNth(head,3,3); // OP: 1,2,3
	InsertAtNth(head,4,2); // OP: 1,4,2,3
	printLL(head);
}