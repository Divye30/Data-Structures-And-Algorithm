#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    if(nums.size()<3)
        return ans;
    for(int i=0; i<nums.size()-2; i++)
    {
        if(i==0 or (i>0 and nums[i]!=nums[i-1]))
        {
            int lo=i+1;
            int hi=nums.size()-1;
            int sum=-nums[i];
            while(lo<hi)
            {
                if(nums[lo]+nums[hi]==sum)
                {
                    vector<int> temps;
                    temps.push_back(nums[i]);
                    temps.push_back(nums[lo]);
                    temps.push_back(nums[hi]);
                    ans.push_back(temps);
                    while(lo<hi and nums[lo]==nums[lo+1])
                        lo++;
                    while(lo<hi and nums[hi]==nums[hi-1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if(nums[lo]+nums[hi]>sum)
                    hi--;
                else
                    lo++;
            }
        }
    }
    return ans;
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
    vector<vector<int>> ans=threeSum(nums);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}
