#include<iostream>
using namespace std;
void toi(int n, char src, char dest, char helper)
{
	if(n==0){
		return;
	}
	// recursive cases.
	// 1. Move N-1 disks from src to helper.
	toi(n-1,src,helper,dest);

	cout<<"Move the disk "<<n<<" from "<<src<<" to "<<dest<<endl;

	toi(n-1,helper,dest,src);

}
int main()
{
	int n; 
	cin>>n;
	char a,b,c;
	cin>>a>>b>>c;
	toi(n,a,c,b);
}