#include<iostream>
using namespace std;
int exponential(int a, int b)
{
    int ans=1;
    while(b>0)
    {
        int last_bit=(b&1);
        if(last_bit==1)
            ans=ans*a;
        a=a*a;
        b=b>>1;
    }
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<exponential(a, b)<<endl;
}
