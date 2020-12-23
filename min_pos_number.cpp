#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
    lli N;
    cin>>N;
    lli n1=N,temp=N;
    lli t,v;
    lli i=1;
    while(n1>0)
    {
        t=n1%10;
        v=t;
        t=9-t;
        if(v>t && (t!=0 || n1>10))
        {
            temp=temp-v*i;
            temp=temp+t*i;
        }
        n1=n1/10;
        i*=10;
    }
    cout<<temp<<endl;
}
