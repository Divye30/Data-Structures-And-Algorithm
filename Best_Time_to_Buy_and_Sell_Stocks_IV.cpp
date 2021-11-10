#include<iostream>
#include<vector>
using namespace std;
int maxProfit(int k, vector<int>& prices)
{
    if(prices.size()==0)
        return 0;
    int n=prices.size();
    int dp[k+1][n+1];
    for(int i=0; i<=k; i++)
        dp[i][0]=0;
    for(int i=0; i<=n; i++)
        dp[0][i]=0;
    for(int i=1; i<=k; i++)
    {
        int maxi=INT_MIN;
        for(int j=1; j<n; j++)
        {
            maxi=max(maxi,dp[i-1][j-1]-prices[j-1]);
            dp[i][j]=max(dp[i][j-1],maxi+prices[j]);
        }
    }
    return dp[k][n-1];
}
int main()
{
    int n,k;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
    cin>>k;
    cout<<maxProfit(k,nums)<<endl;
}
