#include<iostream>
#include<vector>
using namespace std;
int help_rob(vector<int> &nums, int l, int r)
{
    int a=0,b=0;
    for(int i=l; i<r; i++)
    {
        int temp=a;
        a=b;
        b=max(temp+nums[i],b);
    }
    return b;
}
int rob(vector<int>& nums)
{
    int n=nums.size();
    if(n<=3)
        return *max_element(nums.begin(),nums.end());
    return max(help_rob(nums,1,n),help_rob(nums,0,n-1));
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
    cout<<rob(nums)<<endl;
}
