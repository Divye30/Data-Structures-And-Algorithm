#include<iostream>
using namespace std;
int dp[1000][1000];
int max_profit(int *size,int *value,int n, int s)
{
    if(n==0 or s==0)
        return 0;
    if(dp[n][s]!=-1)
        return dp[n][s];
    int inc=0,exc=0;
    if(size[n-1]<=s)
        inc=value[n-1]+max_profit(size, value, n-1, s-size[n-1]);
    exc=max_profit(size, value, n-1, s);
    return dp[n][s]=max(inc,exc);
}
int main()
{
    int n,s;
    cin>>n>>s;
    int size[n],value[n];
    for(int i=0; i<n; i++)
        cin>>size[i];
    for(int i=0; i<n; i++)
        cin>>value[i];
    memset(dp,-1,sizeof(dp));
    cout<<max_profit(size,value,n,s)<<endl;
}
