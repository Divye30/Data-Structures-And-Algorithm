#include<iostream>
using namespace std;
int numberOfways(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    int ans=numberOfways(n-1)+(n-1)*numberOfways(n-2);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<numberOfways(n)<<endl;
}
