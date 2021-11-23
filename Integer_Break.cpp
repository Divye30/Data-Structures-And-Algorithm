#include<iostream>
using namespace std;
int integerBreak(int n)
{
    if(n<=3)
        return n-1;
    int a=0,b=1,c=2,d=3;
    int ans;
    for(int i=4; i<=n; i++)
    {
        ans=max(2*c,3*b);
        a=b,b=c,c=d,d=ans;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<integerBreak(n)<<endl;
}
