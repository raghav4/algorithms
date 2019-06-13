// Subsequence using recursion
#include<iostream>
using namespace std;
void printsub(char *inp, char *out,int i,int j)
{
    if(inp[i]=='\0'){
        out[j]='\0';
        cout<<out<<", ";
        return;
    }
    out[j]=inp[i];
    printsub(inp,out,i+1,j+1);
    printsub(inp,out,i+1,j);
}
int main()
{
    char inp[100];
    cin>>inp;
    char out[100];
    printsub(inp,out,0,0);
}