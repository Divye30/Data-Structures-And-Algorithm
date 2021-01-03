#include<iostream>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=1;
    for(ll i=0; i<b; i++)
    {
        ans*=a%c;
        ans%=c;
    }
    cout<<ans<<endl;
}
