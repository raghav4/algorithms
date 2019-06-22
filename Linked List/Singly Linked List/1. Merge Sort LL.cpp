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
Node* MeregeLL(Node* a, Node *b)
{
	if(a==NULL){
		return a;
	}
	if(b==NULL){
		return a;
	}
	Node* temp;
	if(a->data <= b->data){
		temp = a;
		temp->next = MeregeLL(a->next,b);
	}
	else{
		temp = b;
		temp->next = MeregeLL(a,b->next);
	}
	return temp;
}
Node* MidOfLL(Node* head)
{
	Node* slow = head;
	Node* fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node* MergeSort(Node *head)
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	// Recursive Case
	// Breaking the Linked List into two parts.
	Node* mid = MidOfLL(head);
	Node* first = head;
	Node* second = mid->next;
	mid->next = NULL; //?
	Node* a = MergeSort(first);
	Node* b = MergeSort(second);
	return MeregeLL(a,b);
}
void InsertAtHead(Node *&head, int data)
{
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node* temp = new Node(data);
	temp -> next = head;
	head = temp;
	return;
}
void printLL(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	return;
}
int main()
{
	Node* head = NULL;
	int n;
	cin>>n;
	InsertAtHead(head,4);
	InsertAtHead(head,10);
	InsertAtHead(head,2);
	InsertAtHead(head,23);
	MergeSort(head);
	printLL(head);
}