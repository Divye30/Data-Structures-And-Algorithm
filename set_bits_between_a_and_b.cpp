#include<iostream>
using namespace std;
int total_set_Bits(int a, int b)
{
    int ans=0;
    for(int i=a; i<=b; i++)
    {
        int temp=i;
        while(temp>0)
        {
            ans+=(temp&1);
            temp=temp>>1;
        }
    }
    return ans;
}
int main()
{
    int Q,a,b;
    cin>>Q;
    for(int q=0; q<Q; q++)
    {
        cin>>a>>b;
        cout<<total_set_Bits(a, b)<<endl;
    }
}
