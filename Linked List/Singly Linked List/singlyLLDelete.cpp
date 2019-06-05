#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int d){
		data = d;
	}
	
};
void insert(Node* &head, int data)
{
	Node* nn = new Node(data); // Creating a Node and storing the data into it.
	nn -> next = NULL;
	if(head==NULL){
		head = nn;
		return;
	}
	Node* temp = head; // Pointer to Node, Storing the head node's address.
	while(temp->next!=NULL){ // Traversing to the last node.
		temp = temp -> next;
	}
	temp -> next = nn;
}
void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head -> next;
	}
	return;
}
void DeleteAtHead(Node *&head)
{	
	if(head==NULL){
		return;
	}
	head = head->next;
}
void DeleteAtTail(Node *&head)
{
	if(head==NULL){
		return;
	}
	Node* temp = head;
	while((temp->next->next)!=NULL){
		temp = temp -> next;
	}
	temp -> next = NULL;
}
// void DeleteAtNth(Node *&head, int position)
// {
// 	if(head==NULL){
// 		return;
// 	}
// 	Node* temp = head;
// 	for(int i=0;i<position-1;i++){
// 		temp = temp -> next;
// 	}
	
// }
int main()
{
	Node *head = NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	// DeleteAtHead(head);
	insert(head,4);
	insert(head,5);
	// DeleteAtTail(head);
	print(head);
}


// Note: Deletion of a Node in the middle is handled by the DeleteAtNth position function, however a better approach can be to use fast pointer.
