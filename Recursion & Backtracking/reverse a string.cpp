// program to reverse a string using recursion with no extra space.
#include<iostream>
#include<string>
using namespace std;
void reverse(string &str,int i,int size)
{
	// Base Case.
	if(i>(size/2))
		return;
	//Recursive Steps.
	swap(str[i],str[size-i-1]);
	reverse(str,i+1,size);
}
int main()
{
	string s;
	cin>>s;
	int l = s.length();
	reverse(s,0,l);
	cout<<"Reverse string is : "<<s;
}