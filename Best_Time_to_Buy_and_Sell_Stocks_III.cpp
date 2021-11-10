#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> prices)
{
    int mp1=0;
    int mini=prices[0];
    int n=prices.size();
    int dp1[n];
    dp1[0]=0;
    for(int i=1; i<n; i++)
    {
        if(prices[i]<mini)
            mini=prices[i];
        mp1=prices[i]-mini;
        if(mp1>dp1[i-1])
        {
            dp1[i]=mp1;
        }
        else
        {
            dp1[i]=dp1[i-1];
        }
    }
    int mp2=0;
    int maxi=prices[n-1];
    int dp2[n];
    dp2[n-1]=0;
    for(int i=n-2; i>=0; i--)
    {
        if(prices[i]>maxi)
        {
            maxi=prices[i];
        }
        mp2=maxi-prices[i];
        if(mp2>dp2[i+1])
        {
            dp2[i]=mp2;
        }
        else
        {
            dp2[i]=dp2[i+1];
        }
    }
    int max_Profit=0;
    for(int i=0; i<n; i++)
    {
        if(dp1[i]+dp2[i]>max_Profit)
            max_Profit=dp1[i]+dp2[i];
    }
    return max_Profit;
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
