#include<iostream>
#include<unordered_map>
using namespace std;
class Node
{
	char data;
	unordered_map<char,Node*>m;
public:
	Node(char d){
		data d;
		isTerminal = false;
	}
};
class Trie
{
	Node* root;
public:
	Trie{
		root = new Node('\0');
	}
	void AddWord(char []word){
		Node* temp = new Nod
	}
};
int main()
{

}