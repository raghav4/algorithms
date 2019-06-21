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

// Reverse a Linked List Recursive
Node* ReverseLLrecursive(Node* head)
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* small_head = ReverseLLrecursive(head->next);
	Node* temp = head;
	temp->next->next = temp;
	temp->next = NULL;
	return small_head;
}

// Reversing a Linked List Iterative
void ReverseLLIterative(Node *&head)
{
	if(head==NULL){
		return;
	}
	Node* current = head;
	Node* prev = NULL;
	Node* next_node;
	while(current!=NULL)
	{
		// Saving The Current Node.
		next_node = current->next;
		// Current Node pointing to the previous node.
		current->next = prev;
		// Updating  the previous node.
		prev = current;
		// Updating the current node.
		current = next_node;
	}
	// Updatint the pointer of head node to the prev node, which is reverse LL.
	head = prev;
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
	Insert(head,1);
	Insert(head,2);
	Insert(head,3);
	Insert(head,4);
	Insert(head,5);
	// Output Before Reversing List.
	print(head);
	cout<<endl;
	// Output After Reversing List.
	head = ReverseLLrecursive(head);
	print(head);
	return 0;
}