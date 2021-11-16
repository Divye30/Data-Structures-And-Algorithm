#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    auto M= obstacleGrid.size();
    auto N= obstacleGrid[0].size();
    if(obstacleGrid[M-1][N-1]==1)
        return 0;
    vector<vector<int>> dp(M, vector<int>(N, 0));
    for(int i=0; i<M; ++i)
    {
        if(i!=0)
        {
            dp[i][0]=obstacleGrid[i][0]!=1?dp[i-1][0]:0;
        }
        else
        {
            dp[i][0]=obstacleGrid[i][0]!=1?1:0;
        }
    }
    for(int i=0; i<N; ++i)
    {
        if(i!=0)
        {
            dp[0][i]=obstacleGrid[0][i]!=1?dp[0][i-1]:0;
        }
        else
        {
            dp[0][i]=obstacleGrid[0][i]!=1?1:0;
        }
    }
    for(int i=1; i<M; ++i)
    {
        for(int j=1; j<N; ++j)
        {
            if(obstacleGrid[i][j]!=1)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else
                dp[i][j]=0;
        }
    }
    return dp[M-1][N-1];
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> obstacleGrid(m,vector<int> (n));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int data;
            cin>>data;
            obstacleGrid[i][j]=data;
        }
    }
    cout<<uniquePathsWithObstacles(obstacleGrid)<<endl;
}
