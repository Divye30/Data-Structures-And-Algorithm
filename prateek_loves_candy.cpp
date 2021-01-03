#include<iostream>
using namespace std;
#define ll long long
void prime_sieve(int *p)
{
    p[2]=1;
    p[1]=p[0]=0;
    for(int i=3; i<=1000000; i+=2)
    {
        p[i]=1;
    }
    for(ll i=3; i<=1000000; i+=2)
    {
        if(p[i]==1)
        {
            for(ll j=i*i; j<=1000000; j+=i)
            {
                p[j]=0;
            }
        }
    }
    ll j=0;
    for(ll i=0; i<=1000000; i++)
    {
        if(p[i]==1)
        {
            p[j]=i;
            j++;
        }
    }
}
int main()
{
    int p[1000000]={0};
    prime_sieve(p);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<p[n-1]<<endl;
    }
}
