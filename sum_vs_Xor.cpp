#include<iostream>
#include<math.h>
using namespace std;
long sumXor(long n)
{
    long count= 0;
    while(n)
    {
      count+= n%2?0:1;
      n/=2;
    }
    count=pow(2,count);
    return count;
}
int main()
{
    long n;
    cin>>n;
    cout<<sumXor(n)<<endl;
}
