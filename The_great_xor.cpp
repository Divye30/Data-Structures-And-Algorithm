#include<iostream>
#include<math.h>
using namespace std;
long theGreatXor(long x)
{
    long c=0;
    long t=x;
    while(x>0)
    {
        x=x/2;
        c++;
    }
    return (pow(2,c)-1-t);
}
int main()
{
    long q,x;
    cin>>q;
    while(q>0)
    {
        cin>>x;
        cout<<theGreatXor(x)<<endl;
        q--;
    }
}
