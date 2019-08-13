#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};
node* InsertAtTail(node *&head, int data)
{
	if(head==NULL){
		return new node(data);
	}
	while(head->next!=NULL){
		head = head->next;
	}
	node* nn = new node(data);
	nn->next = NULL;
	head = nn;
}
void print(node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main()
{
	int n,d;
	cin>>n;
	node* head = NULL;
	for(int i=0;i<n;i++){
		cin>>d;
		InsertAtTail(head,d);
	}

}