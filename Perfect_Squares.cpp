#include<iostream>
#include<vector>
using namespace std;
int numSquares(int n)
{
    vector<int> dp(n+1,0);
    dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        int min=INT_MAX;
        for(int j=1; j*j<=i; j++)
        {
            int var=i-j*j;
            if(dp[var]<min)
                min=dp[var];
        }
        dp[i]=min+1;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
}
