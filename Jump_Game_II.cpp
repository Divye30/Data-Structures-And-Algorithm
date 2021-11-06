#include<iostream>
#include<vector>
using namespace std;
int min_jumps(vector<int> nums)
{
    int jump=0, currEnd=0, currFarthest=0;
    for(int i=0; i<nums.size()-1; i++)
    {
        currFarthest=max(currFarthest,i+nums[i]);
        if(i==currEnd)
        {
            jump++;
            currEnd=currFarthest;
        }
    }
    return jump;
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
    cout<<min_jumps(nums)<<endl;
}
