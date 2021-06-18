#include<iostream>
using namespace std;
#define MOD 1000000007
int main()
{
    int m,n,p;
    cin>>m>>n>>p;
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    while(p--)
    {
        int r,c;
        cin>>r>>c;
        dp[r][c]=-1;
    }
    dp[1][1]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i][j]!=-1)
            {
                if(i==1 and dp[i][j-1]!=-1)
                {
                    dp[i][j]=1;
                }
                else if(i==1 and dp[i][j-1]==-1)
                {
                    dp[i][j]=0;
                }
                else if(j==1 and dp[i-1][j]!=-1)
                {
                    dp[i][j]=1;
                }
                else if(j==1 and dp[i-1][j]==-1)
                {
                    dp[i][j]=0;
                }
                else if(dp[i][j-1]!=-1 and dp[i-1][j]!=-1)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else if(dp[i][j-1]==-1 and dp[i-1][j]!=-1)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    cout<<dp[m][n]%MOD<<endl;
}
