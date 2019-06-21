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

Node* GetMiddle(Node* head)
{
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void InsertAtMiddle(Node* head, int data)
{
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* nn = new Node(data);
	nn->next = slow->next;
	slow->next = nn;
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
	InsertAtTail(head,2);
	InsertAtTail(head,3);
	InsertAtTail(head,4);
	InsertAtTail(head,5);
	InsertAtTail(head,6);

	// Insert At Middle.
	InsertAtMiddle(head,10);
	print(head);
	cout<<endl;

	// Get Middle Element of a LL.
	Node* MiddleElement = GetMiddle(head);
	cout<<MiddleElement->data;
	
	return 0;
}