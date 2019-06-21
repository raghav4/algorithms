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
// Function to find out the length of the LL.
int length(Node* head)
{
	if(head==NULL){
		return 0;
	}
	int len = 1 + length(head->next);
	return len;
}

int KthFromEnd(Node* head, int k)
{
	Node* slow = head;
	Node* fast = head;
	for(int i=0;i<k;i++){
		fast = fast->next;
	}
	while(fast!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}
void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
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
int main()
{
	Node* head = NULL;
	Insert(head,1);
	Insert(head,2);
	Insert(head,3);
	Insert(head,4);
	Insert(head,5);
	cout<<KthFromEnd(head,3);
	return 0;
}

// The Brute force approach is to calculate the length of the LL, then iterate length-k times and print. But, it'd take O(N) to find the length
// and ~O(N) to iterate over Kth Element from the last.

// What we can do is, we can maintain two pointers, one slow and another fast, and first move the fast pointer Kth from beginning.
// Then we'll simulataneously move the slow and fast until the fast reaches to NULL. After this our slow pointer will be at Kth Node from last.