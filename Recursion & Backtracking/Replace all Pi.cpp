// Program to replace all 'pi' from a string with 3.14
#include<bits/stdc++.h>
using namespace std;
void shiftString(char *inp, int j, int len)
{
	for(int i=len;i>j;i--)
	{
		inp[i+2] = inp[i];
	}
}
void ReplacePi(char *inp, int i, int len)
{
	if(inp[i]=='\0'){
		return; // if input is empty just return.
	}
	// check for 'pi', if so then shift the char string (having some empty buffer)
	if(inp[i]=='p' && inp[i+1]=='i')
	{
		shiftString(inp,i+1,len);
		inp[i] = '3';
		inp[i+1] = '.';
		inp[i+2] = '1';
		inp[i+3] = '4';
		len+=2; // length will increase by 2, after we replace(pi,3.14).
	}
	ReplacePi(inp,i+1,len);
}
int main()
{
	char input[100001];
	cin>>input;
	int len = strlen(input);
	ReplacePi(input,0,len-1);
	cout<<input;
}