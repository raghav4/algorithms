#include<iostream>
#include<string>
using namespace std;
int StringToInteger(string str, int sz)
{
	// Base Case.
	if(sz==0){
		return str[0]-'0';
	}
	// Recursive Case.
	// let the sample input is 1234
	// we will just add the last digit to the final answer which should be 1230, so what we will be returning is 1230+4=1234 to the main fn.
	// 123*10 + 4 = 1234
	int digit = str[sz]-'0';
	return digit + (10*StringToInteger(str,sz-1));
}
int main()
{
	string s;
	cin>>s;
	cout<<StringToInteger(s,s.length()-1);
}