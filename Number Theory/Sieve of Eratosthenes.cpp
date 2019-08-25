#include<bits/stdc++.h>
#define ll long long
#define MAX 100001 
using namespace std;
vector<int> sieve(){
	vector<int>isPrime(MAX+1);
	
	// Marking all the numbers as prime initially.
	fill(isPrime.begin(), isPrime.end(), 1);

	// Sieve Filling
	for(int i=2;i*i<=MAX;i++){
		if(isPrime[i]){
			for(int j=i*i;j<=MAX;j+=i){
				isPrime[j] = 0;
			}
		}
	}
	// 
	return isPrime;

}
int main()
{
	int n;
	cin>>n;
	vector<int>primes = sieve();
	for(int i=1;i<=n;i++){
		if(primes[i]){
			cout<<i<<" ";
		}
	}
}

/*
If you observe that the first multiple of each prime number that is to be struck out is that square of the number.
We''ll use this in our code :). You can also mathematically prove this.
Conversely we'll also only strike out multiples of numbers that are under sqrt(n) 
as the ones larger than it will be the prime numbers left which have no multiples under n.
*/

