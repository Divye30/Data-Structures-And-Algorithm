#include<iostream>
using namespace std;
void decimal_to_binary(int n)
{
    long int bin=0;
    int j=1;
    while(n>0)
    {
        bin= bin + j*(n&1);
        j=j*10;
        n=n>>1;
    }
    cout<<bin<<endl;
}
int main()
{
    int n;
    cin>>n;
    decimal_to_binary(n);
}
