#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target)
{
    int l=0, r=nums.size()-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(nums[m]==target)
            return m;
        if(nums[l]<=nums[m])
        {
            if(nums[l]<=target && target< nums[m])
                r=m-1;
            else
                l=m+1;
        }
        else
        {
            if(nums[m]< target && target<=nums[r])
                l=m+1;
            else
                r=m-1;
        }
    }
    return -1;
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
    int target;
    cin>>target;
    int ans=search(nums,target);
    if(ans==-1)
        cout<<"Element not found"<<endl;
    else
        cout<<"Element found at index:"<<ans<<endl;
}
