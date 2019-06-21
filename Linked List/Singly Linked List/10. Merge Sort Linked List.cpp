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
Node* MidOfLL(Node* head)
{
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node* MergeSortedLLRecursive(Node* a, Node* b)
{
	// Base Case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	Node* temp; // Pointer to store the address of sorted merged a LL.
	if((a->data)<=(b->data)){
		temp = a;
		temp->next = MergeSortedLLRecursive(a->next,b);
	}
	else{
		temp = b;
		temp->next = MergeSortedLLRecursive(a,b->next);
	}
	return temp;
}
Node* MergeSort(Node *head)
{
	// Base Case
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* mid = MidOfLL(head);
	Node* first = head;
	Node* second = mid->next;
	mid->next = NULL;
	first = MergeSort(first);
	second = MergeSort(second);
	return MergeSortedLLRecursive(first,second);
}
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
	Insert(head,23);
	Insert(head,12);
	Insert(head,45);
	Insert(head,230);
	Insert(head,5);
	head = MergeSort(head);
	print(head);
	return 0;
}