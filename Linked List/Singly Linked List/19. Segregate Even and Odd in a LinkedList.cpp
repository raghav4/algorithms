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

void SegregateRecursive(Node *&head)
{
	if(head==NULL){
		return;
	}	
}
void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
void Segregate(Node *&head)
{
	if(head==NULL){
		return;
	}
	Node* even = head;
	Node* odd = head;
	Node* temp = head;
	while(temp){
		// If the node is of odd data then append it to the odd pointer of the linked list
		if((temp->data)&1){
			odd->next = temp;
		}else{
			even->next = temp;
		}
	}
	print(even);
	print(odd);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
	    Node* head = NULL;
    	int n,data;
    	cin>>n;
    	for(int i=0;i<n;i++){
    		cin>>data;
    		InsertAtTail(head,data);
    	}
    	Segregate(head);
    	//print(head);
	}
	return 0;
}
