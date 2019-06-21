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

void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
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
Node* ReverseLL(Node* head)
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* headsNext = ReverseLL(head->next);
	Node* temp = head;
	temp->next->next = temp;
	temp->next = NULL;
	return headsNext;
}
bool checkPalindrome(Node* head) 
{
	Node* first = head;
	Node* mid = MidOfLL(head);
	Node* second = mid->next;
	mid->next = NULL;
	second = ReverseLL(second);
	while((first) && (second))
	{
		if((first->data)!=(second->data)){
			return false;
		}
		first = first->next;
		second = second->next;

	}
	return true;
}
int main()
{
	Node* head = NULL;
	int n,data;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data;
		Insert(head,data);
	}
	(checkPalindrome(head))?(cout<<"True\n"):(cout<<"False\n");

	return 0;
}

// Todo: Using Recursion & Stack Implementation.