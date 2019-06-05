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

void InsertAtTail(Node *&head, int data)
{
	Node *temp = new Node(data);
	if(head==NULL){
		temp -> next = NULL;
		head = temp;
	}
	else{
		Node* t1 = head;
		while(t1->next!=NULL){
			t1 = t1->next;
		}
		t1->next = temp;
	}

}
void printLL(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head -> next;
	}
}
int main()
{
	Node* head = NULL;
	InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
	printLL(head);
}

// The input can be changed, you can take input with the help of loop also.