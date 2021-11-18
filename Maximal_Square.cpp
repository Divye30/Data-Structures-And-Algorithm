#include<iostream>
#include<vector>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int>> dp(r,vector<int>(c,0));
    int ans=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            dp[i][j]= (matrix[i][j]-48);
            if(dp[i][j])
                ans = 1;
        }
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
            if(dp[i][j])
            {
                dp[i][j]= 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                ans= max(ans,dp[i][j]);
            }
    }
    return ans*ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> matrix(n,vector<char>(m,'0'));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char c;
            cin>>c;
            matrix[i][j]=c;
        }
    }
    cout<<maximalSquare(matrix)<<endl;
}
