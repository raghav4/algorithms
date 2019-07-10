#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
	unordered_map<string,int>m;
	m.insert(make_pair("Mango",100));
	m["Apple"] = 200;
	m["Apple"] += 20;
	m["Pineapple"] = 50;
	cout<<m["Apple"]<<"\n";
	if(m.count("Guava")==0){
		cout<<"Guava Does not exist in the map\n";
	}
	else{
		cout<<m["Guava"]<<endl;
	}
	// find funciton in map
	// unordered_map<string, int>::iterator f = m.find("mango");
	auto fd = m.find("Mango");
	if(fd!=m.end()){
		cout<<fd->first<<" & "<<fd->second<<endl;
	}
	for(auto x: m){
		cout<<x.first<<" "<<x.second<<endl;
	}
}

// map<int,int> is a self balancing tree.
// unordered_map::max_load_factor.
// Insertion and searching is slow in map. They are in sorted order: inorder.