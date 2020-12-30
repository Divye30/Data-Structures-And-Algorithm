#include<iostream>
#include<string>
using namespace std;
void cipher(int k, char s[],int n)
{
    int str[1000000];
    for(int i=0; i<n; i++)
    {
        if(i==0)
        str[i]=int(s[i])%48;
        else if(i<k)
        {
            str[i]=int(s[i-1])^int(s[i]);
        }
        else{
            str[i]=(int(s[i])%48)^str[i-k]^(int(s[i-1])%48);
            }
    }
    for(int i=0; i<n; i++)
    cout<<str[i];
}
int main()
{
    int n,k;
    cin>>n>>k;
    char s[1000000];
    cin>>s;
    cipher(k,s,n);
}
