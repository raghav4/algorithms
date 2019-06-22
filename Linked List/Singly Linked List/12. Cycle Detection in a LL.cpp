// Detect a Cycle in a Linked List
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

// Detect Cycle
bool DetectCycle(Node* head)
{
	Node* slow = head;
	Node* fast = head;

	while(fast!=NULL && fast->next!=NULL)
	{
		if(fast==slow){
			cout<<"I'm in\n";
			cout<<slow->data<<endl;
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
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
	int data;
	while(cin>>data)
	{
		if(data==-1)
			break;
		else
			Insert(head,data);
	}
	bool ans = DetectCycle(head);
	if(ans){
		cout<<"Found\n";
	}
	else{
		cout<<"Not Found a cycle\n";
	}
	print(head);
	return 0;
}

// Also Check out Hare & Tortoise Approach : https://www.geeksforgeeks.org/tag/tortoise-hare-approach/