#include<iostream>
using namespace std;
void f(int n, string output="")
{
	// Base Case
	if(n==0){
		cout<<output<<endl;
		return;
	}
	for(int i=0;i<=9;i++){
		f(n-1,output+to_string(i));
	}
}
int main()
{
	int n;
	cin>>n;
	f(n);
}