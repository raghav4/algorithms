// Singly LL implementation using a class.
#include<iostream>

using namespace std;
class node // Node Packet of a LL
{
 public:
	 int data; // the head node.
	 node* next; // pointer to class which will store only the address of the next node.
	 node(int d) // constructor to initialize the value to the head node.
	 {
	 	data = d;
	 	next = NULL;
	 }
	// The size of this LL is 8 bytes(4 bytes of int + 4 bytes of pointer)
};

// funtion to insert at the head of the LL : 
void insertAtHead(node *&head, int data) 
{
	node* nn = new node(data); //Passing the data into the constructor.
	nn -> next = head;
	head = nn;
}

// function to print the LL : 
void print(node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main()
{
	node* head = NULL;
	int n,m;
	cout<<"Enter the number of elements you want to have in your LL\n";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the number\n";
		cin>>m;
		insertAtHead(head,m);
	}
	print(head);
}
// Some Important Points : 
// The only information we store is the address of the head node, with the help of head node we can traverse the entire Linked List.
// The address of the last node is always NULL as it doesn't point elsewhere.
// The time taken (worst-case) to traverse the LL is proportional to the size of the LL, O(n) where n is the size of the LL.
// In case of LL we don't have to consider declaring the size of an array to upper limit hence that memory is stored in ll but some extra memory to store the pointer to next node is consumed here.
// If we implement class for the Node of a LL, the class is referred as the self referenital class as we are having the pointer of same class which is pointing to another similar class.
// For insertion in LL, it can be done at : Head, Middle, Tail. Unlike in Array where we can only insert the elements at the end of it.
// Memory block of each of the Node is totally random, there's no gurantee that the next node's address will be in increasing order, it can be lesser than the current as linked list's node is created wherever the memory is found.
// We create a head node to store the address of the first node of a linked list. With the help of this we perform operations on the entire LL.
// We are not doing static allocation (node n, n.next = head) here and after the function call is over this static object will be destroyed that's why we are using dynamic allocation.
// Here (*nn) is the object.