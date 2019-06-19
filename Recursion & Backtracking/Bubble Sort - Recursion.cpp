#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr, int i, int n)
{
    if(n<=1){
        return;
    }
    if(i==n-1){
        // if i is at last element then our largest element is at last, now do so for other elements as well.
        bubbleSort(arr,0,n-1);
        return;
    }
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    bubbleSort(arr,i+1,n);
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubbleSort(a,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
