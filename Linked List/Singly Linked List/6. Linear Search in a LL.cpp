#include<bits/stdc++.h>
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

int SearchInLL(Node* head, int key)
{
	int ct = 0;
    if(head==NULL){
        return INT_MIN;
    }
    else if(head->data==key){
        return 0;
    }
    ct = 1 + SearchInLL(head->next,key);
    if(ct==-1){
        return -1;
    }
    return ct;
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
	Insert(head,1);
	Insert(head,2);
	Insert(head,3);
	Insert(head,4);
	Insert(head,5);
    int search = SearchInLL(head,234);
	if(search<0){
        cout<<"Not found in the LL\n";
    }
    else{
        cout<<"Found at "<<search<<endl;
    }
	return 0;
}-