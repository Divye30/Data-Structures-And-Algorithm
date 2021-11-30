#include<iostream>
#include<vector>
using namespace std;
void sortColors(vector<int>& nums)
{
    int i=0,j=0,k=nums.size()-1;
    while(j<=k)
    {
        if(nums[j]==0)
        {
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
        else if(nums[j]==1)
        {
            j++;
        }
        else
        {
            swap(nums[j],nums[k]);
            k--;
        }
    }
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
    sortColors(nums);
    for(auto ele:nums)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}
