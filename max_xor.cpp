#include<iostream>
#include<cmath>
using namespace std;
int maximizingXor(int l, int r)
{
    int temp=l^r;
    int ans=temp;
    int j=0;
    while(temp>0)
    {
        if((temp&1)==0)
        {
            ans=ans+(1<<j);
        }
        j++;
        temp=temp>>1;
    }
    return ans;
}
int main ()
{
    int l,r;
    cin>>l>>r;
    cout<<maximizingXor(l,r)<<endl;
}
