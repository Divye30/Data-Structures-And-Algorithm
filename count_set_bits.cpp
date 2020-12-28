#include<iostream>
using namespace std;
int count_set_Bits(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<count_set_Bits(n)<<endl;
}
