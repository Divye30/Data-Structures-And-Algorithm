#include<iostream>
#include<vector>
using namespace std;
int rob_houses(vector<int> nums)
{
    int n=nums.size();
    int dp[n+1];
    dp[1]=nums[0];
    if(n==1)
    {
        return dp[1];
    }
    dp[2]=max(nums[0],nums[1]);
    if(n==2)
    {
        return dp[2];
    }
    for(int i=3; i<=n; i++)
    {
        dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
    }
    return dp[n];
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
    cout<<rob_houses(nums)<<endl;
}
