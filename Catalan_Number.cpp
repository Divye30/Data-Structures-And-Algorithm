#include<iostream>
using namespace std;
int catalanNumber(int n)
{
    if(n==0)
        return 1;
    int sum=0;
    for(int i=1; i<=n; i++)
       sum+=catalanNumber(i-1)*catalanNumber(n-i);
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<catalanNumber(n)<<endl;
}
