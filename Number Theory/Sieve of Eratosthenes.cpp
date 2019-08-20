// Working till 10^4, afterwards Segmantation Fault: 11
#include<iostream>
#define N 10000000
using namespace std;
int p[N+1] = {0};
void GenerateSieve(int n)
{
	p[0] = p[1] = 0; // 0 and 1 are not prime
	p[2] = 1; // 2 is prime

	// Marking all the odd numbers as prime initially
	for(int i=3;i<=n;i+=2){
		p[i] = 1;
	}

	// Marking non prime odd numbers as 0
	for(int i=3;i<=n;i+=2){
		if(p[i]){
		// Marking the multiples of that numbers as not prime.
			for(int j=i*i;j<=n;j+=(2*i)){ // Optimised 2i -> i*i, j+=i -> j+=2i
				p[j] = 0;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	GenerateSieve(n);
	for(int i=0;i<=N;i++){
		if(p[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}