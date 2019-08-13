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
		Node* nn = new Node(data);
		head = nn;
		return;
	}
	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	Node* nn = new Node(data);
	temp->next = nn;

}
void deleteNode(Node *&head, int position)
{
	Node* temp = head;
	if(position == 1){
	// If we would've used head = head->next to delete the node, it would still occupy space in the memory
		head = temp->next;
		delete temp;
		return;
	}
	for(int i=0;i<position-2;i++){
		temp = temp->next;
	}
	Node* tempNext = temp->next;
	temp->next = tempNext->next;
	delete  tempNext;
}
void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
int main()
{
	Node* head = NULL;
	Insert(head,2);
	Insert(head,4);
	Insert(head,6);
	Insert(head,5);
	print(head); // 2,4,6,5
	deleteNode(head,3);
	print(head); // 2,4,5
	return 0;
}