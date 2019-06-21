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
	 ~Node() // Destructor to delete the entire LL.
	 {

	 }
};

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
	

	print(head);
	return 0;
}