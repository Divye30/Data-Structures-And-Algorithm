#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int findmax(vector<int> &prices, int curr, int n)
{
    if(curr>=n)
        return 0;
    if(dp[curr]!=-1)
        return dp[curr];
    int maxVal=0;
    for(int i=curr+1; i<n; i++)
    {
        if(prices[curr]<prices[i])
            maxVal=max(maxVal,prices[i]-prices[curr]+findmax(prices, i+2, n));
    }
    maxVal=max(maxVal,findmax(prices, curr+1, n));
    dp[curr]=maxVal;
    return maxVal;
}
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    dp.resize(n+1,-1);
    return findmax(prices, 0, n);
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
    cout<<maxProfit(nums)<<endl;
}
