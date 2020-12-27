#include<iostream>
#include<cmath>
using namespace std;
long flippingBits(long n)
{
    return (pow(2,32)-1-n);
}
int main()
{
    int t;
    cin>>t;
    long n;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        cout<<flippingBits(n)<<endl;
    }
}
