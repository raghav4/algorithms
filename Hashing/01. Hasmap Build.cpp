#include<iostream>
#define BASE 73
using namespace std;

template<typename T>
class Node
{
	public:
	string key; // Key 
	T value; // value of key
	Node<T> *next; // Pointer to next node storing the upcoming node.
	// Default constructor to initialise the key and values.
	Node(string k, T v){
		key = k;
		value = v;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next; 
		}
	}
};

template<typename T>
class Hashmap
{
	Node<T>** table;
	int CurrentSize,TableSize;
	int hashFn(string key){
		int index = 0;
		int pw = 1;
		int keylen = key.length();
		for(int j=0;j<keylen;j++){
			// index += (key[j]*pw)%TableSize; // out of index
			index = (index + (key[j]*pw)%TableSize)%TableSize;
			pw = (pw*BASE)%TableSize;
		}
		return index%TableSize;
	}
	void rehash(){
		Node<T>** OldTable = table;
		int OldSize = TableSize;
		TableSize = 2*TableSize; // Use Next Prime.
		table = new Node<T>*[TableSize];
		for(int i=0;i<TableSize;i++){
			table[i] = NULL;
		}
		CurrentSize = 0;
		// Iterate over previous table and insert those elements into the new table.
		for(int i=0;i<OldSize;i++){
			Node<T>*temp = OldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			if(OldTable[i]!=NULL){
				delete OldTable[i]; // fixed #1
			} 
			delete [] OldTable;
		}
	}
	public:
	Hashmap(int ts=7){
		TableSize = ts;
		table = new Node<T>* [TableSize];
		CurrentSize = 0;
		// Updating the default values (garbage) of arrays who are storing the address of the hashmap node, with the NULL.
		for(int i=0;i<TableSize;i++){
			table[i] = NULL;
		}
	}
	void insert(string key, T value){
		int index = hashFn(key);
		Node<T>* mp = new Node<T>(key,value);
		// Insertion at the head, which is taking O(1) to insert an element.
		mp->next = table[index];
		table[index] = mp;
		CurrentSize++;
		float LoadFactor = (CurrentSize)/(1.0 * TableSize);
		if(LoadFactor>0.7){
		//	cout<<"Rehashing...\n";
		//	rehash(); // rehashing not working needs to be fixed.
		}
	}
	void Print(){
		// Go to every bucket and print it's linked list associated with it as a chain.
		for(int i=0;i<TableSize;i++){
			cout<<"Bucket "<<i<<" : ";
			Node<T>*temp = table[i];
			while(temp!=NULL){
				cout<<temp->key<<" --> ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	T* search(string key){
		int index = hashFn(key);
		Node<T>* temp = table[index];
		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value); // return address of temp value.
			}
			temp = temp->next;
		}
		return NULL;
	}
	// Update the element.
	T& operator[](string key){
		T* found = search(key);
		if(found==NULL){ // Key not present
			T garbage;
			insert(key,garbage);
			found = search(key);
		}
		return *found;
	}
	void erase(string key){
		// Find and delete that node from the linked  list.
		
	}

};
int main()
{
	Hashmap<int>h;
	h.insert("Maggi",20);
	h.insert("Idli",30);
	h.insert("Pepsi",35);
	h.insert("Pasta",90);
	h.insert("Noodles",70);
	h.insert("Apple",10);
	h.insert("Mango",12);
	h.insert("Guava",40);
	h.insert("Strawbery",11);
	h.insert("Shake",12);
	h.insert("Juice",21);

	// string product;
	// cin>>product;
	// int *price = h.search(product);
	// if(price){
	// 	cout<<"Price : "<<*price<<endl;
	// }
	// else{
	// 	cout<<"Product not found\n";
	// }

	h.Print();
	h["Banana"] = 24;
	h["Banana"] = 30;
	h["Banana"] += 11;
	cout<<h["Banana"]<<endl;
}

// Rehashing