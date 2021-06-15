#include<iostream>
using namespace std;
typedef long long int lli;
lli number_Of_Strings(lli n)
{
    lli dp[2][n+1];
    dp[0][0]=0;
    dp[1][0]=0;
    dp[0][1]=dp[1][1]=1;
    for(lli i=2; i<=n; i++)
    {
        dp[0][i]=dp[0][i-1]+dp[1][i-1];
        dp[1][i]=dp[0][i-1];
    }
    return dp[0][n]+dp[1][n];
}
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        cout<<number_Of_Strings(n)<<endl;
    }
}
