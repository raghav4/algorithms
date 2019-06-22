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
Node* Reverse(Node* head)
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* SmallNode = Reverse(head->next);
	Node* currentHead = head;
	currentHead->next->next = currentHead;
	currentHead->next = NULL;
	return SmallNode;
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
int Intersection_Point(Node* a, Node* b)
{
	int data = -1;
	while((a)&&(b))
	{
		if(a->data==b->data){
			data = a->data;
		}
		else{
			break;
		}
		a = a->next;
		b = b->next;
	}
	return data;
}
int main()
{
	Node* head1 = NULL;
	Node* head2 = NULL;
	int a,b,data;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>data;
		Insert(head1,data);
	}
	cin>>b;
	for(int i=0;i<b
		;i++){
		cin>>data;
		Insert(head2,data);
	}
	head1 = Reverse(head1);
	head2 = Reverse(head2);
	int intersection = Intersection_Point(head1,head2);
	cout<<intersection;
	return 0;
}