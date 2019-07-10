#include<iostream>
#include<unordered_map>
using namespace std;

bool anagram(string s1, string s2){
	if(s1.size()!=s2.size()){
		return false;
	}
	unordered_map<char,int>mp;
	for(int i=0;i<s1.length();i++){
		mp[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		if(mp.find(s2[i])==mp.end()){
			return false;
		}
		else{
			mp[s2[i]]--;
			if(mp[s2[i]]==0){
				mp.erase(s2[i]);
			}
		}
	}
	return mp.size() ==0 ;
}

int main()
{
	string a,b;
	cin>>a>>b;
	if(anagram(a,b)){
		cout<<"Yeah, They're anagram\n";
	}
	else{
		cout<<"Nope, They're not anagram of each other\n";
	}
}