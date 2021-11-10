#include<iostream>
#include<vector>
using namespace std;
int profit(vector<int> nums)
{
    int maxProfit=0;
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]>nums[i-1])
            maxProfit+=nums[i]-nums[i-1];
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
