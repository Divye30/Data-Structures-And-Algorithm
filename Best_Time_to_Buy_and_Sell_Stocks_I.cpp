#include<iostream>
#include<vector>
using namespace std;
int profit(vector<int> nums)
{
    int mini=INT_MAX;
    int maxProfit=0;
    for(int i=0; i<nums.size(); i++)
    {
        mini=min(mini,nums[i]);
        maxProfit=max(maxProfit,nums[i]-mini);
    }
    return maxProfit;
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
    cout<<profit(nums)<<endl;
}
