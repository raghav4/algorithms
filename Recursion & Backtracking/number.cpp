#include<bits/stdc++.h>
using namespace std;
char alphabets[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<string>ans;
void cal(string str, int l)
{	
	if(l==0){
		reverse(ans.begin(),ans.end());
		for(auto x: ans){
			cout<<ans<<", ";
		}
	}
	ans.push_back(alphabets[(str[l-1]-'0')]);
	cal(str,l-1);
}
int main()
{
	string str;
	cin>>str;
	cal(str,str.length());
}