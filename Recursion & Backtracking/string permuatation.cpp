#include<bits/stdc++.h>
using namespace std;
set<string>s;
void printPermut(char *str, int i)
{
	if(str[i]=='\0'){
		s.insert(str);
		return;
	}	
	for(int j=i;str[j]!='\0';j++){
		swap(str[i],str[j]);
		printPermut(str,i+1);
		swap(str[i],str[j]);
	}

}
int main()
{
	char str[10001];
	cin>>str;
	printPermut(str,0);
	for(auto x: s){
		cout<<x<<endl;
	}
}