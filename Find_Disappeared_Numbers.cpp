#include<iostream>
#include<vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> ans;
    for(auto var: nums)
        nums[abs(var)-1]= -abs(nums[abs(var)-1]);
    for(int i= 0; i<size(nums); i++)
        if(nums[i]>0)
            ans.push_back(i+1);
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
    vector<int> res=findDisappearedNumbers(nums);
    for(auto var:res)
        cout<<var<<" ";
    cout<<endl;
}
